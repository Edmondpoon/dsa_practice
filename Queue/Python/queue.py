class Queue():
    def __init__(self, capacity):
        self.queue = []
        self.cap = capacity
        self.length = 0

    @property
    def size(self):
        """ Returns the size of the queue """
        return self.length

    @property
    def capacity(self):
        """ Returns the max capacity of the queue """
        return self.cap

    def isFull(self):
        """ Returns whether the queue is full or not """
        return (self.size == self.capacity)

    def isEmpty(self):
        """ Returns whether the queue is empty or not """
        return (self.size == 0)

    def tail(self):
        """ Returns the current top of the queue """
        element = -1
        if not self.isEmpty():
            element = self.queue[0]
        return element

    def enqueue(self, item):
        """ Pushes an element to the queue """
        if not self.isFull():
            self.queue.append(item)
            self.length += 1;
            return True
        return False

    def dequeue(self):
        """ Removes the top element of the queue """
        element = -1
        if not self.isEmpty():
            element = self.queue.pop(0)
            self.length -= 1;
        return element


def main():
    q = Queue(100)
    q.enqueue(100000)
    print(q.dequeue())

main()
