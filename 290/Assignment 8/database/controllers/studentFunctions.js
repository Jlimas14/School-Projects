const routeHelper = require("../routes/routeHelpers.js");

const Student = require("../models/student");
const ClassRoom = require("../models/classRoom");

exports.studentList = async function (req, res, next) {
  try {
    let studentList = await Student.find().sort("name").exec();
    res.render("studentList.ejs", { studentList });
  } catch (err) {
    next(err);
  }
};

exports.studentListByName = async function (req, res, next) {
  try {
    let namePatternToMatch = new RegExp(req.params.name, "i");
    let studentList = await Student.find()
      .where("name")
      .regex(namePatternToMatch)
      .sort("name")
      .exec();

    res.render("studentList.ejs", { studentList });
  } catch (err) {
    next(err);
  }
};

exports.studentById = async function (req, res, next) {
  try {
    let student = await Student.findById(req.params.id)
      .populate("classRoom") //get data of class
      .exec();
  //pass the student itself to the view
  res.render("singleStudent.ejs", student);
  } catch (err) {
    next(err);
  }
};

exports.delete = async function (req, res, next) {
  try {
    await Student.findByIdAndDelete(req.params.id).exec();
    res.redirect("/students/");
  } catch (err) {
    next(err);
  }
};

exports.create = async function (req, res, next) {
  try {
    let student = new Student({});
    let classes = await ClassRoom.find().select("className").exec();
    res.render("studentForm.ejs", {
      title: "Create Student",
      student: student,
      classes: classes,
    });
  } catch (err) {
    next(err);
  }
};

exports.update_get = async function (req, res, next) {
  try {
    let student = await Student.findById(req.params.id).exec();
    let classes = await ClassRoom.find().select("className").exec();
    res.render("studentForm.ejs", {
      title: `Update ${student.name}`,
      student: student,
      classes: classes,
    });
  } catch (err) {
    next(err);
  }
};

exports.update_post = [
  async function (req, res, next) {       
    try {
      let student = await Student.findById(req.params.id).exec();
      console.log(student);

      if (student === null)
      student = new Student({
          _id: req.body.id,
        });
      console.log(req.body);
      //Process Grades - split string into an array
      let gradesList = req.body.grades.split("\n");
      for (let i = 0; i < gradesList.length; i++) {
        gradesList[i] = gradesList[i].trim(); 
        if (gradesList[i] === "") {
          gradesList.splice(i, 1);
          i--;
        }
      }
      //Replace existing data
      student.name = req.body.name;
      student.studentId = req.body.studentId;
      student.major = req.body.major;
      student.favoriteClass = req.body.favoriteClass;
      student.age = req.body.age;
      student.classRoom = req.body.classRoom !== "" ? req.body.classRoom : undefined;
      student.grades = gradesList;

      let classes = await ClassRoom.find().select("className").exec();

      //Try to save it
      student
        .save()
        .then((student) => {
          res.redirect(student.url);
        })
        .catch((err) => {
          console.log(err.message);
          res.render("studentForm.ejs", {
            title: `Update ${student.name}`,
            student: student,
            classes: classes,
            errors: routeHelper.errorParser(err.message),
          });
        });
    } catch (err) {
      next(err);
    }
  },
];
