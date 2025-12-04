// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <unistd.h>
// #include "header.h"
// 
// int safe_int_input(int *var)
// {
//     if (scanf("%d", var) != 1)
//     {
//         printf("\033[31mInvalid input! Program terminated.\033[0m\n");
//         return 0;
//     }
//     return 1;
// }
// 
// int main()
// {
//     srand(time(NULL));
// 
//     int mode;
//     printf("\033[33m1) Manual Mode\n2) Auto Mode\033[0m\n");
// 
//     if (!safe_int_input(&mode))
//         return 0;
// 
//     if (mode == 1)
//     {
//         int choice;
//         do
//         {
//             printf("\033[32m1) push\n2) pop\n3) peek\n4) display\n5) isempty\n6) isfull\n0) exit\033[0m\n");
// 
//             if (!safe_int_input(&choice))
//                 return 0;
// 
//             switch (choice)
//             {
//                 case 1: push_manual(); break;
//                 case 2: pop_value(); break;
//                 case 3: peek(); break;
//                 case 4: display(); break;
//                 case 5: isempty(); break;
//                 case 6: isfull(); break;
//                 case 0: break;
//                 default: printf("\033[31mInvalid Choice\033[0m\n");
//             }
// 
//         } while (choice != 0);
//     }
// 
//     else if (mode == 2)
//     {
//         int cycles;
//         printf("Enter number of random operations: ");
// 
//         if (!safe_int_input(&cycles))
//             return 0;
// 
//         for (int i = 0; i < cycles; i++)
//         {
//             int choice = (rand() % 6) + 1;
// 
//             printf("\033[33m\n[AUTO] Operation %d: ", i + 1);
// 
//             switch (choice)
//             {
//                 case 1: printf("PUSH\033[0m\n"); push_auto(); break;
//                 case 2: printf("POP\033[0m\n"); pop_value(); break;
//                 case 3: printf("PEEK\033[0m\n"); peek(); break;
//                 case 4: printf("DISPLAY\033[0m\n"); display(); break;
//                 case 5: printf("ISEMPTY\033[0m\n"); isempty(); break;
//                 case 6: printf("ISFULL\033[0m\n"); isfull(); break;
//             }
// 
//             sleep(1);
//         }
//     }
//     else
//     {
//         printf("\033[31mInvalid mode\033[0m\n");
//     }
// 
//     return 0;
// }
//









#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int choice;

    do
    {
        printf("\n\033[32m1] push\n2] pop\n3] peek\n4] display\n5] isempty\n6] isfull\n0] exit\033[0m\n");
        printf("Enter choice: ");

        if (!safe_int_input(&choice))
            continue;

        switch (choice)
        {
            case 1: push_manual(); break;
            case 2: pop_value(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: isempty(); break;
            case 6: isfull(); break;
            case 0: printf("Exiting...\n"); break;
            default:
                printf("\033[31mInvalid Option!\033[0m\n");
        }

    } while (choice != 0);

    return 0;
}

