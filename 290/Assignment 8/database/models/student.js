const mongoose = require("mongoose");
const Schema = mongoose.Schema;

var StudentSchema = new Schema({
  name: {
    type: String,
    required: [true, "A name is required"],
    validate: [
      function (value) {
        let matchLocation = value.search(/\w/);
        return matchLocation !== -1;
      },
      "There must be at least one character",
    ],
  },
  studentId: { type: Number, required: [true, "Student needs a unique ID"], max: [999999, "Can't be more than 6 digits"], },
  grades: [{ type: String }],
  major: { type: String },
  favoriteClass: { type: String },
  age: {
    type: Number,
    required: [true, "You need age"],
    min: [0, "Minimum age of 0"],
  },
  classRoom: { type: Schema.Types.ObjectId, ref: "ClassRoom" },
});

StudentSchema.virtual("url").get(function () {
  return "/students/id/" + this._id;
});

//Export model
module.exports = mongoose.model("Student", StudentSchema);
