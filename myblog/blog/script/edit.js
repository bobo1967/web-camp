/**
 * 创建一个编辑器
 */
var E = window.wangEditor
var editor = new E('#toolbar', '#editor')
editor.customConfig.menus =
    [
        'head',  // 标题
        'bold',  // 粗体
        'fontSize',  // 字号
        'italic',  // 斜体
        'underline',  // 下划线
        'strikeThrough',  // 删除线
        'foreColor',  // 文字颜色
        'backColor',  // 背景颜色
        'link',  // 插入链接
        'list',  // 列表
        'justify',  // 对齐方式
        'quote',  // 引用
        'image',  // 插入图片
        'code',  // 插入代码
        'undo',  // 撤销
        'redo'  // 重复
    ]
editor.customConfig.uploadImgServer = '/upload';
editor.create();

var save = document.getElementById("save");

save.onclick = function() {
    
    alert(editor.txt.html());
};



/**
 * textarea 自动换行
 */

var title = document.getElementById("blog-title");
title.onkeyup = function() {
    title.style.height = this.scrollHeight + "px";
};


