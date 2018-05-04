#include <stdio.h>
#include <stdlib.h>

#include "sort.c"
#define MAXSIZE 20

void print(int a[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf(" <%d> ", a[i]);
	printf("\n");
}

void menu() {
	printf("\n->-------------------------------------------------<-\n");
	printf("->---------------请选择你要测试的排序--------------<-\n");
	printf("->                                                -<-\n"); 
	printf("->   a.快速排序非递归版本     b.快速排序递归版本  -<-\n");
	printf("->   c.插入排序               d.计数排序          -<-\n");
	printf("->   e.基数计数排序           f.归并排序          -<-\n");
	printf("->   q.退出程序                                   -<-\n");
	printf("->                                                -<-\n"); 
	printf("->-------------------------------------------------<-\n");
	printf("\n");
}

int main(void) 
{	
	char choice, flag;
	int a[20];
	int i;
	menu();
	
	while (1) {
        scanf("%c", &choice);
        flag = getchar();
        if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ||'e' == choice
            ||'f' == choice || 'q' == choice) && '\n' == flag)
            break;
        else
            printf("请输入正确的选择！\n");
        fflush(stdin);
	}
	while ('q' != choice) {
		//重置数列 
		for (i = 0; i < MAXSIZE; i++)
			a[i] = rand() % 100;
		switch (choice) {
			case 'a': {//快排非递归
				printf("原数列：\n"); 
				print(a, MAXSIZE);
				QSort(a, 0, MAXSIZE - 1);
				printf("快排非递归排序后的数列：\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'b': {//快排递归 
				printf("原数列：\n"); 
				print(a, MAXSIZE);
				Qsort_Recursion(a, 0, MAXSIZE - 1);
				printf("快排递归排序后的数列：\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'c': {//插入排序 
				printf("原数列：\n"); 
				print(a, MAXSIZE);
				InsertSort(a, MAXSIZE); 
				printf("插入排序后的数列：\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'd': {//计数排序 
				printf("原数列：\n"); 
				print(a, MAXSIZE);
				CountSort(a, MAXSIZE, 100); 
				printf("计数排序后的数列：\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'e': {//基数基数排序 
				printf("原数列：\n"); 
				print(a, MAXSIZE);
				RadixCountSort(a, MAXSIZE, 2);
				printf("排序后的数列：\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'f': {//归并排序 
				printf("原数列：\n"); 
				print(a, MAXSIZE);
				MergeSort(a, 0 , MAXSIZE - 1);
				printf("归并排序后的数列：\n"); 
				print(a, MAXSIZE); 
				break;
			}
		}
				
		menu();
		while (1) {
        	scanf("%c", &choice);
        	flag = getchar();
        	if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ||'e' == choice ||'f' == choice || 'q' == choice ) && '\n' == flag)
            	break;
        	else
            	printf("请输入正确的选择！\n");
        	fflush(stdin);
		}
		
	}

		
	return 0;	
}
