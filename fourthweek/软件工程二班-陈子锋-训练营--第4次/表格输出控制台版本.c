#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.c"
#define MAXSIZE 100 * 1000


int main(void) 
{	
	int i, j;
	clock_t start, time_1;
	int *a = (int *)malloc(sizeof(int) * MAXSIZE);
	
	printf("100k ��α����� * 100�� �����Ա���������:\n ");
	printf("\n");
	printf("->|-----------------------------------------------------------------------------------------------------|-<\n"); 
	printf("->| ��� |   ���ٷǵݹ�    |   ���ŵݹ�   |   ��������   |   �鲢����   |    ��������   |  ������������ |-<\n"); 
	printf("->|------+-----------------+--------------+--------------+--------------+---------------+---------------|-<\n"); 
	
	for ( i = 1; i <= 100; i++)
	{	//ÿ�ζ�Ҫ����������á� 
		
		//���ŷǵݹ����� 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
	
		start = clock(); 
		Qsort_Recursion(a, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		printf("->|%5d |%8dms\t   |", i, time_1);
		
		//��������ݹ� 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
			
		start = clock(); 
		QSort(a, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		printf("%8dms\t  |", time_1);
			
		//�������� 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
			
		start = clock(); 
		InsertSort(a, MAXSIZE);
		time_1 = clock() - start;
		printf("%8dms\t |", time_1);
			
		//�鲢���� 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
			
		start = clock(); 
		MergeSort(a, 0, MAXSIZE - 1);
		time_1 = clock() - start;  
		printf("%8dms\t|", time_1);
		
		//�������� 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
			
		start = clock(); 
		CountSort(a, MAXSIZE, 100);
		time_1 = clock() - start;
		printf("%8dms\t|", time_1);
		
		//������������ 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
			
		start = clock(); 
		RadixCountSort(a, MAXSIZE , 2);
		time_1 = clock() - start;
		printf("%8dms\t|-<\n", time_1);
		printf("->|------+-----------------+--------------+--------------+--------------+---------------+---------------|-<\n"); 	
	}
	printf("->|-----------------------------------------------------------------------------------------------------|-<\n"); 
	 
	
	system("pause");
	return 0;	
}
