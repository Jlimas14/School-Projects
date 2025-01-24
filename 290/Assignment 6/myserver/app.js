var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

// app.use('/', indexRouter);
// app.use('/users', usersRouter);

//My routes
//--------------------------
app.get("/", async (req, res) => {
  res.send("index.html");
});

app.get("/pokemons/", async (req, res) => {
  const pokemonList = await getPokemonList();
  console.log(pokemonList);
  res.render("pokemon.ejs", pokemonList);
});

app.get("/pokemon/:name", async (req, res, next) => {
  const pokemonList = await getPokemonList();
  const pokemonName = req.params.name;
  let index = -1;
  pokemonList.results.forEach((value, i) => {
    if (value.name === pokemonName) {
      index = i;
    }
  });
  if (index != -1){
  console.log(pokemonList.results[index].url);
  const pokemon = await getPokemonInfo(pokemonList.results[index].url);
  res.render("onePokemon.ejs", pokemon);
  }
  else next();
});
//--------------------------

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

//--------------------------------------------------------
//My data source - gets the pokemon data

//Need to have node-fetch installed!
let fetch = require("node-fetch");

async function getPokemonList() {
  let responsePromise = await fetch(
    "https://pokeapi.co/api/v2/pokemon/?offset=0&limit=50"
  );
  let json = await responsePromise.json();
  return json;
}

async function getPokemonInfo(url) {
  let responsePromise = await fetch(
    url
  );
  let json = await responsePromise.json();
  return json;
}
