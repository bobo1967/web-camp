#include <stdio.h>
#include<stdlib.h>

typedef struct stack {
	int top;
	int *elem;
} stack;
/******************************************
                                         
	方法：插入排序

	原理：从第二个数开始和它左边的数字比较 

*******************************************/
void InsertSort(int a[], int n) {
	int i = 0, j = 0, temp = 0; 
	
	for (i = 1; i < n; i++)
	{
		//找到a[i]左边比它大的数 
		if (a[i] < a[i-1])
		{
			temp = a[i];
			//将a[i] 和 比 左边他大的数交换位置 
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
				a[j+1] = a[j];
			a[j+1] = temp;
		}
	}
	 
}

/************************************************ 

	方法：归并排序
	
	原理：拆分为长度为1或者2的表，排序表然后合并 
 
************************************************/
void Merge(int *a, int low, int mid, int high) {
	int i = low, j = mid + 1, p = 0;
	//开辟一个同等大小的临时数组 
	int *b = (int *)malloc((high - low + 1) * sizeof(int));
	while (i <= mid && j <= high)
	{	//排序操作 
		if (a[i] <= a[j]) 
			b[p++] = a[i++];
		else 
			b[p++] = a[j++]; 	
	} 

	while (i <= mid)
		b[p++] = a[i++];
		
	while (j <= high)
		b[p++] = a[j++];
	//赋值给原数组 
	for (i = 0; i < p; i++)
		a[low + i] = b[i];
	
	free(b);
} 


void MergeSort(int *a, int low, int high) {
	//从上往下划分表 
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low , mid ,high);
	}
}
/***************************************************** 

	方法：快速排序 非递归版本
	
	原理： 将比枢轴大的数放在其右边，小的数放在其左边 
 	
******************************************************/ 
int push(stack *s, int value, int size) {
	if (s->top < size) {
		s->elem[s->top] = value;
		s->top++;
		return s->top;
	} else {
		return -1;
	} 
}

int pop(stack *s) {
	if (0 == s->top)
		return -1;
	else {
		int temp = s->elem[s->top - 1];
		s->top--;
		return temp;
	}	
}

void QSort(int a[], int low, int high) {
	int middle;
	int size = high- low + 1;
	
	//建立一个简单的栈 
	stack s;
	s.elem = (int *)malloc(sizeof(int) * size);
	s.top = 0;
	
	if (low < high)
	{
		middle = Partition(a, low, high);
		if (low < middle - 1)//如果middle - 1 == low，middle左边有序 
		{
			push(&s, low, size);
			push(&s, middle - 1, size);
		}
		if (middle + 1 < high) //如果middle + 1 == high，middle右边有序 
		{
			push(&s, middle + 1, size);
			push(&s, high, size);
		}
		while (0 < s.top)
		{
			int high2 = pop(&s);
			int low2 = pop(&s);
			middle = Partition(a, low2 , high2);
			if (low2 < middle - 1)
			{
				push(&s, low2, size);
				push(&s, middle - 1, size);
			}
			if (middle + 1 < high2)
			{
				push(&s, middle + 1, size);
				push(&s, high2, size);
			}
		}
	}
}

/***************************************************** 
	
	方法：快速排序 递归版本
	
	原理： 将比枢轴大的数放在其右边，小的数放在其左边
		
*****************************************************/ 
 
int Partition(int a[], int first, int last) {
	int  temp;
	int i = first, j = last;
 	//假设a[0] 为枢轴 
	while (i < j)
	{
	
		//从最右边开始，找到比枢轴小的值 
		while ( (i < j) && (a[i] < a[j]) )
			j--;
		//如果找到了，就交换位置，没找到证明枢轴右边的数都比枢轴大 
		if (i < j) 
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; 
			//此时第一个数已经比枢轴小，在枢轴的左边了 
		}
	 
		//此时枢轴是a[j]，从左边开始找到比枢轴大的值 
		while ( (i < j) && (a[i] <= a[j]) ) 
			i++;
		//如果找到了就交换位置 
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j--;//向前移一位 
		} 
	}
	//直到枢轴的左边的数字都比它小，右边的数都比它大。返回i == j，即是枢轴的位置 
	return i;
}

void Qsort_Recursion(int a[], int first, int last)  {
	int middle;
	
	if (first < last)
	{
		middle = Partition(a, first, last);
		Qsort_Recursion(a, first, middle-1);
		Qsort_Recursion(a, middle+1, last);
	}	
}
/************************************************** 
 
	方法：计数排序
	
	原理：利用一个辅助数组统计，无需比较大小 
	 
***************************************************/ 
void CountSort(int a[], int n, int max) {
	int *b = (int *)malloc(sizeof(int) * max);//max为假设随机序列的最大值 
	int *new = (int *)malloc(sizeof(int) * n);
	if (b == NULL || new == NULL)
		return;
	int i;
	
	//初始化数组
	for (i = 0; i < max; i++)
		b[i] = 0;
	//统计a[]中每个元素出现的次数
	for (i = 0; i < n; i++)
		b[a[i]]++;
	
	//每个元素都是有序的了，加上前面所有元素就可以得出位置 
	for (i = 1; i < max; i++)
		b[i] += b[i-1];
	//逆向填充 
	for (i = n - 1; i >= 0; i--)
	{
		new[--b[a[i]]] = a[i];
	}
	 
	for (i = 0; i < n; i++)
		a[i] = new[i];
	free(b);
	free(new);
}	


/***************************************************** 

	方法：基数计数排序
	
	原理：用一个二维数组来统计，对每一位进行计数排序	  
		    
******************************************************/
//求从低到高的第pos位的数 
int getBit(int num, int pos) {
	int temp = 1;
	int i;
	for (i = 0; i < pos - 1; i++)
		temp *= 10;
	return (num / temp) % 10;
} 

void RadixCountSort(int *a, int n, int bit) {
	int i, j, k, pos;
	int *bucket[10];
	for (i = 0; i < 10; i++) 
	{
		bucket[i] = (int *)malloc(sizeof(int) * (n + 1));
		bucket[i][0] = 0; //第一列的桶用来计数 
	}
	
	for ( pos = 1; pos <= bit; pos++)// bit是位数 
	{
		for (i = 0; i < n; i++)
		{
			int num = getBit(a[i], pos);
			int index = ++bucket[num][0];
			bucket[num][index] = a[i];	//往右填充数字 
		} 	
		for (i = 0, j = 0; i < 10; i++)
		{
			for ( k = 1; k <= bucket[i][0]; k++)//出桶 
				a[j++] = bucket[i][k];
			bucket[i][0] = 0;//复位 
		}
	} 
}



