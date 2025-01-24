var express = require('express');
var router = express.Router();

var studentFunctions = require("../controllers/studentFunctions.js");

router.get("/", studentFunctions.studentList);

router.get("/byname/:name", studentFunctions.studentListByName);

router.get("/id/:id", studentFunctions.studentById);

router.get("/delete/:id", studentFunctions.delete);

router.get("/create", studentFunctions.create);

router.get("/update/:id", studentFunctions.update_get);

router.post("/update/:id", studentFunctions.update_post);

module.exports = router;