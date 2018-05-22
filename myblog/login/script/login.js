/*
登陆界面
 */
    
//var patrn_email = /^[a-z0-9]+([._\\-]*[a-z0-9])*@([a-z0-9]+[-a-z0-9]*[a-z0-9]+.){1,63}[a-z0-9]+$/;
var patrn_tel = /^1[0-9]{10}$/;
var partn_spacing = /\s/;

var loginAccount = document.getElementById("login-account");
var loginPassword = document.getElementById("login-password");
//验证码模块
var idc = document.getElementsByClassName("idcContainer")[0];

var summitButton = document.getElementsByClassName("summit_button");
var loginButton = summitButton[0];
loginButton.disabled = true;

var flag1 = false;
var flag2 = false;

function isLoginEmpty() {
    if (loginAccount.value == "") {
        showMessage(loginAccount, "手机号码不能为空！");
        flag1 = false;     
    }
    if (loginPassword.value == "") {
        showMessage(loginPassword, "密码不能为空！");
        flag2 = false;
    }
};
function isLoginRight() {
    if ( patrn_email.test(loginAccount.value) || patrn_tel.test(loginAccount.value)) {
        hideMsg(loginAccount);
        flag1 = true;
    }  
    else  {
        showMessage(loginAccount,"请输入正确的手机号码！");
        flag1 = false;
    }
    if (partn_spacing.test(loginPassword.value)) {
        showMessage(loginPassword, "密码含有非法字符！");
        flag2 = false;
    } else {
        hideMsg(loginPassword);
        flag2 = true;
    }
};
function canLogin() {
    if ( flag1 == true && flag2 == true ) {
        addClass(loginButton, "canUse");
        loginButton.disabled = false;
    }  else {
        loginButton.disabled = true;
        removeClass(loginButton, "canUse");
    }
};

loginAccount.onblur = function() {
    isLoginEmpty();
    isLoginRight();
}
loginAccount.onkeyup = function() {
    isLoginRight();
    isLoginEmpty();
    canLogin();
}
loginPassword.onblur = function() {
    isLoginEmpty();
    isLoginRight();
}
loginPassword.onkeyup = function() {
    isLoginRight();
    isLoginEmpty();
    canLogin();
}
/**
 * 切换注册页面
 */
var switchButton = document.getElementsByClassName("switch-button")[0];
var container2 = document.getElementsByClassName("container2")[0];
var container = document.getElementsByClassName("container")[0];
var close = document.getElementsByClassName("close")[0];

switchButton.onclick = function(){
    addClass(container2, "active");
    setTimeout("addClass(container, 'reset')",200);
};
close.onclick = function(){
    removeClass(container2, "active");
    removeClass(container, "reset"); 
};









