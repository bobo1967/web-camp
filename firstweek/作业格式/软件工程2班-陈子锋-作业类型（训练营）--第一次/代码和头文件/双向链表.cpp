/*********************************************** 
���¶����Ұ���PPT����ɣ��Լ��������д������
���˼·���ԣ������д���ĵط����鷳ʦ��ָ��һ��
лл�� 
ͷ����index Ĭ��Ϊ0
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

//������������һ��˫�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL 
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

//˫������,ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data���� 
Status delete_T(ptr_TNode *head, int index, int *data)
{
	if (head == NULL || *head == NULL || index < 0)
		return ERROR;
	
	int i = 0;
	ptr_TNode p, q;
	p = *head;
	if (index == 0)		//indexΪ0��ɾ��ͷ�ڵ� 
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
	}//�ж�index�Ƿ񳬹������� 
	
	*data = p->next->data;
	p->next->next->pre = p;
	p = p->next;
	*p = *(p->next);
	return SUCCESS;
}	


//˫������,�ڵ� index λ������� node ��� 
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
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
	
	//��index Ϊ���һλʱ
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
	}//�ж�index�Ƿ񳬹������� 
	node->next = p->next;
	p->next->pre = node;
	p->next = node;
	node->pre = p;
	return SUCCESS;		
}
//���ٸ���������  
//�����Ҹ�Ϊ�˶���ָ��
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
//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã�
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
		if (i++ % 5 == 0) 	//ÿ5�������� 
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
	
	
	//ɾ������ 				
	/*
	delete_T(&newlist, 3, a);
	print(newlist);
	printf("\na[0] = %d",a[0]);
	*/ 
	
	//�������
	/* 
	ptr_TNode node = (ptr_TNode)malloc(sizeof(TNode));
	node->data = 0;
	node->next = NULL;
	insert_T(&newlist, node, 12); 
	print(newlist);
	*/
	
	//���ٲ���
	/*
	destroy(&newlist);
	print(newlist); 
	*/
	return 0;
}
