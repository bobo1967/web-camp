#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack.c"
#include <ctype.h>
#include <string.h>

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}


void shuchu() {
	printf("\t\t\t   ________________________________________________________\n");
    printf("\t\t\t   |--->now  input the char to choose the function:   <---|\n");
	printf("\t\t\t   |--->     a.判断链表是否为空                       <---|\n");
	printf("\t\t\t   |--->     b.入栈                                   <---|\n");
	printf("\t\t\t   |--->     c.出栈                                   <---|\n");
	printf("\t\t\t   |--->     d.得到链表头元素                         <---|\n");
	printf("\t\t\t   |--->     e.检测链表长度                           <---|\n");
	printf("\t\t\t   |--->     f.清空链表                               <---|\n");
	printf("\t\t\t   |--->     g.销毁链表                               <---|\n");
	printf("\t\t\t   |--->     q.结束程序                               <---|\n");
	printf("\t\t\t   |______________________________________________________|\n\n");
}
void stack(SqStack *s) {
	shuchu();
	ElemType data;
	char flag, choice;

    while (1) {
        scanf("%c", &choice);
        flag = getchar();
        if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ||'e' == choice
            ||'f' == choice || 'g' == choice || 'q' == choice) && '\n' == flag)
            break;
        else
            printf("请输入正确的选择！\n");
        eatline();
	}
	while('q' != choice) {
		switch (choice) {
			case 'a': {//***************判断链表是否为空***************
				if (isEmptyStack(s)) {
			  		printf("当前链表为空\n");
			    	shuchu();
				} else
					printf("当前链表存在\n");
				break;
			}
			case 'b': {//***************入栈***************
				printf("现在输入你想要压入的数字:\n");
				while(!scanf("%d", &data)) {
                    printf("请输入正确的数字，输入0退出程序\n");
                    eatline();
				}
				eatline();
				if (OK == pushStack(s, data)) {
                    shuchu();
					printf("压入成功\n");
					break;
				} else
					printf("栈已满,压入失败\n");
				break;
			}
			case 'c': {//***************出栈***************
				if (OK == popStack(s, &data)) {
				 	printf("出栈成功,出栈的元素为%d\n", data);
				    shuchu();
	            } else
					printf("链表为空,出栈失败");
					break;
			}
			case 'd': {//***************得到栈头元素***************
		        if(getTopStack(s, &data)) {
					printf("链表头元素为%d\n", data);
				}  else
					printf("链表为空\n");
				    break;
			}
			case 'e': {//***************检测链表长度***************
				stackLength(s, &data);
				printf("当前链表长度为%d\n", ++data);
				break;
			}
			case 'f': {//***************清空链表***************
				if(clearStack(s)) {
					printf("清空完成\n");
				} else printf("链表已为空\n");
					 break;
         	}
			case 'g': {//***************销毁链表***************
			    if(destoryStack(s)) {
					printf("销毁成功\n");
	         		return;
				} else ("链表已为空\n");
					break;
			}
		}
		while (1) {
            scanf("%c", &choice);
            flag = getchar();
            if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ||'e' == choice
                ||'f' == choice || 'g' == choice || 'q' == choice) && '\n' == flag)
            break;
            else
                printf ("请输入正确的选择！\n");
            eatline();
        }
	}
	return;
}
void lstack(LinkStack *s) {
    shuchu();
    ElemType data;
    char flag, choice;

    while (1) {
        scanf("%c", &choice);
        flag = getchar();
        if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ||'e' == choice
            ||'f' == choice || 'g' == choice || 'q' == choice) && '\n' == flag)
            break;
        else
            printf ("请输入正确的选择！\n");
        eatline();
	}
	while('q' != choice) {
		switch (choice) {
			case 'a': {//***************判断链表是否为空***************
				if (isEmptyLStack(s)) {
			  		printf("当前栈为空\n");
			    	shuchu();
				} else
					printf("当前栈存在\n");
				break;
			}
			case 'b': {//***************入栈***************
				printf("请输入你想要压入的数字:\n");
				while(!scanf("%d", &data)) {
                    printf("请输入正确的数字，输入0退出程序\n");
                eatline();
                }
				eatline();
				if (OK == pushLStack(s, data)) {
					printf("入栈成功\n");
					shuchu();
				} else
					printf("栈已满,压入失败\n");
				break;
			}
			case 'c': {//***************出栈***************
				if (OK == popLStack(s, &data)) {
				 	printf("出栈成功,出栈的元素为%d\n", data);
				    shuchu();
	            } else
					printf("链表为空,出栈失败");
					break;
			}
			case 'd': {//***************得到栈头元素***************
		        if(getTopLStack(s, &data)) {
					printf("栈顶部元素为%d\n", data);
				}  else
					printf("栈为空\n");
				    break;
			}
			case 'e': {//***************检测链表长度***************
				LStackLength(s, &data);
				printf("当前栈长度为%d\n", data);
				break;
			}
			case 'f': {//***************清空链表***************
				if(clearLStack(s)) {
					printf("清空完成\n");
				} else printf("栈已为空\n");
					 break;
         	}
			case 'g': {//***************销毁链表***************
			    if(destoryLStack(s)) {
					printf("销毁成功\n");
	         		return;
				} else ("栈已为空\n");
					break;
			}
		}

		while (1) {
            scanf("%c", &choice);
            flag = getchar();
            if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ||'e' == choice
                ||'f' == choice || 'g' == choice || 'q' == choice) && '\n' == flag)
            break;
            else
                printf ("请输入正确的选择！\n");
            eatline();
        }
	}
	return;
}

char startmenu() {
	char choice, flag;
	printf("\t\t\t   _____________________________________________________\n");
	printf("\t\t\t   |--->     a.建立顺序栈                          <---|\n");
	printf("\t\t\t   |--->     b.建立链表栈                          <---|\n");
	printf("\t\t\t   |--->     c.退出程序                            <---|\n");
	printf("\t\t\t   -----------------------------------------------------\n\n");

    while (OK) {
        scanf("%c", &choice);
        flag = getchar();
        if (('a' == choice || 'b' == choice || 'c' == choice) && '\n' == flag)
            break;
        else
            printf ("请输入正确的选择！\n");
        fflush(stdin);
	}
	return choice;
}
int main(void)
{
	char choice;

	while(choice = startmenu()) {
		if ('c' == choice) exit(ERROR);
		if ('a' == choice)
		{
			printf("请输入你你想建立栈的长度\n");
			int i;
			while(!scanf("%d", &i)) {
                    printf("请输入正确的数字，输入0退出程序\n");
                eatline();
			}
			if (ERROR == i) exit(ERROR);
			SqStack s;
			if ( OK == initStack(&s, i)) {
				printf("创建顺序栈成功！\n");
				eatline(); //一定要清空
				stack(&s);
				break;
			}
			else exit(ERROR);
		}
		if ('b' == choice) {
            LinkStack s;
			if ( OK == initLStack(&s)) {
				printf("创建链栈成功！\n");
				lstack(&s);
				break;
			}
            else exit(ERROR);
		}
	}

	return 0;
}
