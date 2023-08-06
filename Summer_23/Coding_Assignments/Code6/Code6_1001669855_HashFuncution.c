#include <stdio.h>
#include <string.h>

#define HASTABLESIZE 10

int HashFunction(char HashValue[])
{
    int string_len = strlen(HashValue);
    int i, sum = 0;

    for(i = 0; i<string_len; i++)
    {
        sum += HashValue[i];
    }
    //printf("%d\n", sum);
    return sum % HASTABLESIZE;
}

int main()
{
    char HashValue[50] = {};
    printf("Enter a name of a RollerCoaster: ");
    scanf("%s", HashValue);
    printf("The hash value for %s is %d\n", HashValue, HashFunction(HashValue));
}
