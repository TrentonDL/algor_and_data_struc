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
    heap->items = calloc(cap, sizeof(int *));
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
    heapP->capacity = 0;
    heapP->items = NULL;
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
	while((idx > 0) && (arr[idx] > arr[idx/2])){
        int temp = arr[idx];
        arr[idx] = arr[idx/2];
        arr[idx/2] = temp;
    }
}

void sink_down(int i, int N, int * arr){
	int left_idx = (2*i)+1;
    int right_idx = (2*i)+2;
    int idx_max_value = idx_of_max_value(arr, i, left_idx, right_idx, N);

    while((idx_max_value != i) && (idx_max_value<=N)){
        int temp = arr[i];
        arr[i] = arr[idx_max_value];
        arr[idx_max_value] = temp;
        i = idx_max_value;
        left_idx = (2*i)+1;
        right_idx = (2*i)+2;
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
        int *arr = calloc(2 * (heapP->capacity), sizeof(int));
        heapP->items = calloc(2 * (heapP->capacity), sizeof(int));
        arr = heapP->items;
        arr[heapP->N] = new_item;
        heapP->items = arr;
        swim_up(heapP->N, heapP->items);
        heapP->N += 1;
    }
    else{
        int *arr = calloc(heapP->capacity, sizeof(int));
        arr = heapP->items;
        arr[heapP->N] = new_item;
        heapP->items = arr;
        //*(heapP->items + heapP->N) = new_item;
        swim_up(heapP->N, heapP->items);
        heapP->N += 1;
    }
}

int peek(struct heap_struct heapS){
    int idxmv = 0;
    for(int idx = 0; idx < heapS.N; idx++){
        if(heapS.items[idx] > heapS.items[idxmv])
            idxmv = idx;
    }

	return idxmv;
}

int poll(struct heap_struct * heapP){
	int mx = heapP->items[0];
    heapP->items[0] = heapP->items[heapP->N];
    heapP->N -= 1;
    sink_down(0, heapP->N, heapP->items);

	return mx;
}