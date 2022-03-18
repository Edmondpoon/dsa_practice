#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack {
    uint64_t capacity;
    uint64_t size;
    uint32_t *stack;
};

// Allocates and initializes a stack
//
// capacity: The max capacity of the stack
Stack *createStack(uint64_t capacity) {
    Stack *s = (Stack *) calloc(1, sizeof(Stack));
    // Enough memory for allocation
    if (s) {
        s->capacity = capacity;
        s->size = 0;
        s->stack = (uint32_t *) calloc (capacity, sizeof(uint32_t));
    }
    return s;
}

// Frees the memory associated with a stack instance
//
// s: the stack to free
void freeStack(Stack **s) {
    // If the given stack is valid
    if (*s) {
        free((*s)->stack);
        free(*s);
        *s = NULL;
    }
    return;
}

// Adds an element to the stack
//
// item: the element to add
// s   : the stack to add the element to
bool push(Stack *s, uint32_t item) {
    if (!isFull(s)) {
        s->stack[size(s)] = item;
        s->size += 1;
    }
    return false;
}

// Removes the element at the top of the stack ands returns it
// Returns -1 if the stack is empty
//
// s: the stack to pop the element from
int64_t pop(Stack *s) {
    int64_t element = EMPTY;
    if (!isEmpty(s)) {
        s->size -= 1;
        element = s->stack[size(s)];
    }
    return element;
}

// Returns the current top of the stack
// Returns -1 if the stack is empty
//
// s: the stack to check
int64_t top(Stack *s) {
    int64_t element = EMPTY;
    if (!isEmpty(s)) {
        element = s->stack[size(s) - 1];
    }
    return element;
}

// Returns whether the stack is empty or not
//
// s: the stack to check
bool isEmpty(Stack *s) {
    return (size(s) == 0);
}

// Returns whether the stack is full or not
//
// s: the stack to check
bool isFull(Stack *s) {
    return (size(s) == capacity(s));
}

// Returns the current size of the stack
//
// s: the stack to check
uint64_t size(Stack *s) {
    return s->size;
}

// Returns the max capacity of the stack
//
// s: the stack to check
uint64_t capacity(Stack *s) {
    return s->capacity;
}

// Prints the stack
//
// s: the stack to print
void printStack(Stack *s) {
    printf("(Top) ");
    for (int i = size(s) - 1; i > 0; ++i) {
        printf("%" PRIu32 " -> ", s->stack[i]);
    }
    printf("%" PRIu32 " (Bottom)\n", s->stack[0]);
    return;
}
