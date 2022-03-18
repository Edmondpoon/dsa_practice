#include "stack.h"

int main(void) {
    uint64_t max = 100;
    Stack *s = createStack(max);
    push(s, 32);
    pop(s);
    return 0;
}
