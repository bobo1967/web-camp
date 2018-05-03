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
	char head[6][20] = {"��������ݹ�汾", "��������ǵݹ�汾", "��������",  "�鲢����", "������������", "��������"};
	
	printf("100 * 100k ��α����������ļ���\n");
	
	//��һ�� ���ٵݹ� 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		Qsort_Recursion(num, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		a[i][1] =  time_1;
		printf("�ݹ�������......%3d / 100\n", i + 1);
	}
	//�ڶ��� ���ٷǵݹ� 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		QSort(num, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		a[i][2] =  time_1;
		printf("���ٷǵݹ�������......%3d / 100\n", i + 1);
	}
	//������  �������� 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		InsertSort(num, MAXSIZE);
		time_1 = clock() - start;
		a[i][0] =  time_1;
		printf("����������......%3d / 100\n", i + 1);
	}
	
	//������ �鲢���� 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		MergeSort(num, 0, MAXSIZE - 1);
		time_1 = clock() - start;
		a[i][3] =  time_1;
		printf("�鲢������......%3d / 100\n", i + 1);
	}
	//������ ������������ 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		RadixCountSort(num, MAXSIZE , 2);
		time_1 = clock() - start;
		a[i][4] =  time_1;
		printf("����������......%3d / 100\n", i + 1);
	}
	//������ �������� 
	for(i = 0; i < 100; i++) 
	{	
		for (j = 0; j < MAXSIZE; j++)
			num[j] = rand() % 100;
		start = clock(); 
		CountSort(num, MAXSIZE, 100);
		time_1 = clock() - start;
		a[i][5] =  time_1;
		printf("����������......%3d / 100\n", i + 1);
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
