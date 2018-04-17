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
	printf("\t\t\t   |--->     a.�ж������Ƿ�Ϊ��                       <---|\n");
	printf("\t\t\t   |--->     b.��ջ                                   <---|\n");
	printf("\t\t\t   |--->     c.��ջ                                   <---|\n");
	printf("\t\t\t   |--->     d.�õ�����ͷԪ��                         <---|\n");
	printf("\t\t\t   |--->     e.���������                           <---|\n");
	printf("\t\t\t   |--->     f.�������                               <---|\n");
	printf("\t\t\t   |--->     g.��������                               <---|\n");
	printf("\t\t\t   |--->     q.��������                               <---|\n");
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
            printf("��������ȷ��ѡ��\n");
        eatline();
	}
	while('q' != choice) {
		switch (choice) {
			case 'a': {//***************�ж������Ƿ�Ϊ��***************
				if (isEmptyStack(s)) {
			  		printf("��ǰ����Ϊ��\n");
			    	shuchu();
				} else
					printf("��ǰ�������\n");
				break;
			}
			case 'b': {//***************��ջ***************
				printf("������������Ҫѹ�������:\n");
				while(!scanf("%d", &data)) {
                    printf("��������ȷ�����֣�����0�˳�����\n");
                    eatline();
				}
				eatline();
				if (OK == pushStack(s, data)) {
                    shuchu();
					printf("ѹ��ɹ�\n");
					break;
				} else
					printf("ջ����,ѹ��ʧ��\n");
				break;
			}
			case 'c': {//***************��ջ***************
				if (OK == popStack(s, &data)) {
				 	printf("��ջ�ɹ�,��ջ��Ԫ��Ϊ%d\n", data);
				    shuchu();
	            } else
					printf("����Ϊ��,��ջʧ��");
					break;
			}
			case 'd': {//***************�õ�ջͷԪ��***************
		        if(getTopStack(s, &data)) {
					printf("����ͷԪ��Ϊ%d\n", data);
				}  else
					printf("����Ϊ��\n");
				    break;
			}
			case 'e': {//***************���������***************
				stackLength(s, &data);
				printf("��ǰ������Ϊ%d\n", ++data);
				break;
			}
			case 'f': {//***************�������***************
				if(clearStack(s)) {
					printf("������\n");
				} else printf("������Ϊ��\n");
					 break;
         	}
			case 'g': {//***************��������***************
			    if(destoryStack(s)) {
					printf("���ٳɹ�\n");
	         		return;
				} else ("������Ϊ��\n");
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
                printf ("��������ȷ��ѡ��\n");
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
            printf ("��������ȷ��ѡ��\n");
        eatline();
	}
	while('q' != choice) {
		switch (choice) {
			case 'a': {//***************�ж������Ƿ�Ϊ��***************
				if (isEmptyLStack(s)) {
			  		printf("��ǰջΪ��\n");
			    	shuchu();
				} else
					printf("��ǰջ����\n");
				break;
			}
			case 'b': {//***************��ջ***************
				printf("����������Ҫѹ�������:\n");
				while(!scanf("%d", &data)) {
                    printf("��������ȷ�����֣�����0�˳�����\n");
                eatline();
                }
				eatline();
				if (OK == pushLStack(s, data)) {
					printf("��ջ�ɹ�\n");
					shuchu();
				} else
					printf("ջ����,ѹ��ʧ��\n");
				break;
			}
			case 'c': {//***************��ջ***************
				if (OK == popLStack(s, &data)) {
				 	printf("��ջ�ɹ�,��ջ��Ԫ��Ϊ%d\n", data);
				    shuchu();
	            } else
					printf("����Ϊ��,��ջʧ��");
					break;
			}
			case 'd': {//***************�õ�ջͷԪ��***************
		        if(getTopLStack(s, &data)) {
					printf("ջ����Ԫ��Ϊ%d\n", data);
				}  else
					printf("ջΪ��\n");
				    break;
			}
			case 'e': {//***************���������***************
				LStackLength(s, &data);
				printf("��ǰջ����Ϊ%d\n", data);
				break;
			}
			case 'f': {//***************�������***************
				if(clearLStack(s)) {
					printf("������\n");
				} else printf("ջ��Ϊ��\n");
					 break;
         	}
			case 'g': {//***************��������***************
			    if(destoryLStack(s)) {
					printf("���ٳɹ�\n");
	         		return;
				} else ("ջ��Ϊ��\n");
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
                printf ("��������ȷ��ѡ��\n");
            eatline();
        }
	}
	return;
}

char startmenu() {
	char choice, flag;
	printf("\t\t\t   _____________________________________________________\n");
	printf("\t\t\t   |--->     a.����˳��ջ                          <---|\n");
	printf("\t\t\t   |--->     b.��������ջ                          <---|\n");
	printf("\t\t\t   |--->     c.�˳�����                            <---|\n");
	printf("\t\t\t   -----------------------------------------------------\n\n");

    while (OK) {
        scanf("%c", &choice);
        flag = getchar();
        if (('a' == choice || 'b' == choice || 'c' == choice) && '\n' == flag)
            break;
        else
            printf ("��������ȷ��ѡ��\n");
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
			printf("�����������뽨��ջ�ĳ���\n");
			int i;
			while(!scanf("%d", &i)) {
                    printf("��������ȷ�����֣�����0�˳�����\n");
                eatline();
			}
			if (ERROR == i) exit(ERROR);
			SqStack s;
			if ( OK == initStack(&s, i)) {
				printf("����˳��ջ�ɹ���\n");
				eatline(); //һ��Ҫ���
				stack(&s);
				break;
			}
			else exit(ERROR);
		}
		if ('b' == choice) {
            LinkStack s;
			if ( OK == initLStack(&s)) {
				printf("������ջ�ɹ���\n");
				lstack(&s);
				break;
			}
            else exit(ERROR);
		}
	}

	return 0;
}
