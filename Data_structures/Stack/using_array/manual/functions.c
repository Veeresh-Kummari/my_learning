#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

int *stack = NULL;
int TOP = -1;
int N = 0;

/* -------------------------------------------------------
   SAFE INTEGER INPUT  (handles chars, symbols, floats...)
   ------------------------------------------------------- */
int safe_int_input(int *num)
{
    char buffer[100];

    if (!fgets(buffer, sizeof(buffer), stdin))
        return 0;

    char *p = buffer;

    // Skip leading spaces
    while (*p == ' ')
        p++;

    // Handle empty input or only newline
    if (*p == '\n' || *p == '\0')
        return 0;

    // Check minus sign
    if (*p == '-')
        p++;

    // First digit must be 0-9
    if (!isdigit(*p))
        return 0;

    p++;

    // Check entire remaining characters
    while (*p != '\0' && *p != '\n')
    {
        if (!isdigit(*p))   // reject floats, symbols, chars
            return 0;
        p++;
    }

    *num = atoi(buffer);
    return 1;
}

/* ------------ Initialize Stack ------------ */
void init_stack()
{
    printf("Enter stack size: ");

    while (!safe_int_input(&N) || N <= 0)
    {
        printf("\033[31mInvalid size! Enter positive integer: \033[0m");
    }

    stack = malloc(N * sizeof(int));
    TOP = -1;

    printf("\033[36m[STACK INITIALIZED WITH SIZE]: %d\033[0m\n", N);
}

/* ------------ Manual Push ------------ */
void push_manual()
{
    int x;
    printf("Enter value to push: ");

    if (!safe_int_input(&x))
    {
        printf("\033[31mInvalid input! Please enter only integers.\033[0m\n");
        return;
    }

    if (TOP == N - 1)
    {
        printf("\033[31mStack Overflow\033[0m\n");
        return;
    }

    stack[++TOP] = x;
    printf("\033[32mPushed %d\033[0m\n", x);
}

/* ------------ Pop ------------ */
void pop()
{
    if (TOP == -1)
    {
        printf("\033[31mStack Underflow\033[0m\n");
        return;
    }

    printf("\033[33mPopped %d\033[0m\n", stack[TOP--]);
}

/* ------------ Peek ------------ */
void peek()
{
    if (TOP == -1)
        printf("\033[31mStack Empty\033[0m\n");
    else
        printf("\033[35mTop Element: %d\033[0m\n", stack[TOP]);
}

/* ------------ Display ------------ */
void display()
{
    printf("\033[36mStack: \033[0m");

    if (TOP == -1)
    {
        printf("[ empty ]\n");
        return;
    }

    for (int i = TOP; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

/* ------------ Empty Check ------------ */
void isempty()
{
    printf(TOP == -1 ? "\033[34mStack is EMPTY\033[0m\n"
                     : "\033[32mStack is NOT empty\033[0m\n");
}

/* ------------ Full Check ------------ */
void isfull()
{
    printf(TOP == N - 1 ? "\033[34mStack is FULL\033[0m\n"
                        : "\033[32mStack is NOT full\033[0m\n");
}

/* ------------ Clean Up ------------ */
void free_stack()
{
    free(stack);
}

