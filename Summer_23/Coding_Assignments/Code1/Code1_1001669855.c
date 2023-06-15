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

void AddNodeToLL(int Number, NODE **LinkedListHead)
{
}

void ReadFileIntoLL(int argc,  char *argv[], NODE **LLH)
{
}

void PrintLL(NODE *LLH) 
{ 
}

void FreeLL(NODE **LLH) 
{ 
}

int main(/* add argc and argv */) 
{ 
	NODE *LLH = NULL;
	
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
