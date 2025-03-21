#include <iostream>

class CircularBuffer
{
private:
    int *buffer;  // Array to hold elements
    int capacity; // Maximum size of buffer
    int head;     // Points to the front element
    int tail;     // Points to the next insert position
    int count;    // Number of elements in the buffer

public:
    CircularBuffer(int size)
    {
        capacity = size;
        buffer = new int[capacity];
        head = 0;
        tail = 0;
        count = 0;
    }

    ~CircularBuffer()
    {
        delete[] buffer;
    }

    bool isFull()
    {
        return count == capacity;
    }

    bool isEmpty()
    {
        return count == 0;
    }
    // add an element at the tail postion
    void enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "Buffer is full! Cannot enqueue " << value << std::endl;
            return;
        }
        buffer[tail] = value;
        tail = (tail + 1) % capacity; // Move tail forward circularly
        count++;
    }
    // remove an element from the head position
    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Buffer is empty! Cannot dequeue." << std::endl;
            return -1;
        }
        int value = buffer[head];
        head = (head + 1) % capacity; // Move head forward circularly
        count--;
        return value;
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Buffer is empty! Cannot peek." << std::endl;
            return -1;
        }
        return buffer[head];
    }

    void printBuffer()
    {
        std::cout << "Buffer: ";
        if (isEmpty())
        {
            std::cout << "Empty" << std::endl;
            return;
        }
        int index = head;
        for (int i = 0; i < count; i++)
        {
            std::cout << buffer[index] << " ";
            index = (index + 1) % capacity;
        }
        std::cout << std::endl;
    }
};

int main()
{
    CircularBuffer cb(5);

    cb.enqueue(10);
    cb.enqueue(20);
    cb.enqueue(30);
    cb.enqueue(40);
    cb.enqueue(50);
    cb.printBuffer();

    cb.enqueue(60); // Should indicate buffer is full

    std::cout << "Dequeued: " << cb.dequeue() << std::endl;
    cb.printBuffer();

    cb.enqueue(60);
    cb.printBuffer();

    return 0;
}
