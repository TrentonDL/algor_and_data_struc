#include <stdio.h>
#include <stdlib.h>

void test_local();
void print_2D_1(int rows, int cols, int arr2d[][cols]);

int main()
{
    test_local();
    return 0;
}

void test_local()
{
    char fname[101];
    printf("Enter a filename: ");
    scanf("%s", fname);
    FILE * fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Failed to open file %s", fname);
        exit(0);
    }

    int rows, cols;

    fscanf(fp, "%d", &rows);
    fscanf(fp, "%d", &cols);

    int arr2D[rows][cols];

    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            fscanf(fp, "%d", &arr2D[r][c]);
        }
    }

    fclose(fp);
    print_2D_1( rows, cols, arr2D);
}

void print_2D_1(int rows, int cols, int arr2d[][cols])
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            printf("\t%d", arr2d[r][c]);
        }
        printf("\n");
    }
}

//int * arr2d = malloc(sizeof(int) * rows * cols)