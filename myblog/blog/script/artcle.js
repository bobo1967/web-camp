var showReply = document.getElementsByClassName("comment-number")[0];
var reply = document.getElementsByClassName("reply-container")[0];
var hideReply = document.getElementsByClassName("hide-buttom")[0];
showReply.onclick = function() {
    reply.style.display = "block";
    hideReply.style.display = "block";
    showReply.style.display = "none";
};
hideReply.onclick = function() {
    reply.style.display = "none";
    hideReply.style.display = "none";
    showReply.style.display = "block";
};

