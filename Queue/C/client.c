#include "queue.h"

int main(void) {
    Queue *q = createQueue(100);
    enqueue(q, 1337);
    enqueue(q, 430);
    enqueue(q, 34);
    printQueue(q);
    dequeue(q);
    freeQueue(&q);
    return 0;
}
