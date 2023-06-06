#include <stdio.h>
#define SIZE1 7

int count_ret(int * arr);
void count_update(int * arr, int *count);
int count_ret_2(int sz, int * arr);

int main()
{
    int arr1[SIZE1] = {10, 6, -2, 9, -7, -8, 12};
    int count1 = -1;

    count1 = count_ret(arr1);
    printf("count1 = %d\n", count1);

    int count2 = -1;
    count_update(arr1, &count2);
    printf("count2 = %d\n", count2);
    return 0;
}

int count_ret(int * arr)
{
    int count = 0;

    for(int i = 0; i < SIZE1; i++)
    {
        if (arr[i] < 0)
        {
            count++;
        }
    }

    return count;
}

void count_update(int * arr, int *count)
{
    (*count) = 0;
    for(int i = 0; i < SIZE1; i++)
    {
        if (arr[i] < 0)
        {
            ++(*count);
        }
    }
}

int count_ret_2(int sz, int * arr)
{
    int count = 0;

    for(int i = 0; i < SIZE1; i++)
    {
        if (arr[i] < 0)
        {
            count++;
        }
    }

    return count;
}