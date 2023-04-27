// Trenton Laule        1001669855 //
// compile using:       gcc -g -std=c99 -o courses_graph courses_graph.c
// run using:           ./courses_graph "user inputed filename"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSE_LENGTH 30

//Function prototypes
FILE * openFile(int argc, char *argv[]);

int main(int argc, char *argv[]){
    FILE *fp = NULL;

    fp = openFile(argc, argv);
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