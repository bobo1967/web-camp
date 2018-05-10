#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct {
   TElemType *elem;     // 0�ŵ�Ԫ����
   int lastIndex;              // ���������һ�����ı��
} SqBiTree;    // ˳��洢�Ķ�����

typedef struct  BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������

typedef enum Status{
	SUCCESS,
	ERROR
} Status;


Status InitBiTree(BiTree *T);
//�������������ն�����T
Status DestroyBiTree(BiTree *T);
//��ʼ������������T����
//����������ݻٶ�����T
Status CreateBiTree(BiTree T, char* definition);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T


//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTree T, void visit(BiTree p));
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTree T, void visit(BiTree p));	//�������
Status PostOrderTraverse(BiTree T, void visit(BiTree p));	//�������
Status LevelOrderTraverse(BiTree T, void (*foo)());	//�������
double Value(BiTree T);			//������Ķ�������ֵ

void visit(BiTree p);

/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/

#endif
