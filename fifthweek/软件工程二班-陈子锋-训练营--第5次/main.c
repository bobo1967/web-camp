#include <stdio.h>
#include "ͷ�ļ�/BinaryTree.h" 
#include <stdlib.h>
#include <string.h> 
#include "BinaryTree.c" 


void print() {
	//��ʼ���˵� 
	printf ("\n\n->----------------------------------------------------------------------<-\n");
	printf ("->--------------------------��������ȷ��ѡ��----------------------------<-\n");
	printf ("->                                                                      <-\n");
	printf ("->           A.��ʼ��һ�ö�����          B. ����һ�ö�����              <-\n");
	printf ("->           C.����һ�ö�����            D.�����������                 <-\n");
	printf ("->           E.�����������              F.�����������                 <-\n");
	printf ("->           G.�����������              H.ǰ׺���ʽ��ֵ               <-\n");
	printf ("->           Q.�˳�����                                                 <-\n");
	printf ("->--------------------version: 1.0----by edison-------------------------<-\n");
	printf ("->----------------------------------------------------------------------<-\n\n");
}

int main(void) {
	char choice, flag;
	BiTree T;
	
	int f = ERROR;//��ʼ���жϷ� 
	//�˵�
	print();
	while (1) {
		scanf("%c", &choice);
		flag = getchar();
		if ((('A' <= choice && choice <= 'H') || 'Q' == choice) && flag == '\n') {
			break;
		}
		else {
			printf("��������ȷ��ѡ��\n");
			fflush(stdin);
		}
	}
	while ('Q' != choice) {
		switch (choice) {
			case 'A' : { //��ʼ��������
				InitBiTree(&T);
				f = SUCCESS; 
				printf ("��ʼ���ɹ���");
				break;
			}
			case 'B' : { //����һ�ö�����
				T = (BiTree)malloc(sizeof(BiTNode));
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
					break; 
				} 
				printf ("\n�������ʽ��'#' ���������'A-Z��ʾ���' \n");
				printf ("����������ˣ��������QAQ\n"); 
				printf ("�Ƽ���ʽ ABD##E##C##\n");
				int i = 0;
				char s;
				char *definition = (char *)malloc(sizeof(char));
				while ( ((s = getchar()) != '\n') ) {
					//��̬�ַ��������ǻ�û�����ô���������� 
					if ((s >= 'A' && s <= 'Z') || '#' == s) {
						definition[i] = s;
						i++;
						definition = (char *)realloc(definition, i * sizeof(char)); 
					}  else {
						continue;
					}
				}
				definition[i] = '\0';
				if (definition[0] == '\0') {
					printf ("��ʽ���󣬹���ʧ�ܣ�");  
				}  else {
					printf("������Ľṹ��\n%s\n", definition);
					printf ("�����ɹ���\n");
					CreateBiTree(T, definition);
				}	
				break;
			}
			case 'C' : {//����һ�ö�����
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
				}  else { 
			 		DestroyBiTree(&T);		
					printf ("���ٳɹ���\n");
					return;
				}
				break;
			}
			case 'D' : { //������� 
				if (SUCCESS != f) {
					printf ("���ȳ�ʼ����������\n");
				}  
				if (T == NULL) {
					printf ("��Ϊ�գ����ȹ���һ�ö�������\n"); 
				} 
				LevelOrderTraverse(T, visit); 
				break;
			}
			case 'E' : { //������� 
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
				}  else
				if (NULL == T) {
					printf ("����һ�ÿ��������ȹ���һ�ö�����\n");
				} else {
					PreOrderTraverse(T, visit);
				}
				break;
			} 
			case 'F' : { //������� 
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
					break; 
				} else 
				if (NULL == T) {
					printf ("����һ�ÿ��������ȹ���һ�ö�����\n"); 
				} else {
					InOrderTraverse(T, visit);
				}
				break;
			}
			case 'G' : { //��������
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
				}  else 
				if (NULL == T) {
					printf ("����һ�ÿ��������ȹ���һ�ö�����\n"); 
				} else {
					PostOrderTraverse(T, visit);
				}
				break;
			}
			case 'H' : {//��������ֵ
			if (ERROR == f) {
				printf ("���ȳ�ʼ��һ������"); 
				break;
			} 	
			printf ("\n������һ��ǰ׺���ʽ����֧��10�������������������㣺\n");
			printf ("ϣ�����ο��ҵĲο���ʽ��+2*34\n");
			int i = 0;
			char s;
			char *definition = (char *)malloc(sizeof(char));
			while ( (s = getchar()) != '\n' ) {
				if ((s >= '0' && s <= '9') || '+' == s || '-' == s || '*' == s || '/' == s ) {
						definition[i] = s;
						i++;
						definition = (char *)realloc(definition, i * sizeof(char));
					} else {
						continue;
					}  
				}
				//һЩ�򵥵Ĺ��� 
				printf ("\n������ı��ʽ��\n%s\n", definition);
				T = (BiTree)malloc(sizeof(BiTNode));
				CreateBiTree(T, definition); 
				printf(" ��õ�ֵ��%lf\n", Value(T));
				
			break;
			} 
		}
		
		print();
		while (1) {
			scanf("%c", &choice);
			flag = getchar();
			if ((('A' <= choice && choice <= 'H') || 'Q' == choice) && flag == '\n') {
				break;
			} else {
				printf ("\n��������ȷ��ѡ��\n");
				fflush(stdin);
			}
		}
	}
	printf("�˳�����ɹ���");
	return 0; 
} 
