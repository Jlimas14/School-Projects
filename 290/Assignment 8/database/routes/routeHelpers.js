//Takes a string like:
//classRoom validation failed: squadName: You must provide a class Name, Location: You must provide a Location
//and extracts the list of error messages into an array like:
//["You must provide a class Name","You must provide a Location"]
function errorParser(errorString) {
    errorString = errorString.slice(errorString.indexOf(":") + 1);
    let errorArray = errorString.split(",");
    for (let i = 0; i < errorArray.length; i++) {
      let e = errorArray[i];
      errorArray[i] = e.slice(e.indexOf(":") + 1).trim();
    }
    return errorArray;
  }
  
  module.exports = { errorParser };
  