#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct Heap {
    uint32_t *heap;
    uint64_t capacity;
    uint64_t size;
    bool maxHeap;
};

void heapify(Heap *h, uint64_t index) {
    while (index / 2 > 1) {
        bool comparison = (h->heap[index] > h->heap[index / 2]);
        if ((h->maxHeap && comparison) ||
            (!h->maxHeap && !comparison)) {
            uint32_t temp = h->heap[index / 2];
            h->heap[index / 2] = h->heap[index];
            h->heap[index] = temp;
        }
        index /= 2;
    }
    return;
}

Heap *createHeap(uint64_t capacity, bool max) {
    Heap *h = (Heap *) calloc(1, sizeof(Heap));
    if (h) {
        h->size = 0;
        h->capacity = capacity;
        h->maxHeap = max;
        h->heap = (uint32_t *) calloc(capacity, sizeof(uint32_t));
    }
    return h;
}

void freeHeap(Heap **h);

bool insertion(Heap *h, uint32_t item);

int64_t removeTop(Heap *h);

int64_t peekTop(Heap *h);

bool isEmpty(Heap *h);

bool isFull(Heap *h);

uint64_t size(Heap *h);

uint64_t capacity(Heap *h);

void printHeap(Heap *h);  
