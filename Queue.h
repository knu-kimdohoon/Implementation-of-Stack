#pragma once
#include <stdio.h>
#include <malloc.h>
#include "Stack.h"

typedef struct QueueNode {
	StackHead* stackData;
	struct QueueNode* next;
	char* menus;
}QueueNode;

typedef struct Queue {
	QueueNode* front, * rear;
	int count;
}Queue;

Queue* CreateQueue() {
	Queue* pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue == NULL) {
		return NULL;
	}
	pQueue->front = pQueue->rear = NULL;
	pQueue->count = 0;

	printf("The Queue is created\n");
	return pQueue;
}

void DestroyQueue(Queue* pQueue) {
	QueueNode* pCur = NULL, * pNext = NULL;
	int i = 0;

	for (pCur = pQueue->front; pCur != NULL; pCur = pNext) {
		pNext = pCur->next;
		DestoryStack(pCur->stackData);
		free(pCur);
		i++;
		pQueue->count--;
		printf("Queue Node[%d] is Destroyed. %d Number of Queue is remained\n", i, pQueue->count);
	}

	pQueue->front = pQueue->rear = NULL;
	pQueue->count = 0;
	free(pQueue);
	printf("The Queue is Destoryed\n");

	return;
}

void Enqueue(Queue* pQueue, StackHead* pStack, char* menus) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) {
		return;
	}
	newNode->stackData = pStack;
	newNode->next = NULL;
	newNode->menus = menus;

	if (pQueue->front == NULL && pQueue->rear == NULL) {
		pQueue->front = pQueue->rear = newNode;
	}
	else {
		pQueue->rear->next = newNode;
		pQueue->rear = newNode;
		
	}
	pQueue->count++;
}

StackHead* Dequeue(Queue* pQueue) {
	QueueNode* qNode = NULL;
	StackHead* stkItem = NULL;

	if (pQueue->count<=0) {
		return NULL;
	}
	qNode = pQueue->front;
	stkItem = qNode->stackData;
	
	if (pQueue->count == 1) {
		pQueue->front = pQueue->rear = NULL;
	}
	else {
		pQueue->front = qNode->next;
	}
	free(qNode);
	pQueue->count--;

	return stkItem;
}