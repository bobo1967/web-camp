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
	printf("->---------------��ѡ����Ҫ���Ե�����--------------<-\n");
	printf("->                                                -<-\n"); 
	printf("->   a.��������ǵݹ�汾     b.��������ݹ�汾  -<-\n");
	printf("->   c.��������               d.��������          -<-\n");
	printf("->   e.������������           f.�鲢����          -<-\n");
	printf("->   q.�˳�����                                   -<-\n");
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
            printf("��������ȷ��ѡ��\n");
        fflush(stdin);
	}
	while ('q' != choice) {
		//�������� 
		for (i = 0; i < MAXSIZE; i++)
			a[i] = rand() % 100;
		switch (choice) {
			case 'a': {//���ŷǵݹ�
				printf("ԭ���У�\n"); 
				print(a, MAXSIZE);
				QSort(a, 0, MAXSIZE - 1);
				printf("���ŷǵݹ����������У�\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'b': {//���ŵݹ� 
				printf("ԭ���У�\n"); 
				print(a, MAXSIZE);
				Qsort_Recursion(a, 0, MAXSIZE - 1);
				printf("���ŵݹ����������У�\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'c': {//�������� 
				printf("ԭ���У�\n"); 
				print(a, MAXSIZE);
				InsertSort(a, MAXSIZE); 
				printf("�������������У�\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'd': {//�������� 
				printf("ԭ���У�\n"); 
				print(a, MAXSIZE);
				CountSort(a, MAXSIZE, 100); 
				printf("�������������У�\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'e': {//������������ 
				printf("ԭ���У�\n"); 
				print(a, MAXSIZE);
				RadixCountSort(a, MAXSIZE, 2);
				printf("���������У�\n"); 
				print(a, MAXSIZE); 
				break;
			}
			case 'f': {//�鲢���� 
				printf("ԭ���У�\n"); 
				print(a, MAXSIZE);
				MergeSort(a, 0 , MAXSIZE - 1);
				printf("�鲢���������У�\n"); 
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
            	printf("��������ȷ��ѡ��\n");
        	fflush(stdin);
		}
		
	}

		
	return 0;	
}
