#include "board.h"

void AddTaskToList(LinearLinkedListNode** manager)
{
    taskPtr tsk;
    char name[256];
    BOOL active;

    printf("Enter the task name: ");
    scanf("%s", name);
    printf("Enter the task status: ");
    scanf(" %c", &active);

    tsk = CreateTask(name, active);
    PushLinearLinkedList(manager);
    (*manager)->info = tsk;
    printf("Task added successfully\n");
}

void EditTaskInList(LinearLinkedListNode* manager)
{
    int num;
    char subAction;
    char name[256];
    BOOL active;
    LinearLinkedListNode* taskNode;

    printf("Enter the number of the task that you want to change: ");
    scanf("%d", &num);
    taskNode = SearchNodeLinearLinkedList(manager, num);
    printf("1 - Change the task name\n2 - Change the task status\n");
    scanf(" %c", &subAction);
    switch (subAction)
    {
        case '1':
            printf("Enter the new name: ");
            scanf("%s", name);
            EditTaskName(taskNode->info, name);
            break;
        case '2':
            printf("Enter the new status: ");
            scanf(" %c", &active);
            EditTaskActive(taskNode->info, active);
            break;
    }
    printf("Task changed successfully\n");
}

void DeleteTaskFromList(LinearLinkedListNode** manager)
{
    int num;
    LinearLinkedListNode* taskNode;

    printf("Enter the number of the task that you want to delete: ");
    scanf("%d", &num);
    if (num == 1)
        PopLinearLinkedList(manager);
    else
    {
        taskNode = SearchNodeLinearLinkedList(*manager, num - 1);
        DeleteAfterNodeLinearLinkedList(taskNode);        
    }

    printf("Task deleted successfully\n");
}

void ReactToAction(LinearLinkedListNode** manager, char action)
{
    switch(action)
    {
        case '1':
            AddTaskToList(manager);
            break;
        case '2':
            EditTaskInList(*manager);
            break;
        case '3':
            DeleteTaskFromList(manager);
            break;
        case '4':
            PrintLinearLinkedList(*manager);
            break;
    }
}

void ActionsManager(LinearLinkedListNode** manager)
{
    char action;
    action = -1;

    while (action != '^')
    {
        printf("Enter the wanted action:\n");
        printf("1 - Add a new task\n");
        printf("2 - Edit a task\n");
        printf("3 - Delete a task\n");
        printf("4 - Show all the tasks\n");
        scanf(" %c", &action);
        ReactToAction(manager, action);
        printf("\n");
    }
    if (*manager)
        FreeLinearLinkedList(manager);

    printf("Goodbye\n");
}