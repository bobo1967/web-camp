

//初始化二叉树 
Status InitBiTree(BiTree *T) {
	(*T)->lchild= NULL;
	(*T)->rchild = NULL;
	*T = NULL;
	return SUCCESS;
} 

//构造二叉树

Status CreateBiTree(BiTree T, char* definition) {
	 	static i = 0;
		char j = definition[i];
		i++;
		 
		if (j == '\0') {
			return SUCCESS;
		}  else  
		if ('#' == j || (j >= '0' && j <= '9')) //后面是赋值用的 
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
	if (NULL == T)//树为空时退出 
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
//销毁二叉树
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
//访问函数 
void visit(BiTree p) {

	printf("%c", p->data);
}
//先序遍历 
Status PreOrderTraverse(BiTree T, void (*foo)()) {
	if (NULL == T) {//节点为空 
		return ERROR; 
	} else {
		visit(T);
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit); 
	}
	
} 
//中序遍历 
Status InOrderTraverse(BiTree T, void visit(BiTree p)) {
	if (NULL == T) {
		return ERROR;
	} else {
		InOrderTraverse(T->lchild, visit);
		visit(T);
		InOrderTraverse(T->rchild, visit);
	}
}	
//后序遍历 
Status PostOrderTraverse(BiTree T, void visit(BiTree p)) { 
	if (NULL == T) {
		return ERROR;
	} else {
		PostOrderTraverse(T->lchild, visit);
		PostOrderTraverse(T->rchild, visit);
		visit(T);	
	}
} 
//层序遍历
Status LevelOrderTraverse(BiTree T, void visit()) {
	
	BiTree queue[1000]; //一层最多可以有1000个结点 
	int front = 0;
	int rear = 0;
	if (NULL != T) {
		//队列头结点不为空 
		rear = (rear + 1) % 1000;
		queue[rear] = T;
		
	}
	while (front != rear) {
		//出队访问
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
