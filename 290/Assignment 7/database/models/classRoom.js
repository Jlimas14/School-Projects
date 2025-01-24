const mongoose = require("mongoose");
const Schema = mongoose.Schema;

var ClassSchema = new Schema({
  availability: [{ type: String, required: true }],
  className: { type: String, required: true },
  Location: { type: String, required: true },
  crn: { type: Number, required: true },
  full: { type: Boolean, required: true },
  days: [{ type: String, required: true }],
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
