//Add an event handler to the button
const searchBtn = document.querySelector("#searchBtn");
searchBtn.addEventListener("click", loadYeasts);
// searchBtn.onclick = function () {
//   console.log("Clicked");
//   let input = document.querySelector("#inputField1")
//   let success = findMatches(input.value);

// }


function loadYeasts() {
  const pokemonName = document.querySelector("#pokeNum");
  const pokemonList = document.querySelector("#pokemon");

  //Clearing existing pokemon
  pokemonList.replaceChildren([]);
  let a = 0;
  let x = 0;
  switch (a) {
    case 1:
      x = 10;
  }

  var url = "https://pokeapi.co/api/v2/pokemon/?offset=" + pokemonName.value + "&limit=1";
  if(pokemonName.value == "all" || pokemonName.value == "All"){
    pokemonName.value = 1117;
    url = "https://pokeapi.co/api/v2/pokemon/?offset=0&limit=1117"
  }
  fetch(url)
    .then((response) => {
      if (!response.ok) console.error("Issue with request:", response);
      console.log(response);
      return response.json();
    })
    .then((data) => {
      console.log(data);

      for (const pokeObj of data.results) {
        console.log(pokeObj);
        console.log("creating card now...");
        let pokemonElement = createPokemonCard(pokeObj);
        pokemonList.appendChild(pokemonElement);


        console.log(pokeObj.url);
        console.log(data.url.id);
        return fetch(data.url)
      }

      fetch(url)
      .then(function(response) { 
        return response.json()
      })
      .then(function(data) {   
        // do stuff with `data`, call second `fetch`
        return fetch(data.url)
      })
      .then(function(response) { 
        return response.json(); 
      })
      .then(function(data) {
        // do stuff with `data`
      })
      .catch(function(error) { 
        console.log('Requestfailed', error) 
      });



//fetch https://pokeapi.co/api/v2/pokemon/ + pokemonName.value
//if in all, then make a for loop to 898 jump to 10001 and finish at 10220
//I am adding abilities, height, id, 



    })
    .catch((error) => {
      console.error("Error:", error);
    });
}

//Given an object for a pokemon number, produce a formatted HTML
// representation
//Returns div to be added into layour
function createPokemonCard(pokeObj) {
  console.log("being made...");
  let container = createElementWithClass("div", "");

  let card = createElementWithClass("div", "card h-100");
  container.appendChild(card);

  const cardHead = createElementWithClass("div", "card-header");
  cardHead.style.backgroundColor = getPokemonColor(pokeObj.name);

  //Dark backgrounds need light text...
  if (getPokemonColor(pokeObj.name) > 10) cardHead.style.color = "#f0f0e8";

  cardHead.innerHTML = `<h2 class="card-title">${pokeObj.name}</h2>`;
  card.appendChild(cardHead);

  let cardBody = createElementWithClass("div", "card-body");
  //Build up all the HTML inside card as a string

  // let cardBodyString = "";
  // cardBodyString += `<p><em class="card-text">${pokeObj.url}</em></p>`;
  // if ("ingredients" in pokeObj) {
  //   if ("malt" in pokeObj.ingredients) {
  //     cardBodyString += "<h3>Malts:</h3>";
  //     cardBodyString += "<ul>";
  //     for (let m of pokeObj.ingredients.malt) {
  //       cardBodyString += `<li>${m.name}</li>`;
  //     }
  //     cardBodyString += "</ul>";
  //   }
  //   console.log(cardBody.innerHTML);
  //   if ("hops" in pokeObj.ingredients) {
  //     cardBodyString += "<h3>Hops:</h3>";
  //     cardBodyString += "<ul>";
  //     for (let h of pokeObj.ingredients.malt) {
  //       cardBodyString += `<li>${h.name}</li>`;
  //     }
  //     cardBodyString += "</ul>";
  //   }
  //   if ("yeast" in pokeObj.ingredients) {
  //     cardBodyString += "<h3>Yeast:</h3>";
  //     cardBodyString += `<p>${pokeObj.ingredients.yeast}</p`;
  //   }
  // }
  // cardBody.innerHTML = cardBodyString;

  card.appendChild(cardBody);

  return container;
}

//Make an element and set one or more classes
function createElementWithClass(type, classes) {
  let el = document.createElement(type);
  el.className = classes;
  return el;
}

//Creates the color based on name length rather than srm
function getPokemonColor(pokemonString) {

  var stringValue = pokemonString.length;
  if(stringValue >= 30){
    stringValue = 30;
  }
  const pokemonColors = [
    "#FFE699",
    "#FFD878",
    "#FFCA5A",
    "#FFBF42",
    "#FBB123",
    "#F8A600",
    "#F39C00",
    "#EA8F00",
    "#E58500",
    "#DE7C00",
    "#D77200",
    "#CF6900",
    "#CB6200",
    "#C35900",
    "#945534",
    "#925536",
    "#844C33",
    "#744229",
    "#683A22",
    "#573512",
    "#492A0B",
    "#3A2102",
    "#361F1B",
    "#261716",
    "#231716",
    "#19100F",
    "#16100F",
    "#120D0C",
    "#100B0A",
    "#050B0A",
  ];

  return pokemonColors[Math.min(Math.floor(stringValue), 30) - 1];
}
