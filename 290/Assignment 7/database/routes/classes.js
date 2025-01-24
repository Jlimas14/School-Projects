var express = require("express");
var router = express.Router();

const ClassRoom = require("../models/classRoom");

router.get("/", async function (req, res) {
  let classRoomList = await ClassRoom.find().sort("name").exec();
  res.render("classRoomList.ejs", { classRoomList: classRoomList });
});

router.get("/id/:id", async function (req, res) {
  let classRoom = await ClassRoom.findById(req.params.id).exec();
  let students = await classRoom.students;

  console.log("routerget array:", students);
  
  //pass the classroom and students list to the view
  res.render("singleClassRoom.ejs", { classRoom: classRoom, students: students });
});

router.get("/delete/:id", async function (req, res) {
  const Student = require("../models/student");
  let classOfStudents = await Student.find().where("classRoom").eq(req.params.id).exec();
  for (let s of classOfStudents) {
    s.classRoom = undefined; //tell mongoose to remove team field
    s.save(); //no need to wait for result, just do it
  }

  //Now delete the class
  let classroom = await ClassRoom.findByIdAndRemove(req.params.id).exec();

  //Send the user back to the classes page
  res.redirect("/classes/");
});

module.exports = router;
