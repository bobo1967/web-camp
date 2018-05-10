

//��ʼ�������� 
Status InitBiTree(BiTree *T) {
	(*T)->lchild= NULL;
	(*T)->rchild = NULL;
	*T = NULL;
	return SUCCESS;
} 

//���������

Status CreateBiTree(BiTree T, char* definition) {
	 	static i = 0;
		char j = definition[i];
		i++;
		 
		if (j == '\0') {
			return SUCCESS;
		}  else  
		if ('#' == j || (j >= '0' && j <= '9')) //�����Ǹ�ֵ�õ� 
		{
			T->data = j;
		//	printf("%c", T->data);
			T->lchild = NULL;
			T->rchild = NULL; 
		}
		else {
			T->data = j;
			//printf("%c", T->data);
			T->lchild = (BiTree)malloc(sizeof(BiTNode));
			CreateBiTree(T->lchild, definition);
			T->rchild = (BiTree)malloc(sizeof(BiTNode));
			CreateBiTree(T->rchild, definition);
		}
		return SUCCESS; 
} 

double Value(BiTree T) {
	if (NULL == T)//��Ϊ��ʱ�˳� 
		return ERROR;
	int l, r, sum;
	if ('0' <= T->data && T->data <= '9') { 
		return (double)(T->data - '0');
	}  
	else {
		switch(T->data) {
			case '+' : {
				return (Value(T->lchild) + Value(T->rchild));
				break;
			} 
			case '-' : {
				return (Value(T->lchild) - Value(T->rchild));
				break;
			}
			case '*' : {
				return (Value(T->lchild) * Value(T->rchild));
				break;
			}
			case '/' : {
				return (Value(T->lchild) / Value(T->rchild));
				break;
			}
		} 
	}  
}
//���ٶ�����
Status DestroyBiTree(BiTree *T) {
    if (*T == NULL)  
    {  
        return;  
    }  
  
    DestroyBiTree(&(*T)->lchild);  
    DestroyBiTree(&(*T)->rchild);  
    free(*T);  
    *T = NULL;
} 
//���ʺ��� 
void visit(BiTree p) {

	printf("%c", p->data);
}
//������� 
Status PreOrderTraverse(BiTree T, void (*foo)()) {
	if (NULL == T) {//�ڵ�Ϊ�� 
		return ERROR; 
	} else {
		visit(T);
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit); 
	}
	
} 
//������� 
Status InOrderTraverse(BiTree T, void visit(BiTree p)) {
	if (NULL == T) {
		return ERROR;
	} else {
		InOrderTraverse(T->lchild, visit);
		visit(T);
		InOrderTraverse(T->rchild, visit);
	}
}	
//������� 
Status PostOrderTraverse(BiTree T, void visit(BiTree p)) { 
	if (NULL == T) {
		return ERROR;
	} else {
		PostOrderTraverse(T->lchild, visit);
		PostOrderTraverse(T->rchild, visit);
		visit(T);	
	}
} 
//�������
Status LevelOrderTraverse(BiTree T, void visit()) {
	
	BiTree queue[1000]; //һ����������1000����� 
	int front = 0;
	int rear = 0;
	if (NULL != T) {
		//����ͷ��㲻Ϊ�� 
		rear = (rear + 1) % 1000;
		queue[rear] = T;
		
	}
	while (front != rear) {
		//���ӷ���
		front = (front + 1) % 1000;
		T = queue[front];
		visit(T);  
		
		if (NULL != T->lchild) {
			rear = (rear + 1) % 1000;
			queue[rear] = T->lchild;
		}
		if (NULL != T->rchild) {
			rear = (rear + 1) % 1000; 
			queue[rear] = T->rchild;
		}
	} 
	
} 
