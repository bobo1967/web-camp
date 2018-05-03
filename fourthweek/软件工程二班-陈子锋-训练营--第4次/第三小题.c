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

	//三种不同的数据量的输出用时
	clock_t time_1;
	int size;
	
	for ( i = 0; i < 3; i++)
	{	//生成n个100内的伪随机数
		printf("->->-------------------------------------------------------------------<-<\n"); 
		if ( 0 == i) {
			size = MAXSIZE_1;
			printf("->----------------------数据量为 10000的情况：---------------------------<\n");
		}	else if ( 1 == i) {
			size = MAXSIZE_2;
			printf("->----------------------数据量为 50000的情况：---------------------------<\n");
		}	else if (2 == i){
			size = MAXSIZE_3;
			printf("->----------------------数据量为200000的情况：---------------------------<\n");
		}
		int *a = (int *)malloc(sizeof(int) * size);
		
			
		//快排非递归
		for (j = 0; j < size; j++)
			a[j] = rand() % 100;	
		start = clock(); 
		Qsort_Recursion(a, 0, size - 1);
		time_1 = clock() - start;
		printf("->\t使用快排(递归)排序%8d个数字需要的时间：%10dms\t-<\n",size, time_1);
		//快排递归
		for (j = 0; j < size; j++)
			a[j] = rand() % 100; 
		start = clock(); 
		QSort(a, 0, size - 1);
		time_1 = clock() - start;
		printf("->\t使用快排(非递归)排序%6d个数字需要的时间：%10dms\t-<\n",size, time_1);
		//插入排序
		for (j = 0; j < size; j++)
			a[j] = rand() % 100;	
		start = clock(); 
		InsertSort(a, size);
		time_1 = clock() - start;
		printf("->\t使用插入排序排序  %8d个数字需要的时间：%10dms\t-<\n",size, time_1);
		//归并排序 
		for (j = 0; j < size; j++)
			a[j] = rand() % 100;
		start = clock(); 
		MergeSort(a, 0, size - 1);
		time_1 = clock() - start;  
		printf("->\t使用归并排序排序  %8d个数字需要的时间：%10dms\t-<\n",size, time_1);
		//基数计数排序
		for (j = 0; j < size; j++)
			a[j] = rand() % 100; 
		start = clock(); 
		RadixCountSort(a, size, 2); 
		time_1 = clock() - start;  
		printf("->\t使用基数排序排序  %8d个数字需要的时间：%10dms\t-<\n",size, time_1);
		//计数排序 
		for (j = 0; j < size; j++)
			a[j] = rand() % 100;
		start = clock(); 
		CountSort(a, size, 100); 
		time_1 = clock() - start;  
		printf("->\t使用计数排序排序  %8d个数字需要的时间：%10dms\t-<\n",size, time_1);
		free(a); 
	}
	printf("->->-------------------------------------------------------------------<-<\n"); 
	
	
	system("pause");
	return 0;	
}
