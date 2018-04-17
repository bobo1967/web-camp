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
			*last -= '0'; //转换为整形 
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
	|	'(' 		的优先级是 -1 	|
	|	'+', '-' 	的优先级是 	0 	|
	|	'*', '/' 	的优先级是	1 	|
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
			//如果是数字直接输出
		} 
		if ('-' == *mid || '+' == *mid || '*' == *mid || '/'  == *mid || ')' == *mid || '(' == *mid )
		{	
			if ('(' == *mid || 0 == s.count) 
			{	//如果是左括号或者是空栈符号直接入栈 
				pushLStack(&s, *(mid++));
				continue;
			}
			if (')' == *mid)
			{	//如果是右括号，会把第一个左括号之前的符号弹栈输出，把左括号弹栈但不输出 
				while (OK == popLStack(&s, &e) && '(' != e) 	
					*(last++) = e;
				mid++;
				continue;				
			}
			/*
			接下来要用栈顶元素和符号比较，如果栈顶元素的优先级大于或者等于该字符，
			则出栈，该字符入栈  
			*/	
			popLStack(&s, &e);//弹出临时栈顶元素 
			if ('-' == *mid || '+' == *mid)
			{	//如果符号是加号或者减号 
				if ('(' == e)
				{	//如果是栈顶元素是左括号，则继续压栈 
					pushLStack(&s,'(');
					pushLStack(&s, *(mid++));
					continue;
				}
				else   
				{	//持续弹栈输出优先级高的元素，再把符号压栈 
					*(last++) = e;
					while (OK == popLStack(&s, &e) && '(' != e);//持续弹栈输出直到栈顶元素是左括号或者到了栈尾 
					{
						*(last++) = e;
					}
					if (e == '(') //判断是否是左括号，是则压回去 
						pushLStack(&s, e);
					pushLStack(&s, *(mid++));
					continue;
				} 
			}   
			if ('*' == *mid || '/' == *mid) 
			{	//符号是乘号或者除号，乘除的优先级最高。 
				if ('*' == e || '/' == e)
		   		{ 	 //同优先级符号，替换 
					*(last++) = e;
					pushLStack(&s, *(mid++));
					continue;
				}
				else 
				{	//比栈顶元素优先级高，压栈 
					pushLStack(&s, e);
					pushLStack(&s, *(mid++));
					continue; 
				}
			}	
		}
	}
	//把栈剩余的符号弹出  
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
	printf ("中缀表达式：\n%s\n", mid);
	change(mid, last);
	printf ("after change:\n");
	printf ("\n后缀表达式：\n%s\n", last);
	printf ("\n四则运算结果：%d\n", result(last));
	getchar(); 
	return 0;
}
