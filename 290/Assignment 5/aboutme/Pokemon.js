//Add an event handler to the button
const searchBtn = document.querySelector("#searchBtn");
searchBtn.addEventListener("click", loadPokemon);

function loadPokemon() {
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

  var url = "https://pokeapi.co/api/v2/pokemon/?offset=" + (pokemonName.value - 1) + "&limit=1";
  // if(pokemonName.value == "all" || pokemonName.value == "All"){
  //   pokemonName.value = 1117;
  //   url = "https://pokeapi.co/api/v2/pokemon/?offset=0&limit=1117"
  // }
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
        let pokemonElement = createPokemonHead(pokeObj);
        pokemonList.appendChild(pokemonElement);
      }

    })
    .catch((error) => {
      console.error("Error:", error);
    });

  if(pokemonName.value > 898){
    pokemonName.value = Number(pokemonName.value) + Number(9102);
  }
  fetch("https://pokeapi.co/api/v2/pokemon/" + pokemonName.value)
  .then((response) => {
    if (!response.ok) console.error("Issue with request:", response);
    return response.json();
  })
  .then((data) => {
    console.log(data)
      let cardBody = createElementWithClass("div", "card-body");
      let cardBodyString = "";
       if ("name" in data) {
        cardBodyString += "<h3>Id Number:</h3>";
        cardBodyString += `<p>${data.id}</p>`;
         }
        if ("abilities" in data) {
          cardBodyString += "<h3>Abilities:</h3>";
          cardBodyString += "<ul>";
          for (let h of data.abilities) {
            cardBodyString += `<li>${h.ability.name}</li>`;
          }
          cardBodyString += "</ul>";
        }
        if ("weight" in data) {
          cardBodyString += "<h3>Weight and Height:</h3>";
          cardBodyString += `<p>${data.weight} lbs and `;
          cardBodyString += `${data.height} feet</p>`;          
        }
      cardBody.innerHTML = cardBodyString;
    
      pokemonList.appendChild(cardBody);

  })
  .catch((error) => {
    console.error("Error:", error);
  });
}

function createPokemonHead(pokeObj) {
  let container = createElementWithClass("div", "");

  let card = createElementWithClass("div", "card h-100");
  container.appendChild(card);

  const cardHead = createElementWithClass("div", "card-header");
  cardHead.style.backgroundColor = getPokemonColor(pokeObj.name);

  if (getPokemonColor(pokeObj.name) > 10) cardHead.style.color = "#f0f0e8";

  cardHead.innerHTML = `<h2 class="card-title">${pokeObj.name}</h2>`;
  card.appendChild(cardHead);

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
  if(stringValue >= 19){
    stringValue = 19;
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
  ];
  return pokemonColors[Math.min(Math.floor(stringValue), 19) - 1];
}