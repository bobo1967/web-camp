#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.c"
#define MAXSIZE_1 10000
#define MAXSIZE_2 50000 
#define MAXSIZE_3 200000

int main(void) 
{	
	int i, j;
	clock_t start, diff;

	//���ֲ�ͬ���������������ʱ
	clock_t time_1;
	int size;
	
	for ( i = 0; i < 3; i++)
	{	//����n��100�ڵ�α�����
		printf("->->-------------------------------------------------------------------<-<\n"); 
		if ( 0 == i) {
			size = MAXSIZE_1;
			printf("->----------------------������Ϊ 10000�������---------------------------<\n");
		}	else if ( 1 == i) {
			size = MAXSIZE_2;
			printf("->----------------------������Ϊ 50000�������---------------------------<\n");
		}	else if (2 == i){
			size = MAXSIZE_3;
			printf("->----------------------������Ϊ200000�������---------------------------<\n");
		}
		int *a = (int *)malloc(sizeof(int) * size);
		
			
		//���ŷǵݹ�
		for (j = 0; j < size; j++)
			a[j] = rand() % 100;	
		start = clock(); 
		Qsort_Recursion(a, 0, size - 1);
		time_1 = clock() - start;
		printf("->\tʹ�ÿ���(�ݹ�)����%8d��������Ҫ��ʱ�䣺%10dms\t-<\n",size, time_1);
		//���ŵݹ�
		for (j = 0; j < size; j++)
			a[j] = rand() % 100; 
		start = clock(); 
		QSort(a, 0, size - 1);
		time_1 = clock() - start;
		printf("->\tʹ�ÿ���(�ǵݹ�)����%6d��������Ҫ��ʱ�䣺%10dms\t-<\n",size, time_1);
		//��������
		for (j = 0; j < size; j++)
			a[j] = rand() % 100;	
		start = clock(); 
		InsertSort(a, size);
		time_1 = clock() - start;
		printf("->\tʹ�ò�����������  %8d��������Ҫ��ʱ�䣺%10dms\t-<\n",size, time_1);
		//�鲢���� 
		for (j = 0; j < size; j++)
			a[j] = rand() % 100;
		start = clock(); 
		MergeSort(a, 0, size - 1);
		time_1 = clock() - start;  
		printf("->\tʹ�ù鲢��������  %8d��������Ҫ��ʱ�䣺%10dms\t-<\n",size, time_1);
		//������������
		for (j = 0; j < size; j++)
			a[j] = rand() % 100; 
		start = clock(); 
		RadixCountSort(a, size, 2); 
		time_1 = clock() - start;  
		printf("->\tʹ�û�����������  %8d��������Ҫ��ʱ�䣺%10dms\t-<\n",size, time_1);
		//�������� 
		for (j = 0; j < size; j++)
			a[j] = rand() % 100;
		start = clock(); 
		CountSort(a, size, 100); 
		time_1 = clock() - start;  
		printf("->\tʹ�ü�����������  %8d��������Ҫ��ʱ�䣺%10dms\t-<\n",size, time_1);
		free(a); 
	}
	printf("->->-------------------------------------------------------------------<-<\n"); 
	
	
	system("pause");
	return 0;	
}
