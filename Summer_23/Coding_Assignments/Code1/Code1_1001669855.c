/* Coding Assignment 1 */
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

void openFile(FILE * fp, char argv[])
{
	fp = fopen(argv, "r");
	if(fp == NULL)
	{
		printf("\nFile \"%s\" failed to open...exiting\n", argv);
		exit(-1);
	}
}

void AddNodeToLL(int Number, NODE **LinkedListHead)
{
}

void ReadFileIntoLL(int argc,  char *argv[], NODE **LLH)
{
	if(argc != 2)
	{
		printf("File must be provided on command line...exiting\n");
		exit(-1);
	}

	FILE * fp;
	openFile(fp, argv[1]);

	
}

void PrintLL(NODE *LLH) 
{ 
}

void FreeLL(NODE **LLH) 
{ 
}

int main(int argc, char *argv[]) 
{
	NODE *LLH = NULL;
	clock_t start, end;
	
	/* capture the clock in a start time */
	ReadFileIntoLL(argc, argv, &LLH);
	/* capture the clock in an end time */
	printf("\n%ld tics to write the file into the linked list\n", end-start);

	/* capture the clock in a start time */
	PrintLL(LLH);
	/* capture the clock in an end time */
	printf("\n%ld tics to print the linked list\n", end-start);
	
	/* capture the clock in a start time */
	FreeLL(&LLH);
	/* capture the clock in an end time */
	printf("\n%ld tics to free the linked list\n", end-start);
	
	return 0; 
} 
