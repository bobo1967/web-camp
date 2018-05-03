#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.c"
#define MAXSIZE 100 * 1000




int main(void) 
{	
	clock_t start, time_1;
	int *num = (int *)malloc(sizeof(int) * MAXSIZE);
	
	int a[100][6];
	int i, j;
	char head[6][20] = {"快速排序递归版本", "快速排序非递归版本", "插入排序",  "归并排序", "基数计数排序", "计数排序"};
	
	printf("100 * 100k 个伪随机数排序文件版\n");
	
	//第一列 快速递归 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		Qsort_Recursion(num, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		a[i][1] =  time_1;
		printf("递归排序中......%3d / 100\n", i + 1);
	}
	//第二列 快速非递归 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		QSort(num, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		a[i][2] =  time_1;
		printf("快速非递归排序中......%3d / 100\n", i + 1);
	}
	//第三列  插入排序 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		InsertSort(num, MAXSIZE);
		time_1 = clock() - start;
		a[i][0] =  time_1;
		printf("插入排序中......%3d / 100\n", i + 1);
	}
	
	//第四列 归并排序 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		MergeSort(num, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		a[i][3] =  time_1;
		printf("归并排序中......%3d / 100\n", i + 1);
	}
	//第五列 基数计数排序 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		RadixCountSort(num, MAXSIZE , 2);
		time_1 = clock() - start;
		a[i][4] =  time_1;
		printf("基数排序中......%3d / 100\n", i + 1);
	}
	//第六列 计数排序 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		CountSort(num, MAXSIZE, 100);
		time_1 = clock() - start;
		a[i][5] =  time_1;
		printf("计数排序中......%3d / 100\n", i + 1);
	}
	
	FILE *fp = NULL;
	fp = fopen("sort.xls", "w");
	for (i = 0; i < 6; i++)
		fprintf(fp, "%s\t", head[i]);
	fprintf(fp, "\n");
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 6; j++)
			fprintf(fp,"%d ms\t", a[i][j]);
		fprintf(fp,"\n");		
	}
	fclose(fp);
	

			

	
	system("pause");
	return 0;	
}
