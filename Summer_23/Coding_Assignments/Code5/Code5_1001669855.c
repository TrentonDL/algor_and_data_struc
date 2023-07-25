#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 50

struct Vertex
{
    int idx;
    char label[6];
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

int populateAdjMatrix(int AdjacencyMatrix[][], char * argv[], struct Vertex * VertexArray[])
{
	FILE * fp;
	openFile(&fp, argv[1]);

	int vertexCount = 0;
	char buffer[100];

	while (fgets(buffer,99,fp) != NULL)
	{
		++vertexCount;
	}

	if(vertexCount > MAX)
	{
		printf("Too many vertexes, please try a different file.\n. . .Exiting\n");
		exit(-1);
	}
	int AdjMatrix[vertexCount][vertexCount];
	fseek(fp, 0.0, SEEK_SET);
	memset(AdjMatrix, -1, (vertexCount*vertexCount));

	int i = 0;

	char *Token = NULL;
	int vert;
	int weight;

	while(fgets(buffer, 99, fp) != NULL)
	{
		if(buffer[strlen(buffer)-1] == '\n')
			buffer[strlen(buffer)-1] = '\0';
		
		Token = strtok(buffer, ",");
		strcpy(Token,VertexArray[i]->label);
		VertexArray[i]->idx = i;
		VertexArray[i]->visted = 0;
		VertexArray[i]->distance = INT_MAX;

		while(Token != NULL)
		{
			Token = strtok(NULL, ",");
			vert = atoi(Token);
			Token = strtok(NULL, ",");
			weight = atoi(Token);
			AdjMatrix[i][vert] = weight;
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
	struct Vertex VertexArray[MAX] = {};
	int vertexCount = populateAdjMatrix(AdjacencyMatrix, argv, &VertexArray);

	char starting_vertex;
    char dest_vertex;
	printf("What is the starting vertex? ");
	scanf(" %c", &starting_vertex);

	printf("What is the destination vertex? ");
	scanf(" %c", &dest_vertex);

    return 0;
}