var express = require("express");
var router = express.Router();

const routeHelper = require("./routeHelpers");
const ClassRoom = require("../models/classRoom");

router.get("/", async function (req, res) {
  let classRoomList = await ClassRoom.find().sort("name").exec();
  res.render("classRoomList.ejs", { classRoomList: classRoomList });
});

router.get("/id/:id", async function (req, res) {
  let classRoom = await ClassRoom.findById(req.params.id).exec();
  let students = await classRoom.students;
  //pass the classroom and students list to the view
  res.render("singleClassRoom.ejs", { classRoom: classRoom, students: students });
});

router.get("/delete/:id", async function (req, res) {
  const Student = require("../models/student");
  let classOfStudents = await Student.find().where("classRoom").eq(req.params.id).exec();
  for (let s of classOfStudents) {
    s.classRoom = undefined; 
    s.save();
  }
  //Now delete the class
  let classroom = await ClassRoom.findByIdAndRemove(req.params.id).exec();
  //Send the user back to the classes page
  res.redirect("/classes/");
});

router.get("/create", function (req, res) {
  let classRoom = new ClassRoom({});
  res.render("classRoomForm.ejs", { title: "Create Class", classRoom: classRoom });
});

router.get("/update/:id", async function (req, res, next) {
  try {
    let classRoom = await ClassRoom.findById(req.params.id).exec();
    res.render("classRoomForm.ejs", { title: "Update Class", classRoom: classRoom });
  } catch (err) {
    var err = new Error("Class not found");
    err.status = 404;
    return next(err);
  }
});

router.post("/update/:id", async function (req, res, next) {
  let classRoom = await ClassRoom.findById(req.params.id).exec();
  if (classRoom === null)
  classRoom = new ClassRoom({
      _id: req.body.id,
    });

  console.log(req.body);

  let availableList = req.body.availability.split("\n");
  for (let i = 0; i < availableList.length; i++) {
    availableList[i] = availableList[i].trim(); //get rid of extra whitespace at begin/end of each
    if (availableList[i] === "") {
      availableList.splice(i, 1);
      i--;
    }
  }

  let daysList = req.body.days.split("\n");
  for (let i = 0; i < daysList.length; i++) {
    daysList[i] = daysList[i].trim();
    if (daysList[i] === "") {
      daysList.splice(i, 1);
      i--;
    }
  }

  //Replace existing data
  classRoom.className = req.body.className;
  classRoom.homeTown = req.body.homeTown;
  classRoom.Location = req.body.Location;
  classRoom.full = req.body.full;
  classRoom.crn = req.body.crn;
  classRoom.availability = availableList;
  classRoom.days = daysList;

  console.log(classRoom);

  //Try to save it
  classRoom
    .save()
    .then((classRoom) => {
      res.redirect(classRoom.url);
    })
    .catch((err) => {
      res.render("classRoomForm.ejs", {
        title: "Update Class",
        classRoom: classRoom,
        errors: routeHelper.errorParser(err.message),
      });
    });
});

module.exports = router;
