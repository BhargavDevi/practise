function card (title,text,follow) {

// document.getElementsByClassName("card-title")[0].innerHTML=`${title}`;
// document.getElementsByClassName("card-text")[0].innerHTML=`${text}`;
// document.getElementsByClassName("follow")[0].innerHTML=`${follow}`;



if (follow>1000&&follow<100000) {
    follow=(follow/1000)+"K" ;   
}
else if(follow>100000){
     follow=(follow/100000)+"M";
}
let html = `
<div class="card" style="width: 18rem;">
<div class="cards">
        <div class="card-body">
            <img src="..." class="card-img-top" alt="...">

            <h5 class="card-title">${title}</h5>
            <p class="card-text">${text}</p>
                  <a href="#" class="btn btn-primary">Go somewhere</a>

            <p class="follow">Follow : ${follow}</p>
        </div>        </div></div>

    `;
// document.querySelector("card")=document.querySelector("card")+document.body   
document.querySelector(".container").innerHTML+=html;
}

document.getElementById("cardForm").addEventListener("submit", function (event) {
    event.preventDefault(); // Prevent form from refreshing the page

    const title = document.getElementById("input").value;
    const text = document.getElementById("input1").value;
    const follow = document.getElementById("input2").value;

    card(title, text, follow);

    // Clear the form inputs after submission
    document.getElementById("cardForm").reset();
});