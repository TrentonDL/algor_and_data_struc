// Trenton Laule        1001669855 //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "heap.h"

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
        fscanf(fp, "%d", &val[i]);
    }
    
    struct heap_struct heap = make_heap(N, val);

    free(val);

    print_heap(heap);
    
    fscanf(fp, "%d", P);

    for(int j = 0; j < P; j++){
        char operation[10];
        fscanf(fp, "%s ", operation);
        if(isdigit(operation[0])){
            add(&heap, atoi(operation));
            print_heap(heap);
        }
        else{
            switch(operation[0]){
                case '*':
                    poll(&heap);
                    print_heap(heap);
                    break;
                case 'P':
                    peek(heap);
                    print_heap(heap);
                    break;
                case 'p':
                    peek(heap);
                    print_heap(heap);
                    break;
                default:
                    printf("Invaild operation\n");
                    break;
            }
        }
    }
    fclose(fp);

    destroy(&heap);
    
    return 0;
}