

typedef struct stack {
	int top;
	int *elem;
} stack;
/************** 

	��������
 
**************/
void InsertSort(int a[], int n) {
	int i = 0, j = 0, temp = 0;
	//clock_t start = clock();
	
	for (i = 1; i < n; i++)
	{
		//�����һ��������ǰһ���������Ѿ������� 
		if (a[i] < a[i-1])
		{//��ǰ��������ƣ�a[i]����
			temp = a[i];
			//ѭ����ߵ����У�ֱ���ҵ���a[i]С��������a[i]������������ұ� 
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
				a[j+1] = a[j];
			a[j+1] = temp;
		}
	}
	/*
	printf("�������������У�\n"); 
	for (i = 0; i < 10; i++)
		printf("%d < ", a[i]);
	*/
	//clock_t diff = clock() - start; 
	//printf("���������������ʱ��%lf s\n", (double)diff / 1000); 
}


/*****************

	�鲢����
 
*****************/
void Merge(int *a, int low, int mid, int high) {
	int i = low, j = mid + 1, p = 0;
	//����һ��ͬ�ȴ�С����ʱ���� 
	int *b = (int *)malloc((high - low + 1) * sizeof(int));
	while (i < mid && j <= high)
	{
		if (a[i] <= a[j]) 
			b[p++] = a[i++];
		else 
			b[p++] = a[j++]; 	
	} 

	while (i <= mid)
		b[p++] = a[i++];
		
	while (j <= high)
		b[p++] = a[j++];
	
	for (p = 0, i = low; i <= high;p++, i++)
		a[i] = b[p];

} 


void MergeSort(int *a, int low, int high) {
	//���η� 
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low , mid ,high);
	}
}
/*****************

	��������
 	�ǵݹ�汾 
 	
*****************/ 
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
	
	//����һ���򵥵�ջ 
	stack s;
	s.elem = (int *)malloc(sizeof(int) * size);
	s.top = 0;
	
	if (low < high)
	{
		middle = Partition(a, low, high);
		if (low < middle - 1)
		{
			push(&s, low, size);
			push(&s, middle - 1, size);
		}
		if (middle + 1 < high)
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

/*****************
	
	�������� 
	�ݹ�汾
	
*****************/ 
//�����㷨 
int Partition(int a[], int first, int last) {
	int  temp;
	int i = first, j = last;
	//�������ᣬһ�λ����㷨�� 
	while (i < j)
	{
		//�����Ҳ�����
		//��ĩβ��ʼ��ǰѰ��ֱ���ҵ���ӽ���ͷһ����ĩβ���ֵ 
		while ( (i < j) && (a[i] < a[j]) )
			j--;
		//����ҵ��ˣ��ͽ���λ�� 
		if (i < j) 
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;//�����һλ 
		}
		//������������ 
		//�ҵ���ӽ�ĩβһ����ͷԪ��С��ֵ 
		while ( (i < j) && (a[i] <= a[j]) ) 
			i++;
		//����ҵ��˾ͽ���λ�� 
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j--;//��ǰ��һλ 
		} 
	} 
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
/****************** 
�������� 
******************/ 
void CountSort(int a[], int n, int max) {
	int *b = (int *)malloc(sizeof(int) * max);//maxΪ����������е����ֵ 
	int *new = (int *)malloc(sizeof(int) * n);
	if (b == NULL || new == NULL)
		return;
	int i;
	
	//��ʼ������
	for (i = 0; i < max; i++)
		b[i] = 0;
	//ͳ��a[]��ÿ��Ԫ�س��ֵĴ���
	for (i = 0; i < n; i++)
		b[a[i]]++;
	
	//ÿ��Ԫ�ض���������ˣ�����ǰ������Ԫ�ؾͿ��Եó�λ�� 
	for (i = 1; i < max; i++)
		b[i] += b[i-1];
	//������� 
	for (i = n - 1; i >= 0; i--)
	{
		new[--b[a[i]]] = a[i];
	}
	 
	for (i = 0; i < n; i++)
		a[i] = new[i];
	free(b);
	free(new);
}	


/****************** 

	������������
	 	   
******************/
//��ӵ͵��ߵĵ�posλ���� 
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
		bucket[i][0] = 0; //��һ�е�Ͱ�������� 
	}
	
	for ( pos = 1; pos <= bit; pos++)// bit��λ�� 
	{
		for (i = 0; i < n; i++)
		{
			int num = getBit(a[i], pos);
			int index = ++bucket[num][0];
			bucket[num][index] = a[i];	//����Խ��λ��Խ���� 
		} 	
		for (i = 0, j = 0; i < 10; i++)
		{
			for ( k = 1; k <= bucket[i][0]; k++)//��Ͱ 
				a[j++] = bucket[i][k];
			bucket[i][0] = 0;//��λ 
		}
	} 
}



