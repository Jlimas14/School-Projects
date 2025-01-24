var express = require("express");
var router = express.Router();

var counter = 0;
router.get("/", async function (req, res) {
    //Print out the cookies attached to the request
    console.log("Session info is: ", req.session);
    let todoList = [];
    if (req.session.todoList) todoList = req.session.todoList;

    console.log("Cookies: ", req.cookies);
      res.cookie('counter', counter++);

    res.cookie("userID", "3821738237482", { maxAge: 60000, httpOnly: true });
    console.log(req.cookies["counter"])
    res.render("counterPage.ejs", {
      todos: todoList,
      counter: req.cookies["counter"],
    });
});

router.post("/", function (req, res, next) {
  let newItem = req.body.todo;

  if (!req.session.todoList) {
    req.session.todoList = [];
  }
  console.log("Cookies: ", req.cookies);
  res.cookie('counter', counter++);

  req.session.todoList.push(newItem);
  console.log("Session info is: ", req.session);
  res.render("counterPage.ejs", { 
    todos: req.session.todoList, 
    counter: req.cookies["counter"],});
});

module.exports = router;
