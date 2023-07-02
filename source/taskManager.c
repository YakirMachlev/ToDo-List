#include "board.h"

int main()
{
    LinearLinkedListNode* manager;
    printf("Welcome to your task manager!\n");
    manager = NULL;

    ActionsManager(&manager);

    return 0;
}