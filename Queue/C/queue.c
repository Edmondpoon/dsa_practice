#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Node {
    uint32_t value;
    struct Node *next;
} node;

//
// (Tail) N -> N -> N -> N (Head)
//
struct Queue {
    uint64_t capacity;
    uint64_t size;
    node *head;
    node *tail;
};

// Allocates and initializes a node for a linked list
//
// value: The value of the node
node *createNode(uint32_t value) {
    node *n = (node *) calloc(1, sizeof(node));
    if (n) {
        n->next = NULL;
        n->value = value;
    }
    return n;
}

// Frees the memory associated with a node
//
// n: the node to free
void freeNode(node **n) {
    // If the given node is valid
    if (*n) {
        free(*n);
        *n = NULL;
    }
    return;
}

// Allocates and initializes a queue
//
// capacity: The max capacity of the queue
Queue *createQueue(uint64_t capacity) {
    Queue *q = (Queue *) calloc(1, sizeof(Queue));
    // Enough memory for allocation
    if (q) {
        q->capacity = capacity;
        q->size = 0;
        q->head = NULL;
        q->tail = NULL;
    }
    return q;
}

// Frees the memory associated with a queue instance
//
// q: the queue to free
void freeQueue(Queue **q) {
    // If the given queue is valid
    if (*q) {
        node *current, *temp = (*q)->tail;
        while (temp != NULL) {
            current = temp;
            temp = temp->next;
            freeNode(&current);
        }
        free(*q);
        *q = NULL;
    }
    return;
}

// Adds an element to the queue
//
// item: the element to add
// q   : the queue to add the element to
bool enqueue(Queue *q, uint32_t item) {
    if (!isFull(q)) {
        node *new = createNode(item);
        new->next = q->tail;
        if (size(q) < 1) {
            q->head = new;
        }
        q->tail = new;
        q->size += 1;
        return true;
    }
    return false;
}

// Removes the element at the top of the queue ands returns it
// Returns -1 if the queue is empty
//
// q: the queue to pop the element from
int64_t dequeue(Queue *q) {
    int64_t element = EMPTY;
    if (!isEmpty(q)) {
        q->size -= 1;
        node *remove = q->tail;
        element = remove->value;
        if (size(q) < 1) {
            q->head = NULL;
            q->tail = NULL;
        } else {
            q->tail = q->tail->next;
        }
        freeNode(&remove);
    }
    return element;
}

// Returns the current front of the queue
// Returns -1 if the queue is empty
//
// q: the queue to check
int64_t tail(Queue *q) {
    int64_t element = EMPTY;
    if (!isEmpty(q)) {
        element = q->tail->value;
    }
    return element;
}

// Returns whether the queue is empty or not
//
// q: the queue to check
bool isEmpty(Queue *q) {
    return (size(q) == 0);
}

// Returns whether the queue is full or not
//
// q: the queue to check
bool isFull(Queue *q) {
    return (size(q) == capacity(q));
}

// Returns the current size of the queue
//
// q: the queue to check
uint64_t size(Queue *q) {
    return q->size;
}

// Returns the max capacity of the queue
//
// q: the queue to check
uint64_t capacity(Queue *q) {
    return q->capacity;
}

// Prints the queue
//
// q: the queue to print
void printQueue(Queue *q) {
    printf("(Tail) ");
    node *temp = q->tail;
    while (temp->next != NULL) {
        printf("%" PRIu32 " -> ", temp->value);
        temp = temp->next;
    }
    printf("%" PRIu32 " (Head)\n", temp->value);
    return;
}
