class Stack():
    def __init__(self, capacity):
        self.stack = []
        self.cap = capacity
        self.length = 0

    @property
    def size(self):
        """ Returns the size of the stack """
        return self.length

    @property
    def capacity(self):
        """ Returns the max capacity of the stack """
        return self.cap

    def isFull(self):
        """ Returns whether the stack is full or not """
        return (self.size == self.capacity)

    def isEmpty(self):
        """ Returns whether the stack is empty or not """
        return (self.size == 0)

    def top(self):
        """ Returns the current top of the stack """
        element = -1
        if not self.isEmpty():
            element = self.stack[self.size - 1]
        return element

    def push(self, item):
        """ Pushes an element to the stack """
        if not self.isFull():
            self.stack.append(item)
            self.length += 1;
            return True
        return False

    def pop(self):
        """ Removes the top element of the stack """
        element = -1
        if not self.isEmpty():
            element = self.stack.pop()
            self.length -= 1;
        return element


def main():
    s = Stack(100)
    s.push(100000)
    print(s.pop())

main()
