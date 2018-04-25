#include <stdio.h>
#include <stdlib.h>
#include "头文件/queue.h"
#include <string.h>


void InitAQueue(AQueue *Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void *)malloc(Q->data_size);
	Q->front = 0;
	Q->rear  = 0;
}

Status IsEmptyAQueue(const AQueue *Q) {
	return (Q->front == Q->rear?TRUE: FALSE);
}

Status IsFullAQueue(const AQueue *Q) {
	return (Q->front == (Q->rear + 1) % MAXQUEUE? TRUE: FALSE);
}

Status EnAQueue(AQueue *Q, void *data) {
	if (IsFullAQueue(Q)) 
		return FALSE;
	Q->rear = (Q->rear+1) % MAXQUEUE;
	memcpy(Q->data[Q->rear], data, Q->data_size);
	return TRUE;
}

Status DeAQueue(AQueue *Q) {
	if (Q->front == Q->rear)
		return FALSE;
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}

void DestoryAQueue(AQueue *Q) {
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	return;
}

void ClearAQueue(AQueue *Q) {
	if (IsEmptyAQueue(Q))
		return;
	Q->front = 0;
	Q->rear = 0;
	return;
}

Status GetHeadAQueue(AQueue *Q, void *e) {
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = Q->front; 
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], Q->data_size);
	return TRUE;
}

int LengthAQueue(AQueue *Q) {
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE; 
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int size)) { 
	if (Q->front == Q->rear)
		return FALSE;
	int i = Q->front + 1;
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE ) {
		foo(Q->data[i], Q->data_size);	
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}

void APrint(void *q, int size) {
	if (size == sizeof(double))
		printf("%lf", *(double *)q);
	if (size == sizeof(char))
		printf("%c", *(char *)q);
	if (size == sizeof (int))
		printf("%d", *(int *)q);
	printf("<");
}

//链式队列 带头节点 
void InitLQueue(LQueue *Q) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	return;
}
	
Status IsEmptyLQueue(const LQueue *Q) {
	return (Q->front == Q->rear? TRUE: FALSE);
}

	
Status EnLQueue(LQueue *Q, void *data) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void *)malloc(Q->data_size);
	memcpy(p->data, data, Q->data_size);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}	

Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, Q->data_size);
	return TRUE;	
}

Status DeLQueue(LQueue *Q) {
	if(IsEmptyLQueue(Q))
		return FALSE;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (NULL == Q->front->next)  
		Q->rear = Q->front;
	free(p);
	return TRUE;
}
	
int LengthLQueue(LQueue *Q) {
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next; 
	return length;
}
	
void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return;
	Node *p, *q;
	Q->rear = Q->front;
	p = Q->front->next; 
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}	

void DestoryLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return; 
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int size)) {
	if (IsEmptyLQueue(Q))
		return FALSE;
		Node* p = (void *)malloc(Q->data_size); 
		p = Q->front->next; 
		int i = 1;
		while (p != NULL) {
			if (i % 20 == 0) printf("\n"); 
			foo(p->data, Q->data_size);
			p = p->next;
			i++;
		}
		printf("\n");
	return TRUE;
}

void LPrint(void *q, int size) {
	if (size == sizeof(double))
		printf("%lf", *(double *)q);
	if (size == sizeof(char))
		printf("%c", *(char *)q);
	if (size == sizeof (int))
		printf("%d", *(int *)q);
	printf("<");
}

