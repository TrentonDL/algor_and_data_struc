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

    *(AP) = malloc(counter * sizeof(int));
    fseek(fp, 0, 0);

    int i = 0;
    while (fgets(buffer,99,fp) != NULL)
    {
        *(AP[i]) = atoi(buffer);
        i++; 
    }
    printArray(*(AP), counter);

    return counter;
}

void printArray(int arr[], int sizeArr)
{
    for(int i = 0; i < sizeArr; i++)
        printf("%d\n", arr[i]);
    
    printf("\n");
}

int main(int argc, char *argv[])
{
    clock_t start, end;
    int *AP = NULL;

    int elements = ReadFileIntoArray(argc, argv, &AP);

    return 0;
}