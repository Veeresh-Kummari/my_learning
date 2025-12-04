#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    init_stack();

    int choice;

    while (1)
    {
        printf("\n\033[32m===== STACK MENU =====\n");
        printf("1) push\n");
        printf("2) pop\n");
        printf("3) peek\n");
        printf("4) display\n");
        printf("5) isempty\n");
        printf("6) isfull\n");
        printf("0) exit\n");
        printf("=======================\033[0m\n");

        printf("Enter choice: ");

        if (!safe_int_input(&choice))
        {
            printf("\033[31mInvalid choice!\033[0m\n");
            continue;
        }

        switch (choice)
        {
            case 1: push_manual(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: isempty(); break;
            case 6: isfull(); break;
            case 0:
                free_stack();
                return 0;
            default:
                printf("\033[31mInvalid option!\033[0m\n");
        }
    }

    return 0;
}

