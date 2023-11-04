#pragma once
#include <stdio.h>
#include <malloc.h>

typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode;

typedef struct StackHead {
	int count;
	StackNode* top;
}StackHead;

StackHead* CreateStack() {
	StackHead* pStack = (StackHead*)malloc(sizeof(StackHead));
	if (pStack == NULL) {
		return NULL;
	}

	pStack->count = 0;
	pStack->top = NULL;

	printf("Success to allocate memory\n");
	return pStack;
}

void DestoryStack(StackHead* pStack) {
	int i = 0;
	while (1) {
		if (pStack->top != NULL) {
			StackNode* dltNode;
			dltNode = pStack->top;
			pStack->top = dltNode->next;
			free(dltNode);
			pStack->count--;
			i++;
			printf("Success to destory [%d] Node, count : %d\n", i, pStack->count);
		}
		else {
			break;
		}
	}
	free(pStack);
	printf("Success to Destory Stack\n");

	return;
}

void Push(StackHead* pStack, int data) {
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (newNode == NULL) {
		return;
	}
	newNode->data = data;
	newNode->next = pStack->top;
	pStack->top = newNode;
	pStack->count++;
	//printf("data : %d count : %d\n", pStack->top->data, pStack->count);
}

int Pop(StackHead* pStack) {
	if (pStack->count == 0) {
		return NULL;
	}
	StackNode* outNode = NULL;
	int item = 0;

	outNode = pStack->top;
	item = outNode->data;
	pStack->top = outNode->next;
	free(outNode);
	//pStack->count--;

	return item;
}