#include <stdio.h>

typedef struct node * nodePT;
struct node {
    int data;
    struct node * next;
};

void printLL(nodePT L){
    nodePT curr = L;
    
    while(curr != NULL){
        printf("%d", curr->data);
        curr = curr->next;
    }
}

void printLLRec(nodePT L){
    if(L == NULL) return;
    
    printf("%d", L->data);
    printLLRec(L->next);
}

int main() {


    return 0;
}