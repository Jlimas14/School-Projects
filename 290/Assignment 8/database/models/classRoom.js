const mongoose = require("mongoose");
const Schema = mongoose.Schema;

var ClassSchema = new Schema({
  availability: {
    type: [{ type: String }], 
    validate: [
      function (value) {
        return value.length > 0;
      },
      "There needs to be at least one term per year",
    ],
 },
  className: { type: String, required: [true, "Class needs a name"] },
  Location: { type: String, required: [true, "Class needs a location" ] },
  crn: { type: Number, required: [true, "Class needs a unique ID"], max: [999999, "Can't be more than 6 digits"], },
  full: { type: Boolean, default: false },
  days: {
    type: [{ type: String }],
    validate: [
      function (value) {
        return value.length >= 1;
      },
      "You need at least one day to have class",     
    ],
 },
});

ClassSchema.virtual("url").get(function () {
  return "/classes/id/" + this._id;
});

//look up students
ClassSchema.virtual("students").get(async function () {
  const Student = require("./student");
  let studentArray = await Student.find().where("classRoom").equals(this._id).exec();

  console.log("class id:", this._id); 
  console.log("virtual array:", studentArray);

  return studentArray;
});

//Export model
module.exports = mongoose.model("ClassRoom", ClassSchema);
