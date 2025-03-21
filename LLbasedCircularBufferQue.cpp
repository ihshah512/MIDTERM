#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;  // Points to the front of the queue
    Node* rear;   // Points to the rear of the queue

public:
    Queue() {
        front = rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation (Insert an element at the rear)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) { // If queue is empty
            front = rear = newNode;
            return;
        }
        rear->next = newNode;  // Link new node to end of queue
        rear = newNode;        // Update rear pointer
    }

    // Dequeue operation (Remove an element from the front)
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty! Cannot dequeue." << std::endl;
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next; // Move front to the next node

        if (front == nullptr) { // If queue is now empty
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    // Peek operation (Retrieve the front element without removing it)
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty! Cannot peek." << std::endl;
            return -1;
        }
        return front->data;
    }

    // Print the queue (for debugging)
    void printQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        Node* temp = front;
        std::cout << "Queue: ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue();

    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    q.printQueue();

    std::cout << "Front element: " << q.peek() << std::endl;

    return 0;
}
