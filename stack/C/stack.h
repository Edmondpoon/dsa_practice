#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <inttypes.h>

#define EMPTY -1
typedef struct Stack Stack;


Stack *createStack(uint64_t capacity);

void freeStack(Stack **s);

bool push(Stack *s, uint32_t item);

int64_t pop(Stack *s);

int64_t top(Stack *s);

bool isEmpty(Stack *s);

bool isFull(Stack *s);

uint64_t size(Stack *s);

uint64_t capacity(Stack *s);

void printStack(Stack *s);  

#endif
