/*
用户名：支持中文，下划线，数字，英文，6-25个字符，中文为2个字符
账号： 邮箱或者手机号码
密码:  6-20位，不可以为全英文全数字，不可以为空格
验证码：开放接口
*/

var partn_username = /[^\w\u4e00-\u9fa5]/;
var patrn_email = /^[a-z0-9]+([._\\-]*[a-z0-9])*@([a-z0-9]+[-a-z0-9]*[a-z0-9]+.){1,63}[a-z0-9]+$/;
var patrn_tel = /^1[0-9]{10}$/;
var partn_spacing = /\s/;
var partn_password = /^(?=.*\d)(?=.*[a-zA-Z])(?=.*[~!@#$%^&*])[\da-zA-Z~!@#$%^&*]{8,20}$/;

var username = document.getElementById("username");
var signinAccount = document.getElementById("signin-account");
var signinPassword = document.getElementById("signin-password");
var commitPassword = document.getElementById("commitPassword");
var msgContainer = document.getElementsByClassName("msgContainer");
var msgSignin = document.getElementsByClassName("msg-signin");
//验证码模块
var idc_1 = document.getElementsByClassName("idcContainer")[1];

var summitButton = document.getElementsByClassName("summit_button");
var signinButton = summitButton[1];
signinButton.disabled = true;

var flag = new Array();
flag[0] = false; flag[1] = false;
flag[2] = false; flag[3] = false;
//获得长度函数
function getLength(str) {
    return str.replace(/[^\x00-xff]/g, "xx").length;
}


username.onkeyup = function() {
    canSummit();
    if (partn_username.test(this.value)) {
        msgContainer[2].style.display = "block";
        msgSignin[0].innerHTML = "用户名含有非法字符！仅支持 '_' ";
        username.style.borderRadius = "5px 5px 0 0";
        flag[0] = false;
    }
    else if(getLength(this.value) < 6 || getLength(this.value) > 25) {
        msgContainer[2].style.display = "block";
        msgSignin[0].innerHTML = "用户名不能少于6个字符或者多于25个字符！";
        username.style.borderRadius = "5px 5px 0 0";
        flag[0] = false;
    }
    else {
        msgContainer[2].style.display = "none";
        username.style.borderRadius = "5px";
        flag[0] = true;    
    }
}
username.onblur = function() {
    if (username.value == "") {
        msgContainer[2].style.display = "block";
        msgSignin[0].innerHTML = "用户名不能为空！";
        username.style.borderRadius = "5px 5px 0 0";
    } 
    else if (flag[0] == true) {
        msgContainer[2].style.display = "none";
        username.style.borderRadius = "5px";
    }
    canSummit();
}

signinAccount.onkeyup = function() {
    if (patrn_tel.test(this.value) || patrn_email.test(this.value) ) {
        msgContainer[3].style.display = "none";
        this.style.borderRadius = "5px";
        flag[1] = true;
    }
    else {
        msgContainer[3].style.display = "block";
        msgSignin[1].innerHTML = "请输入正确的邮箱或者手机号码！";
        this.style.borderRadius = "5px 5px 0 0";
        flag[1] = false; 
    }
    canSummit();
}

signinAccount.onblur = function() {
    if (this.value == "") {
        msgContainer[3].style.display = "block";
        msgSignin[1].innerHTML = "账号不能为空！";
        this.style.borderRadius = "5px 5px 0 0";   
    }
     else if(flag[1] == true) {
        msgContainer[3].style.display = "none";
        this.style.borderRadius = "5px";
    }
}


signinPassword.onblur = function() {
    if (this.value == "") {
        msgContainer[4].style.display = "block";
        msgSignin[2].innerHTML = "密码不能为空！";
        this.style.borderRadius = "5px 5px 0 0";   
    }  else if (flag[2] == true) {
        msgContainer[4].style.display = "none";
        this.style.borderRadius = "5px";
    }
}
signinPassword.onkeyup = function() {
    if (!partn_password.test(this.value)) {
        msgContainer[4].style.display = "block";
        msgSignin[2].innerHTML = "请输入8到20位密码，仅支持'~!@#$%^&*' ";
        this.style.borderRadius = "5px 5px 0 0";   
        flag[2] = false; 
    }
    else {
        msgContainer[4].style.display = "none";
        this.style.borderRadius = "5px";
        flag[2] = true;
    }
    canSummit();
}

commitPassword.onkeyup = function() {
    if (this.value != "" && this.value != signinPassword.value){
        msgContainer[5].style.display = "block";
        msgSignin[3].innerHTML = "两次输入密码不相同！";
        commitPassword.style.borderRadius = "5px 5px 0 0";   
        flag[3] = false;
    }
    else {
        msgContainer[5].style.display = "none";
        commitPassword.style.borderRadius = "5px";
        flag[3] = true;
    }
    canSummit();
}
commitPassword.onblur = function() {
    if (this.value == "") {
        msgContainer[5].style.display = "block";
        msgSignin[3].innerHTML = "请再次输入密码！";
        this.style.borderRadius = "5px 5px 0 0";   
    }
    else if (flag[3] == true){
        msgContainer[5].style.display = "none";
        commitPassword.style.borderRadius = "5px";
    }
}

function canSummit() {
    if (flag[0] == true && flag[1] == true && flag[2] == true && flag[3] == true) {
        signinButton.classList.add("canUse");
        signinButton.disabled = false;
    } else {
        loginButton.disabled = true;
        loginButton.classList.remove("canUse");
    }
}