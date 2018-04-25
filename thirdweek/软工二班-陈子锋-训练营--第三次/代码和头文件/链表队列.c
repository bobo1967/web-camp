#include <stdio.h>
#include "头文件/queue.h"
#include "queue.c"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
char CHOICE;


void print() {
	printf("\t\t\t   ________________________________________________________\n");
    printf("\t\t\t   |--->now  input the char to choose the function:   <---|\n");
	printf("\t\t\t   |--->     a.判断队列是否为空                       <---|\n");
	printf("\t\t\t   |--->     b.入队                                   <---|\n");
	printf("\t\t\t   |--->     c.出队                                   <---|\n");
	printf("\t\t\t   |--->     d.得到队头元素                           <---|\n");
	printf("\t\t\t   |--->     e.检测队列长度                           <---|\n");
	printf("\t\t\t   |--->     f.打印当前队列                           <---|\n");
	printf("\t\t\t   |--->     g.清空队列                               <---|\n");
	printf("\t\t\t   |--->     h.销毁队列                               <---|\n");
	printf("\t\t\t   |--->     q.结束程序                               <---|\n");
	printf("\t\t\t   |______________________________________________________|\n\n");
}

char startmenu() {
	
	char choice, flag;
	printf("\t\t\t   _______________________________________________________\n");
	printf("\t\t\t   |--->     a.输入浮点型数据                         <---|\n");
	printf("\t\t\t   |--->     b.输入整形数据                           <---|\n");
	printf("\t\t\t   |--->     c.输入字符型数据                         <---|\n");
	printf("\t\t\t   |--->     d.退出程序                               <---|\n");
	printf("\t\t\t   -------------------------------------------------------\n\n");

    while (TRUE) {
        scanf("%c", &choice);
        flag = getchar();
        if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ) && '\n' == flag)
            break;
        else
            printf ("请输入正确的选择！\n");
        fflush(stdin);
	}
	return choice;
}

void runLQueue(LQueue *Q) {
	void *data = (void *)malloc(Q->data_size);
	void *data_2 = (void *)malloc(Q->data_size); 
	print();
	char flag, choice;
		fflush(stdin);
    while (1) {
        scanf("%c", &choice);
        flag = getchar();
        if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ||'e' == choice
           ||'f' == choice || 'g' == choice || 'h' == choice || 'q' == choice ) && '\n' == flag)
            break;
        else
            printf("请输入正确的选择！\n");
        fflush(stdin);
	}
	while('q' != choice) {
		switch (choice) {
			case 'a': {//***************判断队列是否为空***************
				if (IsEmptyLQueue(Q)) {
			  		printf("当前队列为空\n");
			  		break;
				} else
					printf("当前队列不为空\n");
					break;
			}
			case 'b': {//***************入队***************
				printf("现在输入你想要压入的数据:\n"); 
				if (CHOICE == 'a') {
					while (!scanf("%lf", (double*)data) ){
						printf("请输入正确的浮点型数据\n");
					fflush(stdin);
					}
				} 
				if (CHOICE == 'b') {
					while (!scanf("%d", (int*)data) ){
						printf("请输入正确的整形数字\n");
					fflush(stdin);
					}
				} 
				if (CHOICE == 'c') {
					while (!scanf("%c", (char*)data) ){
						printf("请输入正确的字符型数据\n");
					fflush(stdin);
					}
				} 
				fflush(stdin);
				if (TRUE == EnLQueue(Q,  data) ) 
					printf("入队成功！\n");
				else
					printf("队列已满,入队失败\n");
				break;
			}
			case 'c': {//***************出队***************
				if (TRUE == DeLQueue(Q)) 
				 	printf("出队成功！\n");
	            else
					printf("队列为空,出队失败\n");
				break;
			}
			case 'd': {//***************得到队头元素***************
		        if(!GetHeadLQueue(Q, data_2)) {
					printf("队列为空！\n");
					break;
				}
				if ('a' == CHOICE)
					printf("%lf\n", *(double *)data_2);
				if ('b' == CHOICE)
					printf("%d\n", *(int *)data_2);
				if ('c' == CHOICE)
					printf("%c\n", *(char *)data_2);	
				break;
			}
			case 'e': {//***************检测队列长度***************
				printf("当前队列长度为%d\n", LengthLQueue(Q));
				break;
			}
			case 'f': {
				if (!TraverseLQueue(Q, LPrint))
					printf("这是一个空队列！\n");
				break;
			}
			case 'g': {//***************清空队列***************
				if (IsEmptyLQueue(Q)) {
					printf("队列已为空\n");
					break;
				}
				ClearLQueue(Q);
				printf("清空完成\n");
				break;
         	}
			case 'h': {//***************销毁队列***************
			    DestoryLQueue(Q);
			    printf("销毁队列成功！");
			    return;
			}		
		}
		print();
		while (1) {
            scanf("%c", &choice);
            flag = getchar();
            if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ||'e' == choice
               ||'f' == choice || 'g' == choice || 'h' == choice || 'q' == choice) && '\n' == flag)
            break;
            else
                printf ("请输入正确的选择！\n");
            fflush(stdin);
        }
	}
	return;
}

int main(void) 
{
	CHOICE = startmenu( );
	if ('d' == CHOICE) exit(FALSE);
		else
		{
			LQueue Q;
			if ('b' == CHOICE) 
				Q.data_size = sizeof(int);
			if ('a' == CHOICE)
				Q.data_size = sizeof(double);
			if ('c' == CHOICE) 
				Q.data_size = sizeof(char);
			InitLQueue(&Q);
			printf("创建链表队列成功！\n");
			runLQueue(&Q);
		}
	return 0;
}
