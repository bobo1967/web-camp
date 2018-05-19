/*
用户名：支持中文，下划线，数字，英文，6-25个字符，中文为2个字符
账号： 邮箱或者手机号码
密码:  6-20位，不可以为全英文全数字，不可以为空格
验证码：开放接口
*/

function hasClass( elements,cName ){ 
    return !!elements.className.match( new RegExp( "(\\s|^)" + cName + "(\\s|$)") ); 
}; 
function addClass( elements,cName ){ 
if( !hasClass( elements,cName ) ){ 
    elements.className += " " + cName; 
    }; 
}; 
function removeClass( elements,cName ){ 
    if( hasClass( elements,cName ) ){ 
      elements.className = elements.className.replace( new RegExp( "(\\s|^)" + cName + "(\\s|$)" ), " " );
    }; 
};


var partn_username = /[^\w\u4e00-\u9fa5]/;
var patrn_email = /^[a-z0-9]+([._\\-]*[a-z0-9])*@([a-z0-9]+[-a-z0-9]*[a-z0-9]+.){1,63}[a-z0-9]+$/;
var patrn_tel = /^1[0-9]{10}$/;
var partn_spacing = /\s/;
var partn_password = /^(?=.*\d)(?=.*[a-zA-Z])(?=.*[~!@#$%^&*])[\da-zA-Z~!@#$%^&*]{8,20}$/;

var username = document.getElementById("username");
var signinAccount = document.getElementById("signin-account");
var signinPassword = document.getElementById("signin-password");
var commitPassword = document.getElementById("commitPassword");
//验证码模块
var idc_1 = document.getElementsByClassName("idcContainer")[1];

var  signinButton = document.getElementsByClassName("summit_button")[1];

signinButton.disabled = false;

var flag = new Array();
flag[0] = false; flag[1] = false;
flag[2] = false; flag[3] = false;
//获得长度函数
var getLength = function(str) {
    return str.replace(/[^\x00-xff]/g, "xx").length;
}
var showMessage = function(x, message) {
    addClass(x, "change-input-boderRadius");
    addClass(x.nextElementSibling, "show-Msg");
    x.nextElementSibling.firstElementChild.innerHTML = message;
}
var hideMsg = function(x) {
    removeClass(x, "change-input-boderRadius");
    removeClass(x.nextElementSibling,"show-Msg");
}

function isSigninEmpty() {
    if (username.value == "") {
        showMessage(username, "用户名不能为空！");
        flag[0] = false;     
    } 
    if (signinAccount.value == "") {
        showMessage(signinAccount, "手机号码不能为空！");
        flag[1] = false;
    } 
    if (signinPassword.value == "") {
        showMessage(signinPassword, "密码不能为空！");
        flag[2] = false;
    } 
    if (commitPassword.value == "") {
        showMessage(commitPassword, "请再次输入密码");
        flag[3] = false;
    } 
}

username.onkeyup = function() {
    if (partn_username.test(this.value)) {
        showMessage(this,"含有非法字符!");
        flag[0] = false;
    }
    else if( (getLength(this.value) < 6 || getLength(this.value ) > 25) && this.value != "") {
        showMessage(this,"用户名不能少于6个字符或者多于25个字符！");
        flag[0] = false;
    }
    else if (this.value == "") {
        showMessage(this, "用户名不能为空！");
        flag[0] = false;     
    } 
    else {
        hideMsg(this);
        flag[0] = true;    
    }
}

username.onblur = function() {
    if (this.value == "") {
        showMessage(this, "用户名不能为空！");
        flag[0] = false;     
    } 
}

signinAccount.onkeyup = function() {
    if (patrn_tel.test(this.value) || patrn_email.test(this.value) ) {
        hideMsg(this);
        flag[1] = true;
    }  else if (this.value == "") {
        showMessage(this, "请再次输入密码！");
        flag[1] = false;     
    } 
    else {
        showMessage(this, "请输入正确的邮箱或者手机号码！");
        flag[1] = false; 
    }
}

signinAccount.onblur = function() {
    if (this.value == "") {
        showMessage(this, "请再次输入密码！");
        flag[1] = false;     
    } 
}


signinPassword.onkeyup = function() {
    
    if (!partn_password.test(this.value)) {
        showMessage(this,"请输入8到20位密码，仅支持'~!@#$%^&*' "); 
        flag[2] = false; 
    }  else if (this.value == "") {
        showMessage(this, "密码不能为空！");
        flag[2] = false;     
    } 
    else {
        hideMsg(this);
        flag[2] = true;
    }
    if (commitPassword.value == this.value) {
        hideMsg(commitPassword);
        flag[3] = true;
    } else if (commitPassword.value != "" && commitPassword.value != this.value) {
        showMessage(commitPassword, "两次输入的密码不相同！");
        flag[3] = false;
    }
}
signinPassword.onblur = function() {
    if (this.value == "") {
        showMessage(this, "请再次输入密码！");
        flag[2] = false;     
    } 
}
commitPassword.onkeyup = function() {
    
    if (this.value != "" && this.value != signinPassword.value){
        showMessage(this, "两次输入密码不相同！");
        flag[3] = false;
    }
    else if (this.value == "") {
        showMessage(this, "请再次输入密码！");
        flag[3] = false;     
    } 
    else {
        hideMsg(this);
        flag[3] = true;
    }
}
commitPassword.onblur = function() {
    if (this.value == "") {
        showMessage(this, "请再次输入密码！");
        flag[3] = false;     
    } 
}


signinButton.onclick =  function() {
    isSigninEmpty();
    if (flag[0] == true && flag[1] == true && flag[2] == true && flag[3] == true) {
        return true;
    }
    else {
        return false;
    }
}
