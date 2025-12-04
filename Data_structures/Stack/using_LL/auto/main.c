#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "header.h"

int main()
{
    srand(time(NULL));

    int cycles = (rand() % 15) + 5;
    // Random operations count (between 5 and 20)

    printf("\n\033[33m[AUTO MODE] Total Random Operations: %d\033[0m\n\n",
           cycles);

    for (int i = 0; i < cycles; i++)
    {
        int choice = (rand() % 6) + 1;

        printf("\033[33m[AUTO] Operation %d: ", i + 1);

        switch (choice)
        {
            case 1: printf("PUSH\033[0m\n"); push_auto(); break;
            case 2: printf("POP\033[0m\n"); pop_value(); break;
            case 3: printf("PEEK\033[0m\n"); peek(); break;
            case 4: printf("DISPLAY\033[0m\n"); display(); break;
            case 5: printf("ISEMPTY\033[0m\n"); isempty(); break;
            case 6: printf("ISFULL\033[0m\n"); isfull(); break;
        }

        sleep(1);
    }

    return 0;
}

