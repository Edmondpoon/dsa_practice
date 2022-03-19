#include "stack.h"

int main(void) {
    uint64_t max = 100;
    Stack *s = createStack(max);
    push(s, 32);
    push(s, 1337);
    push(s, 320);
    printStack(s);
    pop(s);
    freeStack(&s);
    return 0;
}
