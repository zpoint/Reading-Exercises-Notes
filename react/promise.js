const getPromiseData = (num) => {new Promise((resolve, reject) => {typeof num == "number" ? resolve(num*2): reject("expect a number")})}

let complete = false;

let learnJS = new Promise(function (resolve, reject) {
    if (complete) {
        resolve("I've completed learning JS.");
    } else {
        reject("I haven't complete learning JS yet");
    }

});