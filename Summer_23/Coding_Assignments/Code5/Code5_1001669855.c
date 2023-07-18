#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Vertex
{
    int idx;
    char Label;
    int distance;
    int previous;
    int visted;
};

void openFile(FILE ** fp, char *filename)
{
	*fp = fopen(filename, "r");
	if(*fp == NULL)
	{
		printf("File \"%s\" failed to open...exiting\n", filename);
		exit(-1);
	}
}

int main(int argc, char * argv[])
{
    if(argc < 2)
	{
		printf("File must be provided on command line...exiting\n");
		exit(-1);
	}
    
    return 0;
}