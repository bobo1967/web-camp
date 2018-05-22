var hideButton = document.getElementById("hide-button");
var showButton = document.getElementById("show-button");
var editInfo = document.getElementsByClassName("edit-info-container")[0];
var editInfoButton = document.getElementById("edit-info-button");

editInfoButton.onclick=showButton.onclick = function() {
    showButton.style.display = "none";
    editInfo.style.display = "block";
    hideButton.style.display = "block";
    
};

hideButton.onclick = function() {
    showButton.style.display = "block";
    hideButton.style.display = "none";
    editInfo.style.display = "none";
};





