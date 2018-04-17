#include <stdio.h>
#include "stack.c"
#include <stdlib.h>

int result(char *last)
{
	int temp = 0;
	char p ,q;
	char a; 
	
	LinkStack s;
	initLStack(&s);	
	
	while (*last) {
		if (*last >= '0' && *last <= '9') {
			*last -= '0'; //ת��Ϊ���� 
			pushLStack(&s, *(last++));
			continue;
		}
		else {
			popLStack(&s, &p);
			popLStack(&s, &q);
			switch (*last) {
				case '-':	temp = q - p; break;
				case '+':	temp = q + p; break;
				case '*':	temp = q * p; break;
				case '/':	temp = q / p; break;
			}
			pushLStack(&s, temp);
		}
		last++;
	}
	popLStack(&s, &a);
	return (a);
}

void change(char *mid, char *last)
{
	/********************************
	|	'(' 		�����ȼ��� -1 	|
	|	'+', '-' 	�����ȼ��� 	0 	|
	|	'*', '/' 	�����ȼ���	1 	|
	********************************/		
	char e;
	LinkStack s;
	initLStack(&s);
	
	
	while (*mid)
	{
		if (*mid >= '0' && *mid <= '9')
		{
			*(last++) = *(mid++);
			continue;
			//���������ֱ�����
		} 
		if ('-' == *mid || '+' == *mid || '*' == *mid || '/'  == *mid || ')' == *mid || '(' == *mid )
		{	
			if ('(' == *mid || 0 == s.count) 
			{	//����������Ż����ǿ�ջ����ֱ����ջ 
				pushLStack(&s, *(mid++));
				continue;
			}
			if (')' == *mid)
			{	//����������ţ���ѵ�һ��������֮ǰ�ķ��ŵ�ջ������������ŵ�ջ������� 
				while (OK == popLStack(&s, &e) && '(' != e) 	
					*(last++) = e;
				mid++;
				continue;				
			}
			/*
			������Ҫ��ջ��Ԫ�غͷ��űȽϣ����ջ��Ԫ�ص����ȼ����ڻ��ߵ��ڸ��ַ���
			���ջ�����ַ���ջ  
			*/	
			popLStack(&s, &e);//������ʱջ��Ԫ�� 
			if ('-' == *mid || '+' == *mid)
			{	//��������ǼӺŻ��߼��� 
				if ('(' == e)
				{	//�����ջ��Ԫ���������ţ������ѹջ 
					pushLStack(&s,'(');
					pushLStack(&s, *(mid++));
					continue;
				}
				else   
				{	//������ջ������ȼ��ߵ�Ԫ�أ��ٰѷ���ѹջ 
					*(last++) = e;
					while (OK == popLStack(&s, &e) && '(' != e);//������ջ���ֱ��ջ��Ԫ���������Ż��ߵ���ջβ 
					{
						*(last++) = e;
					}
					if (e == '(') //�ж��Ƿ��������ţ�����ѹ��ȥ 
						pushLStack(&s, e);
					pushLStack(&s, *(mid++));
					continue;
				} 
			}   
			if ('*' == *mid || '/' == *mid) 
			{	//�����ǳ˺Ż��߳��ţ��˳������ȼ���ߡ� 
				if ('*' == e || '/' == e)
		   		{ 	 //ͬ���ȼ����ţ��滻 
					*(last++) = e;
					pushLStack(&s, *(mid++));
					continue;
				}
				else 
				{	//��ջ��Ԫ�����ȼ��ߣ�ѹջ 
					pushLStack(&s, e);
					pushLStack(&s, *(mid++));
					continue; 
				}
			}	
		}
	}
	//��ջʣ��ķ��ŵ���  
	while (0 != s.count)
	{
		popLStack(&s, &e);
		*(last++) = e;
	} 
	*last = '\0';
	return;
}

int main(void) 
{	
	char mid[] = "6+(4-2)*3+9/3"; 
	char last[] = {};	
	printf ("��׺���ʽ��\n%s\n", mid);
	change(mid, last);
	printf ("after change:\n");
	printf ("\n��׺���ʽ��\n%s\n", last);
	printf ("\n������������%d\n", result(last));
	getchar(); 
	return 0;
}
