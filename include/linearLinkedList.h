#ifndef LINEAR_LINKED_LIST
	#define LINEAR_LINKED_LIST

	#include <stdio.h>
	#include <stdlib.h>
	#include "task.h"

	#ifndef BOOL
		#define BOOL char
	#endif

	#define LLL_TYPE taskPtr

	typedef struct LinearLinkedListNode
	{
		LLL_TYPE info;
		struct LinearLinkedListNode* nextAddress;
	}
	LinearLinkedListNode;

	void PushLinearLinkedList(LinearLinkedListNode**);
	void InsertAfterNodeLinearLinkedList(LinearLinkedListNode*);
	void PopLinearLinkedList(LinearLinkedListNode**);
	void DeleteAfterNodeLinearLinkedList(LinearLinkedListNode*);
	LinearLinkedListNode* SearchNodeLinearLinkedList(LinearLinkedListNode*, int);
	void PrintLinearLinkedList(LinearLinkedListNode*);
	void FreeLinearLinkedList(LinearLinkedListNode**);
#endif