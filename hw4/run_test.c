// Trenton Laule        1001669855 //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE * fp = NULL;
    char filename[50] = {};
    char fileline[101] = {};
    char *Token = NULL;
    int P = 0;
    int N = 0;

    printf("Enter a Filename: ");
    scanf(" %s", filename);

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("File Failed to open! Exiting...\n");
        exit(0);
    }

    fscanf(fp, "%d", N);
    int *val = calloc(N, sizeof(int));
    for(int i = 0; i < N; i++){
        fscanf(fp, "%d", val[i]);
    }
    
    fscanf(fp, "%d", P);
    
    fgets(fileline, sizeof(fileline)-1, fp);
    
    while(Token != "\n"){
        Token = strtok(fileline, " ");
        strcpy()
    }
    strtok()
    return 0;
}