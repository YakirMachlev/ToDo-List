#include "linearLinkedList.h"

void PushLinearLinkedList(LinearLinkedListNode** manager)
{
	LinearLinkedListNode* newNode;
	newNode = (LinearLinkedListNode*)malloc(sizeof(LinearLinkedListNode));
	newNode->nextAddress = *manager;
	*manager = newNode;
}

void InsertAfterNodeLinearLinkedList(LinearLinkedListNode* node)
{
	LinearLinkedListNode* newNode;
	newNode = (LinearLinkedListNode*)malloc(sizeof(LinearLinkedListNode));
	newNode->nextAddress = node->nextAddress;
	node->nextAddress = newNode;
}

void PopLinearLinkedList(LinearLinkedListNode** manager)
{
	LinearLinkedListNode* tempNode;
	tempNode = *manager;
	*manager = (*manager)->nextAddress;
	free(tempNode);
}

void DeleteAfterNodeLinearLinkedList(LinearLinkedListNode* node)
{
	LinearLinkedListNode* tempNode;
	tempNode = node->nextAddress;
	node->nextAddress = tempNode->nextAddress;
	free(tempNode);
}

LinearLinkedListNode* SearchNodeLinearLinkedList(LinearLinkedListNode* manager, int num)
{
	LinearLinkedListNode* currentNode;
	int offset;
	currentNode = manager;

	for (offset = 1; offset < num; offset++)
		currentNode = currentNode->nextAddress;

	return currentNode;
}

void PrintLinearLinkedList(LinearLinkedListNode* manager)
{
	LinearLinkedListNode* currentNode;
	int offset;
	currentNode = manager;
	offset = 1;

	printf("The tasks are:\n");
	while (currentNode)
	{
		printf("%d: ", offset++);
		PrintTask(currentNode->info);
		currentNode = currentNode->nextAddress;
	}
	printf("\n");
}

void FreeLinearLinkedList(LinearLinkedListNode** manager)
{
	LinearLinkedListNode** start;
	start = manager;

	while (*start)
	{
		PopLinearLinkedList(start);
	}
}