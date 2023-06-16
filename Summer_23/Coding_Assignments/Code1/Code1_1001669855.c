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
	newNode->number = Number;
	printf("initialized\n");

	while (temp->next_ptr != NULL)
	{
		printf("while entered\n");
		prev = temp;
		temp = temp->next_ptr;
	}

	if(prev == NULL)
	{
		printf("if entered\n");
		*LinkedListHead = newNode; 
		printf("linked list head reassigned");
	}
	else
	{
		printf("else entered\n");
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
	int num;
	int counter = 0;
	char buffer[100];


	while(fgets(buffer, 99, fp) != NULL)
	{
		num = atoi(buffer);
		AddNodeToLL(num, LLH);
		counter++;
	}
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
	LLH = malloc(sizeof(NODE));
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
