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
	
	printf("100k 个伪随机数 * 100次 排序以表格形似输出:\n ");
	printf("\n");
	printf("->|-----------------------------------------------------------------------------------------------------|-<\n"); 
	printf("->| 序号 |   快速非递归    |   快排递归   |   插入排序   |   归并排序   |    计数排序   |  基数计数排序 |-<\n"); 
	printf("->|------+-----------------+--------------+--------------+--------------+---------------+---------------|-<\n"); 
	
	for ( i = 1; i <= 100; i++)
	{	//每次都要将随机数重置。 
		
		//快排非递归排序 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
	
		start = clock(); 
		Qsort_Recursion(a, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		printf("->|%5d |%8dms\t   |", i, time_1);
		
		//快速排序递归 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
			
		start = clock(); 
		QSort(a, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		printf("%8dms\t  |", time_1);
			
		//插入排序 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
			
		start = clock(); 
		InsertSort(a, MAXSIZE);
		time_1 = clock() - start;
		printf("%8dms\t |", time_1);
			
		//归并排序 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
			
		start = clock(); 
		MergeSort(a, 0, MAXSIZE - 1);
		time_1 = clock() - start;  
		printf("%8dms\t|", time_1);
		
		//计数排序 
		for (j = 0; j < MAXSIZE; j++)
			a[j] = rand() % 100;
			
		start = clock(); 
		CountSort(a, MAXSIZE, 100);
		time_1 = clock() - start;
		printf("%8dms\t|", time_1);
		
		//基数计数排序 
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
