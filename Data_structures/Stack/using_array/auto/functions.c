#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "header.h"

int *stack = NULL;
int TOP = -1;
int N = 0;
int overflow_count = 0;
int underflow_count = 0;

/* ---------- Initialize Stack (Random Size) ---------- */
void init_stack()
{
    N = (rand() % 11) + 5;   // size 5–15 randomly
    stack = malloc(N * sizeof(int));
    TOP = -1;

    printf("\033[36m[STACK INITIALIZED] Random size: %d\033[0m\n", N);
}

/* ---------- Auto Push ---------- */
void auto_push()
{
    int x = rand() % 100;

    if (TOP == N - 1)
    {
        printf("\033[31m[AUTO PUSH FAILED] STACK FULL\033[0m\n");
        overflow_count++;
        return;
    }

    stack[++TOP] = x;
    printf("\033[32m[AUTO PUSH] %d\033[0m\n", x);
}

/* ---------- Pop ---------- */
void pop()
{
    if (TOP == -1)
    {
        printf("\033[31m[POP FAILED] Stack Underflow\033[0m\n");
        underflow_count++;
        return;
    }

    printf("\033[33m[POP] %d\033[0m\n", stack[TOP--]);
}

/* ---------- Peek ---------- */
void peek()
{
    if (TOP == -1)
        printf("\033[31m[PEEK] Stack Empty\033[0m\n");
    else
        printf("\033[35m[PEEK] Top: %d\033[0m\n", stack[TOP]);
}

/* ---------- Display ---------- */
void display()
{
    printf("\033[36m[DISPLAY] Stack: \033[0m");

    if (TOP == -1)
    {
        printf("[ empty ]\n");
        return;
    }

    for (int i = TOP; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

/* ---------- Empty Check ---------- */
void isempty()
{
    printf(TOP == -1
           ? "\033[34m[EMPTY] Stack is EMPTY\033[0m\n"
           : "\033[32m[EMPTY CHECK] Stack NOT empty\033[0m\n");
}

/* ---------- Full Check ---------- */
void isfull()
{
    printf(TOP == N - 1
           ? "\033[34m[FULL] Stack is FULL\033[0m\n"
           : "\033[32m[FULL CHECK] Stack NOT full\033[0m\n");
}

/* ---------- Clean Up ---------- */
void free_stack()
{
    free(stack);
}

/* ---------- Print Statistics ---------- */
void print_stats()
{
    printf("\n\033[36m===== STACK STATISTICS =====\n");
    printf("Stack Size: %d\n", N);
    printf("Current TOP: %d\n", TOP);
    printf("Overflow Count: %d\n", overflow_count);
    printf("Underflow Count: %d\n", underflow_count);
    printf("============================\033[0m\n");
}

