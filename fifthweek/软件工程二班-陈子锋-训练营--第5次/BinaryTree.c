

//初始化二叉树 
Status InitBiTree(BiTree T) {
	//T = NULL;
	T->lchild = NULL;
	T->rchild = NULL;
	return SUCCESS;
} 

//构造二叉树

Status CreateBiTree(BiTree T, char* definition) {
	 	static i = 0;
		char j = definition[i];
		i++;
		 
		if (j == '\0') {
			return SUCCESS;
		} else  
		if ('#' == j ) 
		{
			T->data = j;
			printf("%c", T->data);
			//T = NULL;
			T->lchild = NULL;
			T->rchild = NULL;
			
		}
		else {
			T->data = j;
			printf("%c", T->data);
			T->lchild = (BiTree)malloc(sizeof(BiTNode));
			if (NULL == T->lchild) {
				return ERROR; //内存申请失败 
			}
			CreateBiTree(T->lchild, definition);
			T->rchild = (BiTree)malloc(sizeof(BiTNode));
			if (NULL == T->rchild) {
				return ERROR;
			} 
	 		CreateBiTree(T->rchild, definition);
		}
		return SUCCESS; 
} 

//销毁二叉树
Status DestroyBiTree(BiTree T) {
	if ( NULL != T) {
		return; 
	}
	else {
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		T = NULL;
	}
} 

void visit(BiTree p) {
	printf("%c", p->data);
}
//先序遍历 
Status PreOrderTraverse(BiTree T, void visit(BiTree p)) {
	if (NULL == T) {//节点为空 
		return ERROR; 
	} else {
		visit(T);
		//printf("%c", T->data);
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
Status LevelOrderTraverse(BiTree T, void visit(BiTree p)) {
	BiTree queue[1000]; //一层最多可以有1000个结点 
	int front = 0;
	int rear = 0;
	if (NULL != T) {
		//队列头结点不为空 
		rear = (rear + 1) % 100;
		queue[rear] = T;
	}
	while (front != rear) {
		//出队访问
		front = (front + 1) % 100;
		T = queue[front];
		visit(T);  
		
		if (NULL != T->lchild) {
			queue[rear] = T->lchild;
			rear = (rear + 1) % 100;
		}
		
		if (NULL != T->rchild) {
			queue[rear] = T->rchild;
			rear = (rear + 1) % 100; 
		}
	} 
} 
