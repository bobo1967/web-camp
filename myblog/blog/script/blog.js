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

