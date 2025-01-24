const mongoose = require("mongoose");
const Schema = mongoose.Schema;

var StudentSchema = new Schema({
  name: { type: String, required: true },
  studentId: { type: Number, required: true },
  grades: [{ type: String }],
  major: { type: String },
  favoriteClass: { type: String },
  age: { type: Number, required: true },
  classRoom: { type: Schema.Types.ObjectId, ref: "ClassRoom" },
});

StudentSchema.virtual("url").get(function () {
  return "/students/id/" + this._id;
});

//Export model
module.exports = mongoose.model("Student", StudentSchema);
