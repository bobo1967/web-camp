
var firstMenu = document.getElementsByClassName("first-menu")[0];
var secondMenu = document.getElementsByClassName("second-menu")[0];

secondMenu.style.display = "none";
firstMenu.onclick = function() {
    
    if (secondMenu.style.display == "none") {
        secondMenu.style.display = "block";
    } else if (secondMenu.style.display == "block"){
        secondMenu.style.display = "none";
    }
}
firstMenu.onblur = function() {
    
    secondMenu.style.display = "none";
}


var searchBar = document.getElementById("search-bar");

var showSearch = document.getElementsByClassName("show-search")[0];
showSearch.style.display = "none";
searchBar.onclick = function() {
    
    if ( showSearch.style.display == "none") {
        showSearch.style.display = "block";
    }
}
searchBar.onblur = function() {
    showSearch.style.display = "none";
}
/**
 * 更多标签
 */
var hideButton = document.getElementById("hide-button");
var showButton = document.getElementById("show-button");
var tagContainer = document.getElementsByClassName("inner-nav")[0];
showButton.onclick = function() {
    showButton.style.display = "none";
    hideButton.style.display = "block";
    tagContainer.style.height = "auto";
};

hideButton.onclick = function() {
    showButton.style.display = "block";
    hideButton.style.display = "none";
    tagContainer.style.height = "30px";
};
/**
 * 通过模板来动态写blog
 */
var blogTem=document.getElementsByClassName("card")[0];
var cardContainer = document.getElementsByClassName("card-container")[0];
    for (var i = 0; i < 5; i++) {
        var newCard=blogTem.cloneNode(true);
        cardContainer.appendChild(newCard);
        newCard.style.display = "block";
    };
window.onload = function() {
   
}


