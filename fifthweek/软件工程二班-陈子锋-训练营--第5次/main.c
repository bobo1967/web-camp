#include <stdio.h>
#include "BinaryTree.h" 
#include <stdlib.h>
#include <string.h> 
#include "BinaryTree.c" 


void print() {
	//初始化菜单 
	printf ("\n\n->----------------------------------------------------------------------<-\n");
	printf ("->--------------------------请输入正确的选项----------------------------<-\n");
	printf ("->                                                                      <-\n");
	printf ("->           A.初始化一棵二叉树          B. 构建一棵二叉树              <-\n");
	printf ("->           C.销毁一棵二叉树            D.层序遍历访问                 <-\n");
	printf ("->           E.先序遍历访问              F.中序遍历访问                 <-\n");
	printf ("->           G.后序遍历访问              Q.退出程序                     <-\n");
	printf ("->                                                                      <-\n");
	printf ("->--------------------version: 1.0----by edison-------------------------<-\n");
	printf ("->----------------------------------------------------------------------<-\n\n");
}

int main(void) {
	char choice, flag;
	BiTree T;
	int f = ERROR;//初始化判断符 
	//菜单
	print();
	while (1) {
		scanf("%c", &choice);
		flag = getchar();
		if ((('A' <= choice && choice <= 'Z') || 'q' == choice) && flag == '\n') {
			break;
		}
		else {
			printf("请输入正确的选择：\n");
			fflush(stdin);
		}
	}
	while ('Q' != choice) {
		switch (choice) {
			case 'A' : { //初始化二叉树
				InitBiTree(T);
				f = SUCCESS; 
				printf ("初始化成功！");
				break;
			}
			case 'B' : { //构建一棵二叉树
				if (SUCCESS != f) {
					printf("请先初始化二叉树！\n");
					break; 
				} 
				printf ("\n请输入格式，'#' 代表空树，'A-Z表示结点' \n");
				printf ("推荐格式：ABD##E##C##\n");
				int i = 0;
				char s;
				char *definition = (char *)malloc(sizeof(char));
				while ( ((s = getchar()) != '\n') ) {
					if ((s >= 'A' && s <= 'Z') || '#' == s) {
						definition[i] = s;
						i++;
						definition = (char *)realloc(definition, i * sizeof(char));
					}  else {
						continue;
					}
				}
			
				printf ("\n您输入的格式：\n%s\n", definition);
				CreateBiTree(T, definition);
				printf ("\n构建成功！\n"); 
				break;
			}
			case 'C' : {//销毁一棵二叉树
				if (SUCCESS != f) {
					printf("请先初始化二叉树！\n");
					break; 
				}  else
				if (SUCCESS == DestroyBiTree(T)) {		
					printf ("销毁成功！\n\n");
					break;
				}  else {
					printf("销毁失败！\n");
					//return ERROR;
					break; 
				}
			}
			/*
			case 'c' : {//二叉树求值
				printf ("\n请输入一个前缀表达式，仅支持10以内正整数的四则运算：\n");
				printf ("参考格式：+2*34\n");
				int i = 0;
				char s;
				char *definition = (char *)malloc(sizeof(char));
				while ( (s = getchar()) != '\n' ) {
					if ((s >= '0' && s <= '9') || '+' == s || '-' == s || '*' == s || '/' == s ) {
						definition[i] = s;
						i++;
						definition = (char *)realloc(definition, i * sizeof(char));
					}  else {
						continue;
					}  
				}
				printf ("\n您输入的表达式：\n%s\n", definition);
				 
				break;
			} 
			*/
			case 'D' : { //层序遍历 
				if (SUCCESS != f) {
					printf ("请先初始化二叉树！\n");
					break; 
				}
				if (ERROR == LevelOrderTraverse(T, visit)) {
					printf ("这是一棵空树！\n"); 
					break;
				}
			}
			case 'E' : { //先序遍历 
				if (SUCCESS != f) {
					printf("请先初始化二叉树！\n");
					break; 
				} 
			 	PreOrderTraverse(T, visit);
				break;
			} 
			case 'F' : { //中序遍历 
				if (SUCCESS != f) {
					printf("请先初始化二叉树！\n");
					break; 
				}	
				InOrderTraverse(T, visit);
				break;
			}
			case 'G' : { //后续遍历
				if (SUCCESS != f) {
					printf("请先初始化二叉树！\n");
					break; 
				} 
				PostOrderTraverse(T, visit);
				break;
			}
		}
		
		print();
		while (1) {
			scanf("%c", &choice);
			flag = getchar();
			if ((('A' <= choice && choice <= 'Z') || 'Q' == choice) && flag == '\n') {
				break;
			} else {
				printf ("\n请输入正确的选择：\n");
				fflush(stdin);
				
			}
		}
		
	}
	printf("退出程序成功！");
	return 0; 
} 
