// Trenton Laule    1001669855 //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void openFile(FILE ** fp, char * filename)
{
	*fp = fopen(filename, "r");
	if(fp == NULL)
	{
		printf("\nFile \"%s\" failed to open...exiting\n", filename);
		exit(-1);
	}
}

void printArray(int * arr[], int sizeArr)
{
    for(int i = 0; i < sizeArr; i++)
        printf("%d\n", arr[i]);
    
    printf("\n");
}

int ReadFileIntoArray(int argc, char *argv[], int **AP)
{
    if(argc != 2)
	{
		printf("File must be provided on command line...exiting\n");
		exit(-1);
	}

	FILE * fp;
	openFile(&fp, argv[1]);

    int counter = 0;
    char buffer[100];

    while (fgets(buffer,99,fp) != NULL)
    {
        counter++;
    }
    printf("intilize Ap\ncounter = %d\n", counter);
    *AP = malloc(counter * sizeof(int));
    printf("sizeof ap = %d\n", sizeof(*AP));
    printf("malloc complete\n");
    fseek(fp, 0.0, SEEK_SET);
    printf("fseek\n");

    for(int i=0; i<counter; i++)
    {
        printf("AP[%d] - %d\n", i, *AP[i]);
        
        fgets(buffer,99,fp);
        printf("attempting to put %d into array - %d\n", atoi(buffer), i);
        *AP[i] = atoi(buffer);
        printf("%d - AP[%d]\n", *AP[i], i);
    }

    printArray(AP, counter);

    return counter;
}

void insertionSort(int * A[], int n)
{
    int i, key, j;

    for( j = 1; j <n; j++ )
    {
        key = *A[j];
        i = j - 1;

        while (i >= 0 && *A[i] > key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        *A[i + 1] = key;
    }
}

int main(int argc, char *argv[])
{
    clock_t start, end;
    int *AP = NULL; 

    int elements = ReadFileIntoArray(argc, argv, &AP);

    insertionSort(&AP, elements);
    printArray(&AP, elements);

    return 0;
}