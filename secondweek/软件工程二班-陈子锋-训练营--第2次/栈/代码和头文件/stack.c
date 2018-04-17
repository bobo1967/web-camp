#include <stdio.h>
#include "stack.h"
#include <stdlib.h>


//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
	s->elem = (ElemType *)malloc(sizes * sizeof(ElemType));
	if (NULL == s->elem)
		return ERROR;
	s->top = -1;
	s->size = sizes;
	return OK;
}


Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	return (-1 == s->top?1: 0);
}


Status getTopStack(SqStack *s,ElemType *e)   //得到栈头元素
{
	if (NULL == s || -1 == s->top)
		return ERROR;
	*e = s->elem[s->top];
	return OK;
}


Status clearStack(SqStack *s)   //清空栈
{
	if (NULL == s || -1 == s->top)
		 return ERROR;
	else
		s->top = -1;
}


Status destoryStack(SqStack *s)  //销毁栈
{
	if (NULL == s)
		return ERROR;
	free(s->elem);
		return OK;
}


Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	if (NULL == s)
		return ERROR;
	*length = s->top;
}

Status pushStack(SqStack *s,ElemType datas)  //入栈
{
	if (NULL == s)
		return ERROR;
	s->top++;
	s->elem[s->top] = datas;
	return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //出栈
{
	if (NULL == s || -1 == s->top)
		return ERROR;
	*datas = s->elem[s->top];
	s->top--;
	return OK;
}

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (NULL == s->top)
        return ERROR;
	s->top->next = NULL;
	s->count = 0;
	return OK;
}

Status isEmptyLStack(LinkStack *s)  //判断栈是否为空
{
	return (NULL == s->top? OK: ERROR);
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈头元素
{
	if (NULL == s->top || s->count == 0)
		return ERROR;
	*e = s->top->data;
	return OK;
}

Status clearLStack(LinkStack *s)   //清空栈
{
	if (NULL == s->top)
		return ERROR;
	LinkStackPtr p, q;
	p = s->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	s->count = 0;

	return OK;

}

Status destoryLStack(LinkStack *s)   //销毁栈
{
    clearLStack(s);
	free(s->top);
 	return OK;
}

Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	if (NULL == s->top)
		return ERROR;
	*length = s->count;
	return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //入栈
{
	if (NULL == s->top)
		return ERROR;
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (NULL == p)
		return ERROR;
	p->data = datas;
	p->next = s->top;
	s->top = p;
	s->count++;
	return OK;
}

Status popLStack(LinkStack *s,ElemType *datas)   //出栈
{
	if (NULL == s->top || 0 == s->count)
		return ERROR;
	*datas = s->top->data;
	LinkStackPtr p = s->top;
	s->count--;
	s->top = s->top->next;
	free(p);
	return OK;
}


