//Data that will load into MongoDB
const classRoomList = [
  {
    availability: ["Fall", "Winter", "Spring", "Summer"],
    className: "Intro to effective study",
    Location: "Yamhill campus",
    crn: 422679,
    full: false,
    days: ["Tuesday", "Thursday"],
  },
  {
    availability: ["Spring", "Summer"],
    className: "Swimming",
    Location: "Woodburn campus",
    crn: 133758,
    full: true,
    days: ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday"],
  },
  {
    availability: ["Fall", "Winter"],
    className: "Basic health class",
    Location: "Salem campus",
    crn: 120802,
    full: false,
    days: ["Monday", "Wednesday"],
  },
];

const studentsList = [
  {
    name: "Jacob Limas",
    studentId: 674503,
    grades: ["A", "A", "B", "C" ],
    major: "Computer Science",
    favoriteClass: "CS290",
    age: 22,
  },
  {
    name: "Jim Jape",
    studentId: 998620,
    grades: ["A", "A", "A", "A", "A" ],
    major: "Doctor",
    favoriteClass: "HE252",
    age: 32,
  },
  {
    name: "Brenda George",
    studentId: 156489,
    grades: ["B", "A", "B", "B" ],
    major: "Dental assistant",
    favoriteClass: "MTH60",
    age: 18,
  },
  {
    name: "Alex Vasquez",
    studentId: 969221,
    grades: ["F", "C" ],
    major: "Sports coach",
    favoriteClass: "HPE292",
    age: 25,
  },
  {
    name: "Cody Cross",
    studentId: 600852,
    grades: ["B", "B", "C" ],
    major: "Architect",
    favoriteClass: "MTH112",
    age: 44,
  },
];

//--------------------------------------------
//Connect to DB with Mongoose
const credentials = require("../database/dbCredentials.js");
const mongoose = require("mongoose");
mongoose.connect(credentials.connection_string, {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

//Load our models
const Student = require("./models/student.js");
const classRoom = require("./models/classRoom.js");

//Async function so we can use await to synchronize steps
async function loadAllRecords() {
  //Delete all existing records
  await classRoom.deleteMany();
  await Student.deleteMany();

  const classRoomRecords = [];

  for (let classRoomItem of classRoomList) {
    const classRoomRecord = new classRoom(classRoomItem);
    classRoomRecords.push(classRoomRecord);
    await classRoomRecord.save();
  }

  console.log("Done loading classes");

  for (let i = 0; i < studentsList.length; i++) {
    const studentRecord = new Student(studentsList[i]);
    //Assign two to each classroom
    if (i < 2) {
      studentRecord.classRoom = classRoomRecords[0];
    } else if (i < 4){
      studentRecord.classRoom = classRoomRecords[1];
    }else {
      studentRecord.classRoom = classRoomRecords[2];
    }
    //Save it to mongodb
    await studentRecord.save();
  }
  console.log("Done loading students");
  console.log("Done loading all the data");
  //Done with connection, close so program can exit
  mongoose.connection.close();
}





//Make it happen
loadAllRecords();
