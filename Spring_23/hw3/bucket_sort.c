//      Trenton Laule 1001669855        //

/* 
compile with -g to collect debugging info needed for Valgrind ( -lm links the math library): 
gcc -g bucket_sort.c list.c -lm

run with Valgrind:
valgrind --leak-check=full ./a.out

On some systems, but not all, you can also use the --show-leak-kinds=all flag:
valgrind --leak-check=full --show-leak-kinds=all ./a.out

run without Valgrind:
./a.out
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "list.h"   // useful if you want to use functions from list.c

void print_array(int arr[], int N);
void run1();

/* 
// function to insert a new node in a sorted list. E.g.: 
nodePT insert_sorted(nodePT L, nodePT newP);
//or
nodePT insert_sorted(nodePT L, int elem);
*/
//  function to sort an array sing bucket sort. E.g.:
void bucket_sort(int * arr, int N);

//function to find max value in given array
void find_Max_Value(int * arr, int N, int * maxValue);
//function to find minimum value in given array
void find_Min_Value(int * arr, int N, int * minValue);

void list_2_array(int *arr, int N, nodePT * bucket_array);

void print_array(int arr[], int N){
	int j;
	printf("\n array: ");
	for(j= 0; j<N; j++){
		printf("%5d,", arr[j]);
	}
	printf("\n");
}

//-------------------------------------------------------------

void run1(){
    FILE* fp = NULL;
    char filename[51] = "\0";
    int arr[10000];
    int N = 0;

	printf("\nEnter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("File could not be opened.\n");
        return;
    }

    fscanf(fp, "%d ", &N);
    for (int i = 0; i < N; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    print_array(arr, N);

    bucket_sort(arr, N);
}

int main()
{
	printf("This program will read a file name, load data for an array from there and print the sorted array.\n");
	printf("The array is sorted using bucket sort.\n");
	printf("This will be repeated as long as the user wants.\n");
	int option;
	do {
		run1();
		printf("\nDo you want to repeat? Enter 1 to repeat, or 0 to stop) ");
		char ch;
		scanf("%d%c",&option, &ch);  // ch is used to remove the Enter from the input buffer
 	} while (option == 1);

   return 0;
}

void bucket_sort(int * arr, int N){
    int maxValue =  -(__INT_MAX__);
    find_Max_Value(arr, N, &maxValue);
    
    int minValue = (__INT_MAX__);
    find_Min_Value(arr, N, &minValue);
    int idx = 0;
    nodePT bucket_array[N];
    
    for (int j = 0; j < N; j++)
    {
        bucket_array[j] = NULL;
    }
    
    printf("\nBucketsort: min = %d, max = %d, N = %d buckets\n", minValue, maxValue, N);
    
    for (int i = 0; i < N; i++)
    {
        nodePT newNode = new_node(arr[i]);
        idx = (int)floor(((long)N * ((long) arr[i] - (long) minValue))/(1+(long)maxValue-(long)minValue));
        
        if(bucket_array[idx] == NULL){
            bucket_array[idx] = newNode;
        }
        else{
            nodePT curr = bucket_array[idx];
            nodePT prev = NULL;
            while(curr != NULL && curr->data < arr[i]){
                prev = curr;
                curr = curr->next;
            }
            bucket_array[idx] = insert_node(bucket_array[idx], prev, newNode);
        }
        printf("arr[%d]=%5d, idx = %d\n", i,arr[i], idx);

    }
    for(int k = 0; k < N; k++){
        printf("------ List at index %d :", k);
        print_list_horiz(bucket_array[k]);
    }

    list_2_array(arr, N, bucket_array);
}

void find_Max_Value(int * arr, int N, int * maxValue){
    for(int i = 0; i < N; i++){
        if(arr[i] > *maxValue){
            *maxValue = arr[i];
        }
    }
}


void find_Min_Value(int * arr, int N, int * minValue){
    for(int i = 0; i < N; i++){
        if(arr[i] < *minValue){
            *minValue = arr[i];
        }
    }
}

void list_2_array(int *arr, int N, nodePT * bucket_array){
    int array_idx = 0;
    for(int i = 0; i < N; i++){
        nodePT curr = bucket_array[i];
        
        while (curr != NULL)
        {
            arr[array_idx] = curr->data;
            curr = curr->next;
            array_idx++;
        }
        destroy_list(bucket_array[i]);
    }
    
    print_array(arr, N);
}