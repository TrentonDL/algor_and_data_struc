#include <stdio.h>

void insertionSort(int A[], int n)
{
    int i, key, j;

    for( j = 1; j <n; j++ )
    {
        key = A[j];
        //printf("%d - key \t j = %d\n", key, j);
        i = j - 1;

        while (i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
        printf("%d - i \t j = %d\n", i, j);
    }
}

int main(){
    int arr[] = {32,9,13,11,56,1,2,0};

    int arr_size = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,arr_size);
}