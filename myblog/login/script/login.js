/*
登陆界面
 */
    
    //var patrn_email = /^[a-z0-9]+([._\\-]*[a-z0-9])*@([a-z0-9]+[-a-z0-9]*[a-z0-9]+.){1,63}[a-z0-9]+$/;
    var patrn_tel = /^1[0-9]{10}$/;
    var partn_spacing = /\s/;

var loginAccount = document.getElementById("login-account");
var loginPassword = document.getElementById("login-password");
var msgContainer = document.getElementsByClassName("msgContainer");
var msgLogin = document.getElementsByClassName("msg-login");
//验证码模块
var idc = document.getElementsByClassName("idcContainer")[0];

var summitButton = document.getElementsByClassName("summit_button");
var loginButton = summitButton[0];
loginButton.disabled = true;

var flag1 = false;
var flag2 = false;
function isEmpty() {
    if (loginAccount.value == "") {
        msgContainer[0].style.display = "block";
        msgLogin[0].innerHTML = "手机号码不能为空！";
        loginAccount.style.borderRadius = "5px 5px 0 0";   
        flag1 = false;     
    }  else {
        msgContainer[0].style.display = "none";
        loginAccount.style.borderRadius = "5px";
        flag1 = true;
    }
    if (loginPassword.value == "") {
        msgContainer[1].style.display = "block";
        msgLogin[1].innerHTML = "密码不能为空！";
        loginPassword.style.borderRadius = "5px 5px 0 0";
        flag1 = false;
    } else if (partn_spacing.test(loginPassword.value)) {
        msgContainer[1].style.display = "block";
        msgLogin[1].innerHTML = "密码含有非法字符！";
        loginPassword.style.borderRadius = "5px 5px 0 0";
        flag1 = false;
    }
    else {
        msgContainer[1].style.display = "none";
        loginPassword.style.borderRadius = "5px";
        flag1 = true;
    }
    
}
function isRight() {
    if ( patrn_email.test(loginAccount.value) || patrn_tel.test(loginAccount.value)) {
        msgContainer[0].style.display = "none";
        loginAccount.style.borderRadius = "5px";    
        flag2 = true;
    }  
     else if (loginAccount.value != "") {
        msgContainer[0].style.display = "block";
        msgLogin[0].innerHTML = "请输入正确的手机号码！";
        loginAccount.style.borderRadius = "5px 5px 0 0"; 
        flag2 = false;
    }
    
}
loginAccount.onblur = function() {
    isEmpty();
    isRight();
}
loginAccount.onkeyup = function() {
    isRight();
    if ( flag1 == true && flag2 == true ) {
        loginButton.classList.add("canUse");
        loginButton.disabled = false;
    }  else {
        loginButton.disabled = true;
        loginButton.classList.remove("canUse");
    }
}



loginPassword.onblur = function() {
    isEmpty();
    isRight();
}
loginPassword.onkeyup = function() {
    isRight();
    isEmpty();
    if ( flag1 == true && flag2 == true ) {
        loginButton.classList.add("canUse");
        loginButton.disabled = false;
    }  else {
        loginButton.disabled = true;
        loginButton.classList.remove("canUse");
    }
}


$(document).ready(function(){
    $(loginPassword).click(function(){
        $(idc).slideDown();
    });
});






