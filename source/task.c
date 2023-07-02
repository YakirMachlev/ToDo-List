#include "task.h"
#include <string.h>

taskPtr CreateTask(char* name, BOOL active)
{
    taskPtr newTask;
    newTask = (taskPtr)malloc(sizeof(task));
    strcpy(newTask->name, name);
    newTask->active = active;

    return newTask;
}

void EditTaskName(taskPtr editedTask, char* name)
{
    strcpy(editedTask->name, name);
}

void EditTaskActive(taskPtr editedTask, BOOL active)
{
    editedTask->active = active;
}

void PrintTask(taskPtr tsk)
{
    printf("%s ", tsk->name);
    printf("%c\n", tsk->active);
}

void FreeTask(taskPtr tsk)
{
    free(tsk);
}