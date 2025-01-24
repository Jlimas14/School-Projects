var express = require('express');
var router = express.Router();

const Student = require("../models/student");

router.get("/", async function (req, res) {
  let studentList = await Student.find().sort("name").exec();
  res.render("studentList.ejs", { studentList });
});

router.get("/byname/:name", async function (req, res) {
  let namePatternToMatch = new RegExp(req.params.name, "i");
  let studentList = await Student.find()
    .where("name")
    .regex(namePatternToMatch)
    .sort("name")
    .exec();
  res.render("studentList.ejs", { studentList });
});

router.get("/id/:id", async function (req, res) {
  let student = await Student.findById(req.params.id)
    .populate("classRoom") //get data of class
    .exec();
  //pass the student itself to the view
  res.render("singleStudent.ejs", student);
});

router.get("/delete/:id", async function (req, res) {
  await Student.findByIdAndDelete(req.params.id).exec();
  //Send the user back to students page
  res.redirect("/students/");
});

module.exports = router;
