#include <stdio.h>
#include <string.h>

// int main()
// {
//     #ifdef Woof
//         int Dog[] = {2, 3, 4, 10, 42, 47, 49, 50};
//     #else
//         int Dog[] = {2, 3, 4, 10, 11, 15, 40, 42, 47, 49};
//     #endif

//     int i = 0;
//     int sum = 0;
//     int Cat = sizeof(Dog)/sizeof(Dog[0]);

//     for(i = 0; i < Cat; i++)
//         sum += Dog[i];
    
//     printf("%d", sum);

//     return 0;
// }

int main()
{
    #ifdef Oranges
        char Apple[] = {"aDlGdHkWs2YUj1JJDfYal5alkdj"};
    #elif Pears
        char Apple[] = {"j1JJDfYal5alkdjaDlGdHkWs2YU"};
    #else
        char Apple[] = {"j1JJDfjaDlGdHkWs2YUYal5alkd"};
    #endif

    int i = 0;

    for (i = 0; i < strlen(Apple); i++)
    {
        printf("%c", Apple[i]);
    }

    return 0;
}