// Trenton Laule        1001669855 //

#include <stdlib.h>
#include <stdio.h>

#include "heap.h"  

#define DEBUG 1
//#define DEBUG 0

int idx_of_max_value(int *arr, int p, int left, int right, int N);

struct heap_struct make_heap_empty(int cap){
    struct heap_struct * heap;
    heap->capacity = cap;
    heap->N = 0;
    heap->items = calloc(cap, sizeof(int));
    heap->items = NULL;

    return *heap;
}

struct heap_struct make_heap(int N, int * arr){
    struct heap_struct heap;
    heap.capacity = sizeof(*arr) - 1;
    heap.N = N;
    heap.items = arr;
    
    return heap;
}

void destroy(struct heap_struct * heapP){
	free(heapP->items);
    heapP->N = 0;
}

void print_heap(struct heap_struct heapS){
    
    printf("Heap:  size: %d, capacity: %d\n", heapS.N, heapS.capacity);
    printf("indexes:");
    for(int i = 0; i < heapS.N; i++){
        printf("%6d,", i);
    }
    printf("\nvalues:");
    for(int i = 0; i < heapS.N; i++){
        printf("%6d,", heapS.items[i]);
    }
    printf("\n");
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
    int idx_max_value = idx_of_max_value(arr, i, left_idx, right_idx, N);

    while((idx_max_value != i) && (idx_max_value<=N)){
        int temp = arr[i];
        arr[i] = arr[idx_max_value];
        arr[idx_max_value] = temp;
        i = idx_max_value;
        left_idx = 2*i;
        right_idx = (2*i)+1;
        idx_max_value = idx_of_max_value(arr, i, left_idx, right_idx, N);
    }
}

int idx_of_max_value(int *arr, int p, int left, int right, int N){
    int idx_max_value = p;

    if((left<=N)&&(arr[left] > arr[idx_max_value])){
        idx_max_value = left;
    }

    if((right<=N) && (arr[right]>arr[idx_max_value])){
        idx_max_value = right;
    }

    return idx_max_value;
}

void add(struct heap_struct * heapP, int new_item){
	if(heapP->capacity < heapP->N){
        printf("Heap full cannot add item\n");
    }
    else{
        int idx = heapP->N;
        printf("idx created\n");
        heapP->items[idx] = new_item;
        printf("item added to end of heap\n");
        swim_up(idx, heapP->items);
        heapP->N++;
    }
}

int peek(struct heap_struct heapS){
	printf("\npeek placeholder, returns -1\n");
	return -1;
}

int poll(struct heap_struct * heapP){
	printf("\npoll placeholder, returns -1\n");
	return -1;
}