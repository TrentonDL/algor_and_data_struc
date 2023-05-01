// Trenton Laule        1001669855 //
// compile using:       gcc -g -std=c99 -o courses_graph courses_graph.c
// run using:           ./courses_graph "user inputed filename"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSE_LENGTH 30
#define MAX_FILENAME_LENGTH 30
#define FILELINE_SIZE 1000

//Function prototypes

//Parameters: 
    // argc = input strings in command line
    // argv = input strings array
FILE * openFile(int argc, char *argv[]);

typedef struct CourseRequirements {
    char *name;
    char **prereqs;
    int prereqCount;
}CourseRequirements;

int main(int argc, char *argv[]){
    FILE *fp = NULL;
    char fileline[FILELINE_SIZE] = {};
    char *Token = NULL;
    char *delims = " ";
    char *newline;
    int course_counter = 0;
    CourseRequirements **courses = NULL;
    
    fp = openFile(argc, argv);

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

    for (int i=0; i < course_counter; i++) {
        printf("In print for %d\n", i);
        printf("Course %s has the following prereqs:\n", courses[i]->name);
        for (int j=0; j < courses[i]->prereqCount; j++) {
            printf("%s\n", courses[i]->prereqs[j]);
        }
        printf("Finished prereqs\n");
        printf("\n");
    }
    return EXIT_SUCCESS;
}

//Parameters: 
    // argc = input strings in command line
    // argv = input strings array
FILE * openFile(int argc, char *argv[]){
    char filename[MAX_FILENAME_LENGTH + 1] = {};
    FILE * filePtr = NULL;

    if(argc == 2){
        strcpy(filename, argv[1]);
    }
    else{
        printf("File must be used in running the code\n");
        printf("Enter a Filename here: ");
        scanf("%s", filename);
    }
    
    filePtr = fopen(filename, "r");
    if(filePtr == NULL){
        printf("Error: Could not open \"%s\"! . . . Exiting\n");
        exit(-EXIT_FAILURE);
    }

    return filePtr;
}