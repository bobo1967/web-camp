#include <stdio.h>
#include "ͷ�ļ�/queue.h"
#include "queue.c"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
char CHOICE;


void print() {
	printf("\t\t\t   ________________________________________________________\n");
    printf("\t\t\t   |--->now  input the char to choose the function:   <---|\n");
	printf("\t\t\t   |--->     a.�ж϶����Ƿ�Ϊ��                       <---|\n");
	printf("\t\t\t   |--->     b.���                                   <---|\n");
	printf("\t\t\t   |--->     c.����                                   <---|\n");
	printf("\t\t\t   |--->     d.�õ���ͷԪ��                           <---|\n");
	printf("\t\t\t   |--->     e.�����г���                           <---|\n");
	printf("\t\t\t   |--->     f.��ӡ��ǰ����                           <---|\n");
	printf("\t\t\t   |--->     g.��ն���                               <---|\n");
	printf("\t\t\t   |--->     h.���ٶ���                               <---|\n");
	printf("\t\t\t   |--->     q.��������                               <---|\n");
	printf("\t\t\t   |______________________________________________________|\n\n");
}

char startmenu() {
	
	char choice, flag;
	printf("\t\t\t   _______________________________________________________\n");
	printf("\t\t\t   |--->     a.���븡��������                         <---|\n");
	printf("\t\t\t   |--->     b.������������                           <---|\n");
	printf("\t\t\t   |--->     c.�����ַ�������                         <---|\n");
	printf("\t\t\t   |--->     d.�˳�����                               <---|\n");
	printf("\t\t\t   -------------------------------------------------------\n\n");

    while (TRUE) {
        scanf("%c", &choice);
        flag = getchar();
        if (('a' == choice || 'b' == choice || 'c' == choice || 'd' == choice ) && '\n' == flag)
            break;
        else
            printf ("��������ȷ��ѡ��\n");
        fflush(stdin);
	}
	return choice;
}

void runAQueue(AQueue *Q) {
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
            printf("��������ȷ��ѡ��\n");
        fflush(stdin);
	}
	
	while('q' != choice) {
		switch (choice) {
			case 'a': {//***************�ж϶����Ƿ�Ϊ��***************
				if (IsEmptyAQueue(Q)) 
			  		printf("��ǰ����Ϊ��\n");
				else
					printf("��ǰ���в�Ϊ��\n");
					break;
			}
			case 'b': {//***************���***************
				printf("������������Ҫѹ�������:\n"); 
				fflush(stdin);
				if (CHOICE == 'a') {
					while (!scanf("%lf", (double*)data) ){
						printf("��������ȷ������\n");
					fflush(stdin);
					}
				} 
				if (CHOICE == 'b') {
					while (!scanf("%d", (int*)data) ){
						printf("��������ȷ������\n");
					fflush(stdin);
					}
				} 
				if (CHOICE == 'c') {
					while (!scanf("%c", (char*)data) ){
						printf("��������ȷ������\n");
					fflush(stdin);
					}
				} 
				fflush(stdin);
				if (TRUE == EnAQueue(Q, data)) 
					printf("��ӳɹ���\n");
				else
					printf("��������,���ʧ��\n");
				break;
			}
			case 'c': {//***************����***************
				if (TRUE == DeAQueue(Q)) 
				 	printf("���ӳɹ���\n");
	            else
					printf("����Ϊ��,����ʧ��\n");
				break;
			}
			case 'd': {//***************�õ���ͷԪ��***************
				if(!GetHeadAQueue(Q, data_2)) {
					printf("����Ϊ�գ�\n"); 
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
			case 'e': {//***************�����г���***************
				printf("��ǰ���г���Ϊ%d\n", LengthAQueue(Q));
				break;
			}
			case 'f': {
				if (!TraverseAQueue(Q, APrint))
					printf("����һ���ն��У�\n");
				break;
			}
			case 'g': {//***********b****��ն���***************
				if (IsEmptyAQueue(Q)) {
					printf("������Ϊ��\n");
					break;
				}
				ClearAQueue(Q);
				printf("������\n");
				break;
         	}
			case 'h': {//***************���ٶ���***************
			    DestoryAQueue(Q);
			    printf("���ٶ��гɹ���");
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
                printf ("��������ȷ��ѡ��\n");
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
			AQueue Q;
			if ('b' == CHOICE) 
				Q.data_size = sizeof(int);
			if ('a' == CHOICE)
				Q.data_size = sizeof(double);
			if ('c' == CHOICE) 
				Q.data_size = sizeof(char);
			InitAQueue(&Q);	
			printf("����˳��ѭ�����гɹ���\n");
			runAQueue(&Q);
		}
	return 0;
}
