#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
    int count;
} queue;

void init_queue(queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->count == 0;
}

bool enqueue(queue *q, int value) {
    
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) return false;
    newnode->value = value;
    newnode->next = NULL;

    if (q->tail != NULL) {
        q->tail->next = newnode;
    }
    
    q->tail = newnode;
    if (q->head == NULL) {
        q->head = newnode;
    }
    q->count++;
}

int dequeue(queue *q) {
    
    if (q->head == NULL) return QUEUE_EMPTY;
    
    
    node* tmp = q-> head;

    
    int result = tmp->value;

    
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
    q->count--;
    return result;
}

int isEmpty(queue *q) {
    return (q->count==0);
}

int count(queue *q) {
    int tempCount;
    tempCount == q->count;
    return tempCount;
}


