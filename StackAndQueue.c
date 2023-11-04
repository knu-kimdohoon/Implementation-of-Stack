#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

void Order(Queue* pQueue) {
	char menus[10];
	int i = 0;
	char* Qmenus = NULL;
	StackHead* pStack = CreateStack();

	printf("Order : ");
	scanf("%s", menus);
	Qmenus = (char*)malloc(strlen(menus));
	strcpy(Qmenus, menus);
	for (i = 0; i < strlen(menus); i++) {
		Push(pStack, menus[i]-'0');
	}
	
	Enqueue(pQueue, pStack, Qmenus);
	printf("Print All data in the Stack\n");

	return;
}

void Serve(Queue* pQueue) {
	if (pQueue->front == NULL && pQueue->rear == NULL) {
		printf("No data in the Queue\n");
		return;
	}

	free(pQueue->front->menus);
	StackHead* sNode = Dequeue(pQueue);
	
	int i = 0;
	for (i = 0; i < sNode->count; i++) {
		int menu = 0;
		menu = Pop(sNode);
		if (menu == 1) {
			printf("Ice cream, ");
		}
		else if (menu == 2) {
			printf("Bibimbab, ");
		}
		else if (menu == 3) {
			printf("Bulgogi, ");
		}
		else if (menu == 4) {
			printf("Coffee, ");
		}
		else if (menu == 5) {
			printf("Noodle, ");
		}
		else {
			continue;
		}
	}
	printf("\n");
	DestoryStack(sNode);

	return; 
}
void PrintAllMenus(Queue* pQueue) {
	QueueNode* pCur = NULL, * pNext = NULL;

	for (pCur = pQueue->front; pCur != NULL; pCur = pNext) {
		printf("%s ", pCur->menus);
		pNext = pCur->next;
	}
	printf("(%d)\n", pQueue->count);

	return;
}

void main() {
	/*
	int item = 0;
	int i = 0;
	Queue* pQueue = CreateQueue();
	StackHead* pStack = NULL;
	for (i = 0; i < 4; i++) {
		item = 0;
		printf("Number : ");
		scanf("%d", &item); 
		pStack = CreateStack();
		Push(pStack, item);
		Enqueue(pQueue, pStack);
	}
	while (1) {
		item = Pop(pStack);
		if (item == NULL) {
			break;
		}
		else {
			printf("%d from Pop, count : %d\n", item, pStack->count);
		}
	}
	DestoryStack(pStack);

	DestroyQueue(pQueue);
	*/
	/*
	StackHead* pStack = CreateStack();
	Queue* pQueue = CreateQueue();
	int item = 0;

	printf("Number : ");
	scanf("%d", &item);
	Push(pStack, item);
	Enqueue(pQueue, pStack);

	printf("%d\n", pQueue->front->stackData->top->data);
	printf("%d\n", pQueue->rear->stackData->top->data);

	printf("%d\n", Dequeue(pQueue)->top->data);

	DestroyQueue(pQueue);
	DestoryStack(pStack);
	*/
	int choose = 0;
	Queue* pQueue = CreateQueue();
	while (1) {
		printf("Order(0), Serve(1), Exit(2) : ");
		scanf("%d", &choose);
		if (choose == 0) {
			Order(pQueue);
		}
		else if (choose == 1) {
			Serve(pQueue);
		}
		else if (choose == 2) {
			break;
		}
		printf("pQueue->count : %d\n", pQueue->count);
		PrintAllMenus(pQueue);
	}
	DestroyQueue(pQueue);
	printf("Programm end");
}