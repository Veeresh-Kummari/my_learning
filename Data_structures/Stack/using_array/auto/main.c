#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "header.h"

int main()
{
    srand(time(NULL));

    init_stack();

    int cycles = (rand() % 11) + 5;   // number of random operations (5–15)
    printf("\033[33m[INFO] Total automatic operations: %d\033[0m\n", cycles);

    for (int i = 1; i <= cycles; i++)
    {
        int op = (rand() % 6) + 1;

        printf("\n\033[33m[OPERATION %d]: ", i);

        switch (op)
        {
            case 1: printf("AUTO PUSH\033[0m\n"); auto_push(); break;
            case 2: printf("POP\033[0m\n"); pop(); break;
            case 3: printf("PEEK\033[0m\n"); peek(); break;
            case 4: printf("DISPLAY\033[0m\n"); display(); break;
            case 5: printf("ISEMPTY\033[0m\n"); isempty(); break;
            case 6: printf("ISFULL\033[0m\n"); isfull(); break;
        }

        usleep(1000000); // 0.5 sec delay for better visualization
    }

    print_stats();
    free_stack();

    return 0;
}

