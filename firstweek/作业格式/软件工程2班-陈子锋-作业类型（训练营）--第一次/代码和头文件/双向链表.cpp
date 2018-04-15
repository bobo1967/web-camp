/*********************************************** 
以下都是我按照PPT和题干，自己理解题意写出来的
如果思路不对，或者有错误的地方，麻烦师兄指点一下
谢谢！ 
头结点的index 默认为0
************************************************/ 
#include<stdio.h>
#include<stdlib.h>

typedef struct TNode 
{ 
	int data; 
	struct TNode *next;
	struct TNode *pre;
}TNode, *ptr_TNode;

typedef enum Status 
{
	SUCCESS,
	ERROR 
}Status;

//根据数组生成一条双向链表，成功则返回头节点，失败返回 NULL 
ptr_TNode create(int *arr, int n)
{
	int i = 1;
	ptr_TNode head, p, q;
	head = NULL;
	p = NULL;
	head = (ptr_TNode)malloc(sizeof(TNode));
		if (head == NULL)
		{printf("fail to create list!\n"); return NULL;}
	head->data = *arr;
	head->pre = NULL;
	q = head;
	for (i = 1; i < n; i++) 
	{
		p = (ptr_TNode)malloc(sizeof(TNode));
			if (p == NULL)
			{printf("fail to create list!\n"); return NULL;}			
		p->data = (*arr+i);
		p->pre = q;
		p->next = NULL;
		q->next = p;
		q = q->next;
	}
	return head; 
}

//双向链表,删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
Status delete_T(ptr_TNode *head, int index, int *data)
{
	if (head == NULL || *head == NULL || index < 0)
		return ERROR;
	
	int i = 0;
	ptr_TNode p, q;
	p = *head;
	if (index == 0)		//index为0，删除头节点 
	{
		*data = p->data;		
		*head = p->next;
		p->next->pre == NULL;
		free(p);
		return SUCCESS;
	}
	
	for (i = 0; i < index; i++) 
	{
		p = p->next; 
		if(p == NULL) {printf("Fail to delete!\n"); return ERROR;}
	}//判断index是否超过链表长度 
	
	*data = p->next->data;
	p->next->next->pre = p;
	p = p->next;
	*p = *(p->next);
	return SUCCESS;
}	


//双向链表,在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
Status insert_T(ptr_TNode *head, ptr_TNode node, int index)
{
	if (head == NULL || *head == NULL || index < 0)
		return ERROR;
	int i = 0;
	ptr_TNode p;
	p = *head;
	if (index == 0)
	{
		p->pre = node;
		node->next = p;
		node->pre = NULL;
		*head = node;	
		return SUCCESS; 
	}
	
	//当index 为最后一位时
	while (p->next != NULL)
		p = p->next;
	ptr_TNode teil = (ptr_TNode)malloc(sizeof(TNode));
	teil = node;
	p->next = teil;
	teil->next = NULL; 
	
	for (i = 0; i < index; i++) 
	{
		p = p->next; 
		if(p == NULL) {printf("Fail to insert!\n"); return ERROR;}
	}//判断index是否超过链表长度 
	node->next = p->next;
	p->next->pre = node;
	p->next = node;
	node->pre = p;
	return SUCCESS;		
}
//销毁给定的链表  
//这里我改为了二级指针
void destroy(ptr_TNode *head)
{
	if (head == NULL)
		return; 
	ptr_TNode p, q;
	p = *head;
	while(p != NULL)
	{
		p = p->next; 
		free(q);
		q = p;
	} 
	*head = NULL;
}
//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好）
void print(ptr_TNode head)
{
	if (head == NULL)
	{
		printf("This is an empty list.\n");
		printf("\n");
		return;
	}
	
	ptr_TNode p;
	p = head; 
	int i = 1; 
	
	printf ("Your list:\n");
	while (p != NULL)
	{
		printf ("%5d  ", p->data);
		p = p->next; 
		if (i++ % 5 == 0) 	//每5个数换行 
			putchar('\n');
	}
}


int main()
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[1];
	ptr_TNode newlist;
	newlist = create(arr, 10);
	print(newlist);  
	
	
	//删除测试 				
	/*
	delete_T(&newlist, 3, a);
	print(newlist);
	printf("\na[0] = %d",a[0]);
	*/ 
	
	//插入测试
	/* 
	ptr_TNode node = (ptr_TNode)malloc(sizeof(TNode));
	node->data = 0;
	node->next = NULL;
	insert_T(&newlist, node, 12); 
	print(newlist);
	*/
	
	//销毁测试
	/*
	destroy(&newlist);
	print(newlist); 
	*/
	return 0;
}
