// Trenton Laule    1001669855//
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
    if(argc < 2)
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

    return counter;
}

void swap(int * Swap1, int * Swap2)
{
    int temp = *Swap1;
    *Swap1 = *Swap2;
    *Swap2 = temp;
}

int partition(int * AP, int low, int high)
{
    int i, j = 0;

    #if QSM
    int middle = (high+low)/2;
    swap(&AP[middle], &AP[high]);
    #elif QSRND
    int random = (rand() % (high-low+1)) + low;
    swap(&AP[random], &AP[high]);
    #endif

    int pivot = AP[high];

    i = (low - 1);

    for(j = low; j < high; j++)
    {
        if(AP[j] < pivot)
        {
            i++;
            swap(&AP[i], &AP[j]);
        }
    }
    swap(&AP[i + 1], &AP[high]);

    return (i + 1);
}

void quickSort(int * AP, int low, int high)
{
    if (low < high)
    {
        int idx = partition(AP, low, high);

        quickSort(AP, low, idx - 1);
        quickSort(AP, idx + 1, high);
    }
}

int main(int argc, char *argv[])
{
    clock_t start, end;
    int *AP;
    int runs, n;

    if(argc != 3)
    {
        printf("Number of runs not specified on command line...defaulting to 10\n");
        runs = 10;
    }
    else
    {
        runs = atoi(argv[2]);
    }

    int r;
    long total_tics = 0;
    for(r=0; r<runs; r++)
    {
        n = ReadFileIntoArray(argc, argv, &AP);

        #ifdef PRINTARRAY
        printArray(AP, n);
        #endif
        
        start = clock();
        quickSort(AP, 0, n-1);
        end = clock();

        #ifdef PRINTARRAY
        printArray(AP, n);
        #endif

        printf("Run %d complete : %ld tics\n", r, (end - start));

        total_tics += (end - start);
        free(AP);
        n = 0;
    }
    printf("The average run time for %d runs is %ld\n", runs, (total_tics/(long)runs));

    printf("\n\nProcessed %d records\n", n);
    return 0;
}