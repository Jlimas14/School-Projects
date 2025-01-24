var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var app = express();

var session = require("express-session");

app.use(
  session({
    secret: "j243.4xchff982yf807NAYsDF97n6t935r3", //This should not be in code!
    cookie: {
      httpOnly: true, //Don't want JS to see session cookie
      maxAge: 1000 * 60 * 60 * 24 * 7, //expire after 7 days
    },
    resave: false, //Don't constantly update session if no changes
    saveUninitialized: false, //Don't start session until we write to it
    ////Uncomment to save in DB
    //store: sessionStore,
  })
);
  app.use(logger('dev'));
  app.use(express.json());
  app.use(express.urlencoded({ extended: false }));
  app.use(cookieParser());

app.set("view engine", "ejs");
//my pages
var counterRouter = require("./routes/counter");
app.use("/", counterRouter);




app.use(express.static(path.join(__dirname, 'public')));


// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
