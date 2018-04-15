/*********************************************** 
以下都是我按照PPT和题干，自己理解题意写出来的
如果思路不对，或者有错误的地方，麻烦师兄指点一下
谢谢！ 
头结点的index 默认为0
************************************************/ 
#include<stdio.h>
#include<stdlib.h>
			
typedef struct Node 
{ int data; 
  struct Node *next; 
}Node, *ptr_Node;

typedef enum Status 
{ 
	SUCCESS, 
	ERROR 
}Status;

//根据数组生成一条链表，成功则返回头结点，失败返回 NULL 
ptr_Node create(int *arr, int n)
{	
	int i;
	ptr_Node head, p, t;
	head =(ptr_Node)malloc(sizeof(Node)); 
	if (head == NULL)
	{printf("Fail to create list!"); return NULL;}
	//判断是否分配内存成功 
	head->next = NULL;  
	head->data = *arr;
	t = head;  
	for (i = 1; i < n; i++)
	{
		p =(ptr_Node)malloc(sizeof(Node));
		if (p == NULL)
		{ printf("Fail to create list!"); return NULL;}
		p->data= *(arr+i);
		t->next = p;
		p->next = NULL;
		t = t->next;
	}
	
	return head;
}
//销毁给定的链表 
void destroy(ptr_Node head) // 头指针会变成野指针？ 
{
	
	if (head == NULL)
		return;
	ptr_Node p, q; 
	p = head;
	q = p;
	while(q != NULL)
	{
		
		p = p->next;
		free(q);
		q = p; 
	}
	
	head = NULL; //好像不起作用 
	return;
}

//在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
Status insert(ptr_Node *head, ptr_Node node, int index) 
{
	if (head == NULL || *head == NULL || index < 0)	
		return ERROR;
	
	int i = 0;
	ptr_Node p;
	p = *head; 
	
	//当index == 0时，node作为头结点插入 
	if (index == 0) 		
	{
		node->next = p; 
		*head = node;	 
		return SUCCESS;
	}
	
	//当index 为最后一位时
	while (p->next != NULL)
		p = p->next;
	ptr_Node teil = (ptr_Node)malloc(sizeof(Node));
	teil = node;
	p->next = teil;
	teil->next = NULL; 
	
	//判断index是否超过链表长度 
	for (i = 0; i < index; i++) 
	{
		p = p->next; 
		if(p == NULL) {printf("Fail to found!\n"); return ERROR;}
	}
	node->next = p->next;
	p->next = node;
	  
	return SUCCESS;
}

//删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
//删除成功返回 SUCCESS，其他情况返回 ERROR 
Status delete(ptr_Node *head, int index, int *data)
{
	if (head == NULL || *head == NULL || index < 0)
		return ERROR;
	
	int i = 0;
	ptr_Node p;
	p = *head;
	if (index == 0)
	{
		*data = p->data;
		*head = p->next;	 
		free(p);
		return SUCCESS;
	}
	
	for (i = 0; i < index; i++) 
	{
		p = p->next; 
		if(p == NULL) {printf("Fail to delete!\n"); return ERROR;}
	}//判断index是否超过链表长度 
	
	*data = p->next->data;
	p = p->next;
	*p = *(p->next);
	return SUCCESS;	
}



//在链表中查找节点值与 data 相等的节点，并返回找到的第一个节点的前一个节点的位置 
//（例：头节点相等，返回 0），没找到或者其他情况返回-1
int search(ptr_Node head, int data)
{
	if (head == NULL)
		return -1;
		
	int i = 0;
	ptr_Node p;
	p = head;
	if (p->data == data)
	{
		printf("0");
		return 0;
	}
	
	p = p->next;
	while (p != NULL)//p遍历到最后一个节点
	{
		if (p->data == data)
			break;
		p = p->next;
		i++;
	}
	if (p == NULL) 
	{
		printf("No found!"); 
		return -1;	
	}
	
	else
	{
		printf("%d",i);
		return i;
	}
}


//将链表中 index 位点后面的结点的值修改为(*data)，将原值保存到(*data) 
//修改成功返回 SUCCESS，其他情况返回 ERROR 
Status edit(ptr_Node head, int index, int *data)
{
	if (head == NULL || index < 0)
		return ERROR;
	int temp;
	int i = 0;
	ptr_Node p;
	p = head;
	if (index == 0)
	{
		temp = head->data;
		head->data = *data;
		*data = temp;
		return SUCCESS;
	}	
	
	for (i = 0; i < index; i++) 
	{
		p = p->next; 
		if(p == NULL) {printf("Fail to found!\n"); return ERROR;}
	}//判断index是否超过链表长度 
	
	temp = p->next->data;
	p->next->data = *data;
	*data = temp;
	return SUCCESS;	 
}
	
//此题选做,实现单链表按照节点值大小升序排序 
Status sort(ptr_Node *head)
{
	//冒泡排序
	if (head == NULL || *head == NULL)
		return ERROR; 
	ptr_Node p, teil;
	teil = NULL;
	p = NULL;
	int temp;
	p = *head;
	while(p != teil)
	{
		while (p->next != teil)
		{
			if (p->data > p->next->data)
			{
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next; //遍历一遍后，p指向最后一个节点 
		}
		teil = p;	//每排序一次，表尾都会向前一个节点 
		p = *head; 	//将p重新指向头节点 
	} 
	return SUCCESS;
}
//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好） 
void print(ptr_Node head)
{
	if (head == NULL)
	{
		printf("This is an empty list.\n");
		printf("\n");
		return;
	}
	
	ptr_Node p;
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
	ptr_Node newlist;
	newlist = create(arr, 10);
	print(newlist);  
	//销毁链表
	//destroy(newlist);
	//插入测试
	/*
	ptr_Node node = (ptr_Node)malloc(sizeof(Node));
	node->data = 0;
	insert(&newlist, node, 10); 
	print(newlist);
	*/ 
	//删除测试 				
	/* 
	delete(&newlist, 30, a);
	print(newlist);
	*/ 
	//排序测试 
	/*
	sort(&newlist); 	
	print(newlist);
	*/ 
	//寻找测试 
	/*
	search(newlist, 110);
	print(newlist);
	*/ 
	//修改测试 
	/* 
	a[0] = 100;
	edit(newlist, 20, a);
	print(newlist);
	printf("\na[0] = %d",a[0]);
	*/
	return 0;
}
