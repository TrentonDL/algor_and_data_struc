// Trenton Laule        1001669855 //

#include <stdlib.h>
#include <stdio.h>

#include "heap.h"  

#define DEBUG 1
//#define DEBUG 0
int idx_of_max_Value(int *arr, int p, int left, int right, int N);

/*
// uncomment and write your code
struct heap_struct make_heap_empty(int cap){
}

struct heap_struct make_heap(int N, int * arr){
}
*/

void destroy(struct heap_struct * heapP){
	// write your code here
}


void print_heap(struct heap_struct heapS){
	// write your code here
}


void swim_up(int idx, int * arr){
	while((idx > 1) && (arr[idx] > arr[idx/2])){
        int temp = arr[idx];
        arr[idx] = arr[idx/2];
        arr[idx/2] = temp;
    }
}


void sink_down(int i, int N, int * arr){
	int left_idx = 2*i;
    int right_idx = (2*i)+1;
    struct heap_struct heap = make_heap(N, arr);
    int idx_max_value = peek(heap);
    while((idx_max_value != i) && (idx_max_value<=N)){
        int temp = arr[i];
        arr[i] = arr[idx_max_value];
        arr[idx_max_value] = temp;
        i = idx_max_value;
        left_idx = 2*i;
        right_idx = (2*i)+1;

    }
}

void add(struct heap_struct * heapP, int new_item){
	// write your code here
}

int peek(struct heap_struct heapS){
	printf("\npeek placeholder, returns -1\n");
	return -1;
}


int poll(struct heap_struct * heapP){
	printf("\npoll placeholder, returns -1\n");
	return -1;
}

int idx_of_max_Value(int *arr, int p, int left, int right, int N){
    int idx_max_value = p;

    if((left<=N)&&(arr[left] > arr[idx_max_value])){
        idx_max_value = left;
    }

    if((right<=N) && (arr[right]>arr[idx_max_value])){
        idx_max_value = right;
    }

    return idx_max_value;
}