#include <stdio.h>
#include <stdlib.h>

void FunctionR(int Z[], int a, int b)
{
    if(a < b)
        return;

    printf("%d-", Z[1]+Z[3]);
    Z[2] = Z[4];

    FunctionR(Z, Z[1], Z[3]);
}

int main()
{
    int A[] = {848, 123, 687, 981, 532};

    FunctionR(A, A[2], A[4]);
    return 0;
}