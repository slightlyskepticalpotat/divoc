const start = document.getElementById("start");
const quiz = document.getElementById("quiz");
const question = document.getElementById("question");
const qImg = document.getElementById("qImg");
const choiceA = document.getElementById("A");
const choiceB = document.getElementById("B");
const choiceC = document.getElementById("C");
const counter = document.getElementById("counter");
const link = document.getElementById ("link");
const scoreDiv = document.getElementById("scoreContainer");

// create our questions
let questions = [
    {
        question : "Have you been abroad in the past 2 weeks?",
        imgSrc : "img/planePerson.jpg",
        choiceA : "Yes",
        choiceB : "No",
        choiceC : "Not sure",
        one : "A",
        two : "B",
        three:"C"
    },{
        question : "Have you had difficulty breathing or a dry cough?",
        imgSrc : "img/cough.jpg",
        choiceA : "Yes",
        choiceB : "No",
        choiceC : "Not sure",
        one : "A",
        two : "B",
        three:"C"
    },{
        question : "Do you have nasal congestion?",
        imgSrc : "img/nasal.jpg",
        choiceA : "Yes",
        choiceB : "No",
        choiceC : "Not sure",
        one : "A",
        two : "B",
        three:"C"
    },{
        question : "Have you had a fever?",
        imgSrc : "img/fever.jpg",
        choiceA : "Yes",
        choiceB : "No",
        choiceC : "Not sure",
        one : "A",
        two : "B",
        three:"C"
    }
    ,{
        question : "Have you experienced severe chest pains?",
        imgSrc : "img/chest.jpg",
        choiceA : "Yes",
        choiceB : "No",
        choiceC : "Not sure",
        one : "A",
        two : "B",
        three:"C"
    }
    ,{
        question : "Have you experienced a lost sense of taste and smell?",
        imgSrc : "img/smell.png",
        choiceA : "Yes",
        choiceB : "No",
        choiceC : "Not sure",
        one : "A",
        two : "B",
        three:"C"
    }
    ,{
        question : "Are you in close contact with a person who recently travelled outside of Canada?",
        imgSrc : "img/travel.jpg",
        choiceA : "Yes",
        choiceB : "No",
        choiceC : "Not sure",
        one : "A",
        two : "B",
        three:"C"
    }
];

// create some variables

const lastQuestion = questions.length - 1;
let runningQuestion = 0;
let count = 0;
let resultScore = 0;
let score = 0;

// render a question
function renderQuestion(){
    let q = questions[runningQuestion];

    question.innerHTML = "<p>"+ q.question +"</p>";
    qImg.innerHTML = "<img src="+ q.imgSrc +">";
    choiceA.innerHTML = q.choiceA;
    choiceB.innerHTML = q.choiceB;
    choiceC.innerHTML = q.choiceC;
}

start.addEventListener("click",startQuiz);

// start quiz
function startQuiz(){
    start.style.display = "none";
    renderQuestion();
    quiz.style.display = "block";
    renderProgress();
}

// render progress
function renderProgress(){
    for(let qIndex = 0; qIndex <= lastQuestion; qIndex++){
        progress.innerHTML += "<div class='prog' id="+ qIndex +"></div>";
    }
}



// checkAnwer

function checkAnswer(answer){
    if (answer == questions[runningQuestion].one){
        score+=10;
    }
    else if (answer == questions[runningQuestion].three){
      score+=5;
    }
    answerIsCorrect();

    count = 0;
    if(runningQuestion < lastQuestion){
        runningQuestion++;
        renderQuestion();
    }else{
        // end the quiz and show the score
        scoreRender();
    }
}

// answer is correct
function answerIsCorrect(){
    document.getElementById(runningQuestion).style.backgroundColor = "#0f0";
}

// score render
function scoreRender(){
    scoreDiv.style.display = "block";

    // calculate the amount of question percent answered by the user
    const scorePerCent = Math.round(100 *score/ (10*questions.length));

    // choose the image based on the scorePerCent
    let img = (scorePerCent >= 80) ? "img/1.png" :
              (scorePerCent >= 60) ? "img/2.png" :
              (scorePerCent >= 40) ? "img/3.png" :
              (scorePerCent >= 20) ? "img/4.png" :
              "img/5.png";

    scoreDiv.innerHTML = "<img src="+ img +">";
    scoreDiv.innerHTML += "<p>Your chance of having COVID-19 is ~"+ scorePerCent+"%</p>";


}
