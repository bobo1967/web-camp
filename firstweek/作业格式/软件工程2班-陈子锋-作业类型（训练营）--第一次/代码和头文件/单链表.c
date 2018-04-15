/*********************************************** 
���¶����Ұ���PPT����ɣ��Լ��������д������
���˼·���ԣ������д���ĵط����鷳ʦ��ָ��һ��
лл�� 
ͷ����index Ĭ��Ϊ0
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

//������������һ�������ɹ��򷵻�ͷ��㣬ʧ�ܷ��� NULL 
ptr_Node create(int *arr, int n)
{	
	int i;
	ptr_Node head, p, t;
	head =(ptr_Node)malloc(sizeof(Node)); 
	if (head == NULL)
	{printf("Fail to create list!"); return NULL;}
	//�ж��Ƿ�����ڴ�ɹ� 
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
//���ٸ��������� 
void destroy(ptr_Node head) // ͷָ�����Ұָ�룿 
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
	
	head = NULL; //���������� 
	return;
}

//�ڵ� index λ������� node ��� 
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
Status insert(ptr_Node *head, ptr_Node node, int index) 
{
	if (head == NULL || *head == NULL || index < 0)	
		return ERROR;
	
	int i = 0;
	ptr_Node p;
	p = *head; 
	
	//��index == 0ʱ��node��Ϊͷ������ 
	if (index == 0) 		
	{
		node->next = p; 
		*head = node;	 
		return SUCCESS;
	}
	
	//��index Ϊ���һλʱ
	while (p->next != NULL)
		p = p->next;
	ptr_Node teil = (ptr_Node)malloc(sizeof(Node));
	teil = node;
	p->next = teil;
	teil->next = NULL; 
	
	//�ж�index�Ƿ񳬹������� 
	for (i = 0; i < index; i++) 
	{
		p = p->next; 
		if(p == NULL) {printf("Fail to found!\n"); return ERROR;}
	}
	node->next = p->next;
	p->next = node;
	  
	return SUCCESS;
}

//ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data���� 
//ɾ���ɹ����� SUCCESS������������� ERROR 
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
	}//�ж�index�Ƿ񳬹������� 
	
	*data = p->next->data;
	p = p->next;
	*p = *(p->next);
	return SUCCESS;	
}



//�������в��ҽڵ�ֵ�� data ��ȵĽڵ㣬�������ҵ��ĵ�һ���ڵ��ǰһ���ڵ��λ�� 
//������ͷ�ڵ���ȣ����� 0����û�ҵ����������������-1
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
	while (p != NULL)//p���������һ���ڵ�
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


//�������� index λ�����Ľ���ֵ�޸�Ϊ(*data)����ԭֵ���浽(*data) 
//�޸ĳɹ����� SUCCESS������������� ERROR 
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
	}//�ж�index�Ƿ񳬹������� 
	
	temp = p->next->data;
	p->next->data = *data;
	*data = temp;
	return SUCCESS;	 
}
	
//����ѡ��,ʵ�ֵ������սڵ�ֵ��С�������� 
Status sort(ptr_Node *head)
{
	//ð������
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
			p = p->next; //����һ���pָ�����һ���ڵ� 
		}
		teil = p;	//ÿ����һ�Σ���β������ǰһ���ڵ� 
		p = *head; 	//��p����ָ��ͷ�ڵ� 
	} 
	return SUCCESS;
}
//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã� 
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
		if (i++ % 5 == 0) 	//ÿ5�������� 
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
	//��������
	//destroy(newlist);
	//�������
	/*
	ptr_Node node = (ptr_Node)malloc(sizeof(Node));
	node->data = 0;
	insert(&newlist, node, 10); 
	print(newlist);
	*/ 
	//ɾ������ 				
	/* 
	delete(&newlist, 30, a);
	print(newlist);
	*/ 
	//������� 
	/*
	sort(&newlist); 	
	print(newlist);
	*/ 
	//Ѱ�Ҳ��� 
	/*
	search(newlist, 110);
	print(newlist);
	*/ 
	//�޸Ĳ��� 
	/* 
	a[0] = 100;
	edit(newlist, 20, a);
	print(newlist);
	printf("\na[0] = %d",a[0]);
	*/
	return 0;
}
