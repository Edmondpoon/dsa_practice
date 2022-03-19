#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include <inttypes.h>

#define EMPTY -1
typedef struct Queue Queue;


Queue *createQueue(uint64_t capacity);

void freeQueue(Queue **q);

bool enqueue(Queue *q, uint32_t item);

int64_t dequeue(Queue *q);

int64_t tail(Queue *q);

bool isEmpty(Queue *q);

bool isFull(Queue *q);

uint64_t size(Queue *q);

uint64_t capacity(Queue *q);

void printQueue(Queue *q);  

#endif
