#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "header.h"

struct node *TOP = NULL;

/* ---------- AUTO PUSH ---------- */
void push_auto()
{
    int x = rand() % 100;

    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode)
    {
        printf("\033[31m[ERROR] Memory Allocation Failed\033[0m\n");
        return;
    }

    newnode->data = x;
    newnode->next = TOP;
    TOP = newnode;

    printf("\033[32m[AUTO PUSH] %d\033[0m\n", x);
}

/* ---------- POP ---------- */
void pop_value()
{
    if (TOP == NULL)
    {
        printf("\033[31m[AUTO POP] Stack Underflow\033[0m\n");
        return;
    }

    struct node *temp = TOP;
    printf("\033[33m[AUTO POP] %d\033[0m\n", TOP->data);

    TOP = TOP->next;
    free(temp);
}

/* ---------- PEEK ---------- */
void peek()
{
    if (TOP == NULL)
        printf("\033[31m[AUTO PEEK] Stack Empty\033[0m\n");
    else
        printf("\033[35m[AUTO PEEK] Top = %d\033[0m\n", TOP->data);
}

/* ---------- DISPLAY ---------- */
void display()
{
    struct node *temp = TOP;

    printf("\033[36m[AUTO DISPLAY] Stack: \033[0m");

    if (TOP == NULL)
    {
        printf("[ empty ]\n");
        return;
    }

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ---------- ISEMPTY ---------- */
void isempty()
{
    if (TOP == NULL)
        printf("\033[34m[AUTO ISEMPTY] Stack EMPTY\033[0m\n");
    else
        printf("\033[35m[AUTO ISEMPTY] Stack NOT empty\033[0m\n");
}

/* ---------- ISFULL ---------- */
void isfull()
{
    printf("\033[35m[AUTO ISFULL] Stack is NOT full (Linked List)\033[0m\n");
}

