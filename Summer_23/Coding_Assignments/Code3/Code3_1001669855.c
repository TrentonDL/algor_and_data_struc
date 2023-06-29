#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void openFile(FILE ** fp, char *filename)
{
	*fp = fopen(filename, "r");
	if(fp == NULL)
	{
		printf("\nFile \"%s\" failed to open...exiting\n", filename);
		exit(-1);
	}
}

void printArray(int arr[], int sizeArr)
{
    int i;
    for(i = 0; i < sizeArr; i++)
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

    *AP = malloc(sizeof(int) * counter);
    fseek(fp, 0.0, SEEK_SET);
    int i;
    for(i=0; i<counter; i++)
    {
        fgets(buffer,99,fp);
        (*AP)[i] = atoi(buffer);
    }
    fclose(fp);
    #ifdef PRINTARRAY
    printArray(*AP, counter);
    #endif

    return counter;
}

void insertionSort(int * A, int n)
{
    int i, key, j;

    for( j = 1; j <n; j++ )
    {
        key = A[j];
        i = j - 1;

        while (i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

int main(int argc, char *argv[])
{
    clock_t start, end;
    int *AP;

    int n = ReadFileIntoArray(argc, argv, &AP);

    start = clock();
    insertionSort(AP, n);
    end = clock();
    
    #ifdef PRINTARRAY
    printArray(AP, n);
    #endif

    printf("Processed %d records\n", n);
    printf("Insertion Sort = %ld Tics\n",(end-start));
    free(AP);
    AP = NULL;
    n = 0;

    n = ReadFileIntoArray(argc, argv, &AP);

    start = clock();
    
    end = clock();

    printf("Merge Sort = %ld Tics\n",(end-start));
    free(AP);
    AP = NULL;
    return 0;
}