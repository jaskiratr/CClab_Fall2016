document.addEventListener("DOMContentLoaded", function() {

    //every second, the iteration state will change. once we get to iteration 2, start over at 0

    var colorPool = ["#B2FFE9", "#B2BFFC", "#F26969"]; //use any color combo you like
    console.log("state: " + typeof(colorPool));

    var seconds = 0;
    var state = 0;
    var rotateIncrement = 0;
    var temp = 0;

    //divs from DOM
    var parentDiv = document.getElementsByClassName("blockContainer");
    var div1 = document.getElementById("div1");
    var div2 = document.getElementById("div2");
    var div3 = document.getElementById("div3");

    div1.style.backgroundColor = "#000";
    div2.style.backgroundColor = "#000";
    div3.style.backgroundColor = "#000";

    setInterval(function() {
        seconds += 1;

        parentDiv[0].style.transform = "rotate(" + seconds * 90 + "deg)";
        parentDiv[0].style.WebkitTransform = "rotate(" + seconds * 90 + "deg)";

        div1.style.backgroundColor = colorPool[0];
        div2.style.backgroundColor = colorPool[1];
        div3.style.backgroundColor = colorPool[2];

        temp = colorPool[0];
        colorPool.shift();
        colorPool.push(temp);

        console.log(colorPool);


    }, 1000);
});
