#ifndef TASK
	#define TASK

	#include <stdio.h>
	#include <stdlib.h>

	#ifndef BOOL
		#define BOOL char
	#endif

	typedef struct task
	{
		char name[256];
		BOOL active;
	}task, *taskPtr;

    taskPtr CreateTask(char*, BOOL);
    void EditTaskName(taskPtr, char*);
    void EditTaskActive(taskPtr, BOOL);
    void PrintTask(taskPtr);
    void FreeTask(taskPtr);
#endif