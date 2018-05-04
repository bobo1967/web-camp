#include <stdio.h>
#include <string.h>

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

void print(int *a, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("<%d>", a[i]);
	printf("\n"); 
}

void sortColor(int *color, int size) {
	int p2 = size - 1; //ָ��2��ָ�� 
	int p0 = 0; //ָ��0��ָ�� 
	int i; 

	for (i = 0 ; i <= p2; i++)
	{
		
		if (color[i] == 2)
		{	
			 
			swap(&color[p2], &color[i]);
			p2--;
			i--;//�ٴ��ж� 
		}
		else if (color[i] == 0)
		{
			swap(&color[p0], &color[i]);
			p0++;
		}
	}
	printf("�����\n");
	print(color, size);
}

int main(void) 
{
	int a[] = {0, 1, 0, 2, 0, 1, 1, 2}; 
	int b[] = {1, 2, 0, 1, 0, 1, 2, 2, 0};
	int c[] = {2, 1, 0, 1, 1, 2, 0, 1, 1, 2, 0, 1};
	
	
	printf("����ǰ��\n");
	print(a, sizeof(a) / sizeof(int) );
	sortColor(a, sizeof(a) / sizeof(int) );
	printf("����ǰ��\n");
	print(b, sizeof(b) / sizeof(int) );
	sortColor(b, sizeof(b) / sizeof(int) ) ;
	printf("����ǰ��\n");
	print(c, sizeof(c) / sizeof(int) );
	sortColor(c, sizeof(c) / sizeof(int) );
	
	
	system("pause");
	return 0;	
} 
