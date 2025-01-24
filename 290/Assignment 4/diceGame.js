function roll() {
    console.log("Rolling");
    let message = "Rolling!";
    displayScoring(message);

    for(let x = 1; x < 6; x++){
        let dieNum = Math.floor(Math.random() * 6) + 1;
        if(isLocked(x) == false){
            setDie(x, dieNum);
        }
    }

}

function score() {
    console.log("Scoring");

    total = addValues();
    let message = "Ones:" + Ones() + "\nTwos:" + Twos() + "\nThrees:" + 
                    Threes() + "\nFours:" + Fours() + "\nFives:" + Fives() + "\nSixes:" + Sixes() + 
                    "\nThreeKind:" + ThreeKind() + "\nFourKind:" + FourKind() + "\nFullHouse:" + 
                    FullHouse() + "\nSmallStraight:" + SmallStraight() + "\nLargeStraight:" + 
                    LargeStraight() + "\nYahtzee:" + Yahtzee() + "\nChance:" + Chance();
    

    displayScoring(message);

}

function addValues() {
    let total = 0;
    for(let x = 1; x < 6; x++){
        let dieNum = getDieValue(x);
        total += parseInt(dieNum);
    }
    return total;
}

function restart() {
    for(let x = 1; x < 5; x++){
        let dieNum = Math.floor(Math.random() * 6) + 1;
        if(isLocked(x) == false){
            setDie(x, dieNum);
        }
    }
}

function Ones() {
    //    Receive 1 point for each 1 rolled
    let total = 0;
    for(let x = 1; x < 6; x++){
        let dieNum = getDieValue(x);
        if(dieNum == 1){
            total += parseInt(dieNum);
        }
    }
    return total;
}

function Twos() {
    //    Receive 2 points for each 2 rolled
    let total = 0;
    for(let x = 1; x < 6; x++){
        let dieNum = getDieValue(x);
        if(dieNum == 2){
            total += parseInt(dieNum);
        }
    }
    return total;
}

function Threes() {
    //    Receive 3 points for each 3 rolled
    let total = 0;
    for(let x = 1; x < 6; x++){
        let dieNum = getDieValue(x);
        if(dieNum == 3){
            total += parseInt(dieNum);
        }
    }
    return total;
}

function Fours() {
    //   Receive 4 points for each 4 rolled
    let total = 0;
    for(let x = 1; x < 6; x++){
        let dieNum = getDieValue(x);
        if(dieNum == 4){
            total += parseInt(dieNum);
        }
    }
    return total;
}

function Fives() {
    //  Receive 5 points for each 5 rolled
    let total = 0;
    for(let x = 1; x < 6; x++){
        let dieNum = getDieValue(x);
        if(dieNum == 5){
            total += parseInt(dieNum);
        }
    }
    return total;
}

function Sixes() {
    //   Receive 6 points for each 6 rolled
    let total = 0;
    for(let x = 1; x < 6; x++){
        let dieNum = getDieValue(x);
        if(dieNum == 6){
            total += parseInt(dieNum);
        }
    }
    return total;
}

function ThreeKind() {
    //  Three dice of the same number
    let a = 0;
    let b = 0;
    let c = 0;
    let d = 0;
    let e = 0;
    let f = 0;
    for(let x = 1; x < 6; x++){
        if(getDieValue(x) == 1){a++};
        if(getDieValue(x) == 2){b++};
        if(getDieValue(x) == 3){c++};
        if(getDieValue(x) == 4){d++};
        if(getDieValue(x) == 5){e++};
        if(getDieValue(x) == 6){f++};
    }
    if(a == 3 || b == 3 || c == 3 || d == 3 || e == 3 || f == 3){
        return addValues();
    }
}

function FourKind() {
    //   Four dice of the same number
    let a = 0;
    let b = 0;
    let c = 0;
    let d = 0;
    let e = 0;
    let f = 0;
    for(let x = 1; x < 6; x++){
        if(getDieValue(x) == 1){a++};
        if(getDieValue(x) == 2){b++};
        if(getDieValue(x) == 3){c++};
        if(getDieValue(x) == 4){d++};
        if(getDieValue(x) == 5){e++};
        if(getDieValue(x) == 6){f++};
    }
    if(a == 4 || b == 4 || c == 4 || d == 4 || e == 4 || f == 4){
        return addValues();
    }
}

function FullHouse() {
    // Three dice showing the same number, and two dice showing another number.
    let a = 0;
    let b = 0;
    let c = 0;
    let d = 0;
    let e = 0;
    let f = 0;
    for(let x = 1; x < 6; x++){
        if(getDieValue(x) == 1){a++};
        if(getDieValue(x) == 2){b++};
        if(getDieValue(x) == 3){c++};
        if(getDieValue(x) == 4){d++};
        if(getDieValue(x) == 5){e++};
        if(getDieValue(x) == 6){f++};
    }
    if((a == 3 || b == 3 || c == 3 || d == 3 || e == 3 || f == 3) && (a == 2 || b == 2 || c == 2 || d == 2 || e == 2 || f == 2)){
        return addValues();
    }
}

function SmallStraight() {
    //  Any four consecutive numbers (for example, 3-4-5-6)
    let totalWord = [];
    for(let x = 1; x < 6; x++){
        let dieNum = getDieValue(x);
        totalWord.push(dieNum);
    }
    totalWord.sort();
    var first = "1";
    var second = "2";
    var third = "3";
    var fourth = "4";
    var fifth = "5";
    var sixth = "6";
    console.log(totalWord);
    var matchOne = totalWord.indexOf(first);
    var matchTwo = totalWord.indexOf(second);
    var matchThree = totalWord.indexOf(third);
    var matchFour = totalWord.indexOf(fourth);
    var matchFive = totalWord.indexOf(fifth);
    var matchSix = totalWord.indexOf(sixth);
    if((matchOne != -1 && matchTwo != -1 && matchThree != -1 && matchFour != -1) || 
    (matchTwo != -1 && matchThree != -1 && matchFour != -1 && matchFive != -1) ||
    (matchThree != -1 && matchFour != -1 && matchFive != -1 && matchSix != -1)){
        return 30;
    }
}

function LargeStraight() {
    //  Any five consecutive numbers (for example, 1-2-3-4-5)
    let totalWord = [];
    for(let x = 1; x < 6; x++){
        let dieNum = getDieValue(x);
        totalWord.push(dieNum);
    }
    totalWord.sort();
    var first = "1";
    var second = "2";
    var third = "3";
    var fourth = "4";
    var fifth = "5";
    var sixth = "6";
    console.log(totalWord);
    var matchOne = totalWord.indexOf(first);
    var matchTwo = totalWord.indexOf(second);
    var matchThree = totalWord.indexOf(third);
    var matchFour = totalWord.indexOf(fourth);
    var matchFive = totalWord.indexOf(fifth);
    var matchSix = totalWord.indexOf(sixth);
    if((matchOne != -1 && matchTwo != -1 && matchThree != -1 && matchFour != -1 && matchFive != -1) || 
    (matchTwo != -1 && matchThree != -1 && matchFour != -1 && matchFive != -1 && matchSix != -1)){
        return 40;
    }
}

function Yahtzee() {
    //  All 5 dice showing the same number
    let a = 0;
    let b = 0;
    let c = 0;
    let d = 0;
    let e = 0;
    let f = 0;
    for(let x = 1; x < 6; x++){
        if(getDieValue(x) == 1){a++};
        if(getDieValue(x) == 2){b++};
        if(getDieValue(x) == 3){c++};
        if(getDieValue(x) == 4){d++};
        if(getDieValue(x) == 5){e++};
        if(getDieValue(x) == 6){f++};
    }


    if(a == 5 || b == 5 || c == 5 || d == 5 || e == 5 || f == 5){
        return 50;
    }
}

function Chance() {
    return addValues();
}

//------------------------------------------------
//YOUR CODE ABOVE
//You may call the functions listed below but should not modify them

//returns the value showing on the given die (1-5)
function getDieValue(dieNumber) {
    let die = document.getElementById('die' + dieNumber);
    return die.textContent;
}

//Changes the given die number (1-5) to the given value (1-6)
function setDie(dieNumber, value) {
    let die = document.getElementById('die' + dieNumber);
    let regex = /\d+/;
    die.className = die.className.replace(regex, value);
    die.innerText = value;
}

//returns true if the given die number (1-5) is in the locked state, false if not
function isLocked(dieNumber) {
    let die = document.getElementById('die' + dieNumber);
    return die.className.indexOf("-fill") != -1;
}

//displays the message in the scoring information textarea
function displayScoring(message) {
    let textarea = document.getElementById('score-report');
    textarea.value = message;
}