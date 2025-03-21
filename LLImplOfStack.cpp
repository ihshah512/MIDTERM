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

class Stack { //in stack we are only dealing with one end which is top
                // In que we are dealing with both rear and top end
private:
    Node* top; // Points to the top of the stack

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push operation (Insert an element at the top)
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top; // Link new node to the previous top
        top = newNode;        // Update top pointer
    }

    // Pop operation (Remove the top element)
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty! Cannot pop." << std::endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next; // Move top to the next node
        delete temp;
        return value;
    }

    // Peek operation (Retrieve the top element without removing it)
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty! Cannot peek." << std::endl;
            return -1;
        }
        return top->data;
    }

    // Print the stack (for debugging)
    void printStack() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        Node* temp = top;
        std::cout << "Stack (Top -> Bottom): ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.printStack();

    std::cout << "Popped: " << s.pop() << std::endl;
    s.printStack();

    std::cout << "Top element: " << s.peek() << std::endl;

    return 0;
}
