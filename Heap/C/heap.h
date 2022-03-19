#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdbool.h>
#include <inttypes.h>

typedef struct Heap Heap;


Heap *createHeap(uint64_t capacity, bool max);

void freeHeap(Heap **h);

bool insertion(Heap *h, uint32_t item);

int64_t removeTop(Heap *h);

int64_t peekTop(Heap *h);

bool isEmpty(Heap *h);

bool isFull(Heap *h);

uint64_t size(Heap *h);

uint64_t capacity(Heap *h);

void printHeap(Heap *h);  

#endif
