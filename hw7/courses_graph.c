// Trenton Laule        1001669855 //
// compile using:       gcc -g -std=c99 -o courses_graph courses_graph.c
// run using:           ./courses_graph

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSE_LENGTH 30
#define MAX_FILENAME_LENGTH 30
#define FILELINE_SIZE 1000

typedef struct CourseRequirements {
    char *name;
    char **prereqs;
    int prereqCount;
}CourseRequirements;

int findVertice(CourseRequirements **courses, char *name, int courseCount) {
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printVertices(int*vertices, int size) {
    printf("Adjacency Matrix:\n");
    printf("    |");
    for (int d = 0; d < size; d++) {
        printf("%4d", d);
    }
    printf("\n");
    for (int d = 0; d < size+1; d++) {
        printf("----");
    }
    printf("-\n");
    for (int i = 0; i < size; i++) {
        printf("%4d|",i);
        for (int j=0; j < size; j++) {
            printf("%4d", vertices[i*size+j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int vertice, int size, int *vertices, int *depth, int *queue, int *queueSize) {
    depth[vertice*(sizeof(int))] = 1;
    for (int i = 0; i < size; i++) {
        if (i != vertice && vertices[vertice*size+i] == 1 && depth[i*sizeof(int)] == 0) {
            dfs(i, size, vertices, depth, queue, queueSize);
        }
    }
    printf("Adding %d to queue index %d\n", vertice, *queueSize);
    queue[*queueSize] = vertice;
    *queueSize += 1;
}

void dfs_visit(int *vertices, int vertice, int size, char *color, int *pred, int *result, int *resultCount) {
    color[vertice] = 'G';
    for (int y = 0; y < size; y++) {
        if(vertices[vertice*size+y] == 1){
            if (y != vertice && y != pred[vertice]) {
                if (color[y] == 'W') {
                    pred[y] = vertice;
                    dfs_visit(vertices, y, size, color, pred, result, resultCount);
                }
                else if (color[y] == 'G') {
                    printf("We have a cycle %d %d\n", vertice, y);
                }
            }
            else{
                printf("There was at least one cycle. there is no possible ordering of the courses.\n");
                *resultCount = 0;
                return;
            }
        }

    }
    color[vertice] = 'B';
    result[*resultCount] = vertice;
    *resultCount += 1;
}

void dfs_start(int *vertices, int size, int *result, int *resultCounter) {
    // int result[size];
    // int resultCount = 0;
    char color[size+1];
    int pred[size];
    for (int u = 0; u < size; u++) {
        color[u] = 'W';
        pred[u] = -1;
    }
    for (int u = 0; u < size; u++) {
        if (color[u] == 'W') {
            dfs_visit(vertices, u, size, color, pred, result, resultCounter);
        }
    }
}


FILE * openFile(){
    char filename[MAX_FILENAME_LENGTH + 1] = {};
    FILE * filePtr = NULL;

    printf("This program will read, from a file, a list of courses and their prerequisites and will print the list in which to take courses\n");
    printf("Enter filename: ");
    scanf(" %s", filename);

    filePtr = fopen(filename, "r");
    if(filePtr == NULL){
        printf("Error: Could not open \"%s\"! . . . Exit\n");
        printf("\nFailed to read from file. Program will terminate.\n");
        exit(-EXIT_FAILURE);
    }

    return filePtr;
}

int main(){
    FILE *fp = NULL;
    char fileline[FILELINE_SIZE] = {};
    char *Token = NULL;
    char *delims = " ";
    char *newline;
    int course_counter = 0;
    CourseRequirements **courses = NULL;
    
    fp = openFile();

    while (fgets(fileline, FILELINE_SIZE, fp) != NULL){
        char* vertex[] = {};
        char *newline = strchr(fileline, '\n');
        if(newline){
            *newline = 0;
        }
        courses = (CourseRequirements**)realloc(courses, (course_counter+1) * sizeof(CourseRequirements*));
        courses[course_counter] = malloc(sizeof(CourseRequirements));
        int vertex_counter = 0;

        Token = strtok(fileline, delims);
        courses[course_counter]->name = malloc((strlen(Token)+1) * sizeof(char));
        strcpy(courses[course_counter]->name, Token);
        courses[course_counter]->prereqs = NULL;
        courses[course_counter]->prereqCount = 0;

        do{
            Token = strtok(NULL, delims);
            if(Token != "\0" && Token != NULL){
                courses[course_counter]->prereqs = (char**)realloc(courses[course_counter]->prereqs, (courses[course_counter]->prereqCount+1) * sizeof(char*));
                courses[course_counter]->prereqs[courses[course_counter]->prereqCount] = (char*) malloc((strlen(Token)+1) * sizeof(char));
                strcpy(courses[course_counter]->prereqs[courses[course_counter]->prereqCount], Token);
                courses[course_counter]->prereqCount++;
            }
        }while(Token != "\0" && Token != NULL);

        course_counter++;
    }
    fclose(fp);

    printf("Number of vertices in built graph: N = %d\n", course_counter);
    printf("Vertex - coursename correspondence\n");
    int *vertices = malloc((course_counter * course_counter) * sizeof(int));
    memset(vertices, 0, (course_counter * course_counter) * sizeof(int));
    for(int i = 0; i < course_counter; i++){
        for (int j = 0; j < courses[i]->prereqCount; j++) {
            int vertice = findVertice(courses, courses[i]->prereqs[j], course_counter);
            if (vertice != -1) {
                vertices[vertice*course_counter+i] = 1;
            }
        }

        printf("%d - %s\n", i, courses[i]->name);
    }
    printf("\n");
    printVertices(vertices, course_counter);
    int result[course_counter];
    int resultCounter;
    dfs_start(vertices, course_counter, result, &resultCounter);
    int i = 1;
    for (int z = resultCounter - 1; z >=0; z--) {
        printf("%d. - %s (corresponds to graph vertex %d)\n",i, courses[result[z]]->name, result[z]);
        i++;
    }

    free(vertices);

    for(int j=0; j<course_counter;j++){
        free(courses[j]);
    }
    
    return EXIT_SUCCESS;
}