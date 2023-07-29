#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 50

typedef struct 
{
    int idx;
    char label[6];
    int distance;
    int previous;
    int visited;
}
Vertex;

void openFile(FILE ** fp, char *filename)
{
	*fp = fopen(filename, "r");
	if(*fp == NULL)
	{
		printf("File \"%s\" failed to open...exiting\n", filename);
		exit(-1);
	}
}

void printArray(int AdjMatrix[MAX][MAX], int VertexCount)
{
	int i, j;
	printf("\n");
	for(i = 0; i < VertexCount; i++)
	{
		for(j = 0; j < VertexCount; j++)
			printf("%5d\t", AdjMatrix[i][j]);
		printf("\n");
	}
}

int populateAdjMatrix(int AdjacencyMatrix[MAX][MAX], char * argv[], Vertex VertexArray[])
{
	FILE * fp;
	openFile(&fp, argv[1]);

	int vertexCount = 0;
	char buffer[100];

	while (fgets(buffer,99,fp) != NULL)
	{
		vertexCount++;
	}

	if(vertexCount > MAX)
	{
		printf("Too many vertexes, please try a different file.\n. . .Exiting\n");
		exit(-1);
	}
	
	fseek(fp, 0.0, SEEK_SET);
	
	int j;
	for(j = 0; j < vertexCount; j++)
		memset(AdjacencyMatrix[j], -1, sizeof(int)*(vertexCount));

	#ifdef PRINTIT
	printArray(AdjacencyMatrix, vertexCount);
	#endif

	int i = 0;

	char *Token = NULL;
	int vert;
	int weight;

	while(fgets(buffer, 99, fp) != NULL)
	{
		if(buffer[strlen(buffer)-1] == '\n')
			buffer[strlen(buffer)-1] = '\0';
		
		Token = strtok(buffer, ",");
		strcpy(VertexArray[i].label, Token);
		VertexArray[i].idx = i;
		VertexArray[i].visited = 0;
		VertexArray[i].distance = INT_MAX;

		Token = strtok(NULL, ",");

		while(Token != NULL)
		{
			vert = atoi(Token);
			Token = strtok(NULL, ",");
			weight = atoi(Token);
			AdjacencyMatrix[i][vert] = weight;
			Token = strtok(NULL, ",");
		}
		i++;
	}

	return vertexCount;
}

int main(int argc, char * argv[])
{
    if(argc < 2)
	{
		printf("File must be provided on command line...exiting\n");
		exit(-1);
	}

	int AdjacencyMatrix[MAX][MAX] = {};
	Vertex VertexArray[MAX] = {};
	int vertexCount = populateAdjMatrix(AdjacencyMatrix, argv, VertexArray);
	
	#ifdef PRINTIT
	printArray(AdjacencyMatrix,vertexCount);
	#endif

	char starting_vertex[6];
    char dest_vertex[6];
	printf("What is the starting vertex? ");
	scanf(" %s", starting_vertex);

	printf("What is the destination vertex? ");
	scanf(" %s", dest_vertex);



    return 0;
}