#include <stdio.h>
#include <stdlib.h>

void FunctionR(int Z[], int a, int b, int e, int f)
{
    printf("%d-", Z[e]+Z[f]);

    if(a > b)
    {
        Z[e] -= Z[f];
        FunctionR(Z, Z[f+1], Z[e+1], f, e);
        printf("%d-", Z[f-1]+Z[e+1]);
    }
}

int main()
{
    int A[] = {1032, 687, 648, 765, 981};
    int x = 2, y = 3;

    FunctionR(A, A[0], A[1], x, y);
    
    return 0;
}