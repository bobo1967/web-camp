#include <stdio.h>
#include "BinaryTree.h" 
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
	printf ("->           G.�����������              Q.�˳�����                     <-\n");
	printf ("->                                                                      <-\n");
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
		if ((('A' <= choice && choice <= 'Z') || 'q' == choice) && flag == '\n') {
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
				InitBiTree(T);
				f = SUCCESS; 
				printf ("��ʼ���ɹ���");
				break;
			}
			case 'B' : { //����һ�ö�����
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
					break; 
				} 
				printf ("\n�������ʽ��'#' ���������'A-Z��ʾ���' \n");
				printf ("�Ƽ���ʽ��ABD##E##C##\n");
				int i = 0;
				char s;
				char *definition = (char *)malloc(sizeof(char));
				while ( ((s = getchar()) != '\n') ) {
					if ((s >= 'A' && s <= 'Z') || '#' == s) {
						definition[i] = s;
						i++;
						definition = (char *)realloc(definition, i * sizeof(char));
					}  else {
						continue;
					}
				}
			
				printf ("\n������ĸ�ʽ��\n%s\n", definition);
				CreateBiTree(T, definition);
				printf ("\n�����ɹ���\n"); 
				break;
			}
			case 'C' : {//����һ�ö�����
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
					break; 
				}  else
				if (SUCCESS == DestroyBiTree(T)) {		
					printf ("���ٳɹ���\n\n");
					break;
				}  else {
					printf("����ʧ�ܣ�\n");
					//return ERROR;
					break; 
				}
			}
			/*
			case 'c' : {//��������ֵ
				printf ("\n������һ��ǰ׺���ʽ����֧��10�������������������㣺\n");
				printf ("�ο���ʽ��+2*34\n");
				int i = 0;
				char s;
				char *definition = (char *)malloc(sizeof(char));
				while ( (s = getchar()) != '\n' ) {
					if ((s >= '0' && s <= '9') || '+' == s || '-' == s || '*' == s || '/' == s ) {
						definition[i] = s;
						i++;
						definition = (char *)realloc(definition, i * sizeof(char));
					}  else {
						continue;
					}  
				}
				printf ("\n������ı��ʽ��\n%s\n", definition);
				 
				break;
			} 
			*/
			case 'D' : { //������� 
				if (SUCCESS != f) {
					printf ("���ȳ�ʼ����������\n");
					break; 
				}
				if (ERROR == LevelOrderTraverse(T, visit)) {
					printf ("����һ�ÿ�����\n"); 
					break;
				}
			}
			case 'E' : { //������� 
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
					break; 
				} 
			 	PreOrderTraverse(T, visit);
				break;
			} 
			case 'F' : { //������� 
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
					break; 
				}	
				InOrderTraverse(T, visit);
				break;
			}
			case 'G' : { //��������
				if (SUCCESS != f) {
					printf("���ȳ�ʼ����������\n");
					break; 
				} 
				PostOrderTraverse(T, visit);
				break;
			}
		}
		
		print();
		while (1) {
			scanf("%c", &choice);
			flag = getchar();
			if ((('A' <= choice && choice <= 'Z') || 'Q' == choice) && flag == '\n') {
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
