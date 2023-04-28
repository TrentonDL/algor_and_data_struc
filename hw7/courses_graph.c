// Trenton Laule        1001669855 //
// compile using:       gcc -g -std=c99 -o courses_graph courses_graph.c
// run using:           ./courses_graph "user inputed filename"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSE_LENGTH 30
#define FILELINE_SIZE 1000
#define MAX_NUM_COURSES 100

//Function prototypes
FILE * openFile(int argc, char *argv[]);

int main(int argc, char *argv[]){
    FILE *fp = NULL;
    char fileline[FILELINE_SIZE] = {};
    char *Token = NULL;
    char *delims = " \n";
    int course_counter = 0;
    int vertex_counter = 0;
    char *courses[MAX_NUM_COURSES] = {};
    

    fp = openFile(argc, argv);

    while (fgets(fileline, FILELINE_SIZE, fp) != NULL){
        Token = strtok(fileline, delims);
        courses[course_counter] = Token;
        
        do{
            Token = strtok(NULL,delims);
            if(Token != NULL){
                courses[course_counter][vertex_counter] = (char*) malloc(strlen(Token) * sizeof(char));
                strcpy(courses[course_counter][vertex_counter], Token);
                vertex_counter++;
            }

        }while(Token != "\n");
        course_counter++;
    }
    return EXIT_SUCCESS;
}

//Parameters: 
    // argc = input strings in command line
    // argv = input strings array
FILE * openFile(int argc, char *argv[]){
    char filename[MAX_COURSE_LENGTH + 1] = {};
    char course_name[MAX_COURSE_LENGTH + 1] = {};
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