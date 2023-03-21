#include <stdlib.h>
#include <stdio.h>

#include "heap.h"  

#define DEBUG 1
//#define DEBUG 0


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
	// write your code here
}


void sink_down(int i, int N, int * arr){
	// write your code here
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