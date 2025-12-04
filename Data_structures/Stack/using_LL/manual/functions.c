// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <unistd.h>
// #include "header.h"
// 
// struct node *TOP = NULL;
// 
// /* -------- AUTOMATED PUSH (RANDOM VALUE) -------- */
// void push_auto()
// {
//     int x = rand() % 100;
// 
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     if (!newnode)
//     {
//         printf("\033[31mMemory Allocation Failed\033[0m\n");
//         return;
//     }
// 
//     newnode->data = x;
//     newnode->next = TOP;
//     TOP = newnode;
// 
//     printf("\033[32m[AUTO PUSH] %d\033[0m\n", x);
// }
// 
// /* -------- MANUAL PUSH -------- */
// void push_manual()
// {
//     int x;
//     printf("Enter value: ");
// 
//     if (scanf("%d", &x) != 1)
//     {
//         printf("\033[31mInvalid Input! Returning to menu.\033[0m\n");
//         return;
//     }
// 
//     struct node *newnode = malloc(sizeof(struct node));
//     if (!newnode)
//     {
//         printf("\033[31mMemory Allocation Failed\033[0m\n");
//         return;
//     }
// 
//     newnode->data = x;
//     newnode->next = TOP;
//     TOP = newnode;
// 
//     printf("\033[32mPushed %d\033[0m\n", x);
// }
// 
// /* -------- POP -------- */
// void pop_value()
// {
//     if (TOP == NULL)
//     {
//         printf("\033[31mStack Underflow\033[0m\n");
//         return;
//     }
// 
//     struct node *temp = TOP;
//     printf("\033[33mPopped %d\033[0m\n", TOP->data);
// 
//     TOP = TOP->next;
//     free(temp);
// }
// 
// /* -------- PEEK -------- */
// void peek()
// {
//     if (TOP == NULL)
//         printf("\033[31mStack Empty\033[0m\n");
//     else
//         printf("\033[35mTop Element: %d\033[0m\n", TOP->data);
// }
// 
// /* -------- DISPLAY -------- */
// void display()
// {
//     struct node *temp = TOP;
// 
//     printf("\033[36mStack: \033[0m");
// 
//     if (TOP == NULL)
//     {
//         printf("[ empty ]\n");
//         return;
//     }
// 
//     while (temp)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }
// 
// /* -------- EMPTY CHECK -------- */
// void isempty()
// {
//     if (TOP == NULL)
//         printf("\033[34mStack is EMPTY\033[0m\n");
//     else
//         printf("\033[35mStack is NOT empty\033[0m\n");
// }
// 
// /* -------- FULL CHECK -------- */
// void isfull()
// {
//     /* Linked list stack is NEVER full until memory ends */
//     printf("\033[35mStack is NOT full (Linked List)\033[0m\n");
// }










#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct node *TOP = NULL;

/* -------- CLEAR INPUT BUFFER -------- */
void clear_buffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/* -------- SAFE INTEGER INPUT -------- */
int safe_int_input(int *var)
{
    if (scanf("%d", var) != 1)
    {
        printf("\033[31mInvalid input! Only integers allowed.\033[0m\n");
        clear_buffer();
        return 0;
    }
    clear_buffer();
    return 1;
}

/* -------- MANUAL PUSH -------- */
void push_manual()
{
    int x;

    printf("Enter value: ");

    if (!safe_int_input(&x))
        return;

    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode)
    {
        printf("\033[31mMemory Allocation Failed\033[0m\n");
        return;
    }

    newnode->data = x;
    newnode->next = TOP;
    TOP = newnode;

    printf("\033[32mPushed %d\033[0m\n", x);
}

/* -------- POP -------- */
void pop_value()
{
    if (TOP == NULL)
    {
        printf("\033[31mStack Underflow\033[0m\n");
        return;
    }

    struct node *temp = TOP;
    printf("\033[33mPopped %d\033[0m\n", TOP->data);

    TOP = TOP->next;
    free(temp);
}

/* -------- PEEK -------- */
void peek()
{
    if (TOP == NULL)
        printf("\033[31mStack Empty\033[0m\n");
    else
        printf("\033[35mTop Element: %d\033[0m\n", TOP->data);
}

/* -------- DISPLAY -------- */
void display()
{
    struct node *temp = TOP;

    if (!temp)
    {
        printf("\033[31mStack is Empty\033[0m\n");
        return;
    }

    printf("\033[36mStack: \033[0m");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* -------- EMPTY CHECK -------- */
void isempty()
{
    if (TOP == NULL)
        printf("\033[34mStack is EMPTY\033[0m\n");
    else
        printf("\033[35mStack is NOT empty\033[0m\n");
}

/* -------- FULL CHECK -------- */
void isfull()
{
    printf("\033[35mStack is NOT full (Linked List)\033[0m\n");
}


