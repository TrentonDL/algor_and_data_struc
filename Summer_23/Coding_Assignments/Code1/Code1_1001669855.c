/* Trenton Laule		1001669855 */
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <time.h>

typedef struct node
{
	int number;
	struct node *next_ptr;
}
NODE;

void openFile(FILE ** fp, char argv[])
{
	*fp = fopen(argv, "r");
	if(fp == NULL)
	{
		printf("\nFile \"%s\" failed to open...exiting\n", argv);
		exit(-1);
	}
}

void AddNodeToLL(int Number, NODE **LinkedListHead)
{
	NODE *temp, *prev, *newNode;
	temp = *LinkedListHead;
	prev = NULL;

	newNode = malloc(sizeof(NODE));
	newNode->next_ptr = NULL;
	newNode->number = Number;

	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next_ptr;
	}

	if(prev == NULL)
	{
		*LinkedListHead = newNode; 
	}
	else
	{
		prev->next_ptr = newNode;
	}
}

void ReadFileIntoLL(int argc,  char *argv[], NODE **LLH)
{
	if(argc != 2)
	{
		printf("File must be provided on command line...exiting\n");
		exit(-1);
	}

	FILE * fp;
	openFile(&fp, argv[1]);
	int num, sum;
	int counter = 0;
	char buffer[100];


	while(fgets(buffer, 99, fp) != NULL)
	{
		num = atoi(buffer);
		sum += num;
		AddNodeToLL(num, LLH);
		counter++;
	}

	fclose(fp);
	printf("\n%d records were read for a total sum of %d\n", counter, sum);
}

void PrintLL(NODE **LLH) 
{
	NODE *temp, *prev;
	int counter = 0, sum = 0;
	temp = *LLH;

	while (temp != NULL)
	{
		counter++;
		sum += temp->number;
		printf("\n%p %d %p\n", temp, temp->number, temp->next_ptr);
		temp = temp->next_ptr;
	}
	printf("\n%d records were read for a total sum of %d\n", counter, sum);	
}

void FreeLL(NODE **LLH) 
{
	NODE *temp, *prev;
	temp = *LLH;
	prev = NULL;
	int counter = 0, sum = 0;

	while(temp != NULL)
	{
		counter++;
		sum += temp->number;
		prev = temp;
		temp = temp->next_ptr;
		printf("\nFreeing %p %d %p\n", prev, prev->number, temp);
		free(prev);
	}
	printf("\n%d nodes were deleted for a total sum of %d\n",counter, sum);
	*LLH = NULL;
}

int main(int argc, char *argv[]) 
{
	NODE *LLH = NULL;
	clock_t start, end;
	
	start = clock();
	ReadFileIntoLL(argc, argv, &LLH);
	/* capture the clock in an end time */
	end = clock();
	printf("\n%ld tics to write the file into the linked list\n", end-start);
	
	#ifdef PRINT
		start = clock();
		/* capture the clock in a start time */
		PrintLL(&LLH);
		end = clock();
		/* capture the clock in an end time */
		printf("\n%ld tics to print the linked list\n", end-start);
	#endif

	start = clock();
	/* capture the clock in a start time */
	FreeLL(&LLH);
	/* capture the clock in an end time */
	end = clock();
	printf("\n%ld tics to free the linked list\n", end-start);
	
	return 0; 
} 
