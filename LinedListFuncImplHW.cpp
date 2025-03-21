#include <iostream>
#include <string>

using namespace std;

class Node
{ // a node in a linked list
public:
    Node() : m_next(nullptr), m_elem("") {};

private:
    string m_elem; // element value
    Node *m_next;  // next item in the list
    // provides LinkedList access
    friend class LinkedList;
};
class LinkedList
{ // a linked list
public:
    LinkedList();  // empty list constructor
    ~LinkedList(); // destructor
    // empty() checks if list is empty
    bool empty() const
    {
        return m_head == nullptr;
    }
    // front() returns the front (head) member
    const string &front() const;
    // tail() returns the last member
    const string &tail() const;
    // append() inserts a node at the tail of list
    void append(const string &toInsert);
    // removeTail() removes the last member of the list
    void removeTail();
    // printList() prints all members in order from head to tail
    void printList();
    // overloaded assignment operator makes an exact copy of rhs
    const LinkedList &operator=(const LinkedList &rhs);

private:
    Node *m_head; // pointer to the head of list
};

void LinkedList::append(const string &toInsert)
{

    Node *appendNode = new Node();
    appendNode->m_elem = toInsert;
    appendNode->m_next = nullptr;

    if (m_head == nullptr)
    {
        m_head = appendNode;

        return;
    }

    Node *temp = m_head;
    while (temp->m_next != nullptr)
    {
        temp = temp->m_next;
    }

    temp->m_next = appendNode;
}

void LinkedList::removeTail()
{

    if (m_head == nullptr)
    {
        throw runtime_error("List is empty cant remove tail");
        return;
    }

    // missing case  if head itself is the only pointer

    if (m_head->m_next = nullptr)
    {

        delete m_head;
        m_head = nullptr;
        return;
    }

    Node *temp = m_head;
    while (temp->m_next->m_next != nullptr)
    {
        temp = temp->m_next;
    }
    Node *nodeToDelete = temp->m_next;
    delete nodeToDelete;
    nodeToDelete = nullptr;
}

/* TEST CASES FOR APPEND
1. LIST SHOULD NOT BE EMPTY AFTER APPENEDING
2. THE APPENDED VALUE MUST BE EQUAL TO THE VALUE AT THE TAIL OF THE LIST
3.
*/

const LinkedList &LinkedList::operator=(const LinkedList &rhs)
{

    // Case # 1 first check the self assignment

    if (this != &rhs)
    {
        // if this is not empty we are talking about one which is current
        //  in which we will copy from rhs
        if (!empty())
        {

            removeTail();
        }

        Node *current = rhs.m_head;
        while (current != nullptr)
        {

            append(current->m_elem);
            current = current->m_next;
        }
    }
    return *this;
}
/*
Differences Recap (Specific to Your Class)
Copy Constructor: Creates a new LinkedList by duplicating the nodes from another LinkedList. Since it’s a new object, no cleanup of existing nodes is needed.
Assignment Operator: Updates an existing LinkedList to match another LinkedList. It must first clear the current list’s nodes to avoid memory leaks before copying from the source.
Complete LinkedList Class with Implementations
Here’s the corrected and completed code, including both the copy constructor and assignment operator:

cpp

Collapse

Wrap

Copy
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    Node() : m_next(nullptr), m_elem("") {}

private:
    string m_elem;  // element value
    Node* m_next;   // next item in the list
    friend class LinkedList;
};

class LinkedList {
public:
    // Default constructor
    LinkedList() : m_head(nullptr) {}

    // Copy constructor
    LinkedList(const LinkedList& other) : m_head(nullptr) {
        Node* current = other.m_head;
        while (current != nullptr) {
            append(current->m_elem);
            current = current->m_next;
        }
    }

    // Destructor
    ~LinkedList() {
        while (!empty()) {
            removeTail();
        }
    }

    // Check if list is empty
    bool empty() const {
        return m_head == nullptr;
    }

    // Return the front element
    const string& front() const {
        if (empty()) {
            throw runtime_error("List is empty, no front element");
        }
        return m_head->m_elem;
    }

    // Return the tail element
    const string& tail() const {
        if (empty()) {
            throw runtime_error("List is empty, no tail element");
        }
        Node* temp = m_head;
        while (temp->m_next != nullptr) {
            temp = temp->m_next;
        }
        return temp->m_elem;
    }

    // Append a node at the tail
    void append(const string& toInsert) {
        Node* appendNode = new Node();
        appendNode->m_elem = toInsert;
        appendNode->m_next = nullptr;

        if (m_head == nullptr) {
            m_head = appendNode;
            return;
        }

        Node* temp = m_head;
        while (temp->m_next != nullptr) {
            temp = temp->m_next;
        }
        temp->m_next = appendNode;
    }

    // Remove the tail node
    void removeTail() {
        if (m_head == nullptr) {
            throw runtime_error("List is empty, can't remove tail");
        }

        // Case 1: Only one node
        if (m_head->m_next == nullptr) {  // Fixed: = to ==
            delete m_head;
            m_head = nullptr;
            return;
        }

        // Case 2: More than one node
        Node* temp = m_head;
        while (temp->m_next->m_next != nullptr) {
            temp = temp->m_next;
        }
        Node* nodeToDelete = temp->m_next;
        temp->m_next = nullptr;
        delete nodeToDelete;
    }

    // Print the list
    void printList() {
        if (empty()) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = m_head;
        while (temp != nullptr) {
            cout << temp->m_elem << " -> ";
            temp = temp->m_next;
        }
        cout << "nullptr" << endl;
    }

    // Assignment operator
    const LinkedList& operator=(const LinkedList& rhs) {
        if (this != &rhs) {  // Check for self-assignment
            // Clear the current list
            while (!empty()) {
                removeTail();
            }

            // Copy from rhs
            Node* current = rhs.m_head;
            while (current != nullptr) {
                append(current->m_elem);
                current = current->m_next;
            }
        }
        return *this;
    }

private:
    Node* m_head;  // Pointer to the head of the list
};

// Test code
int main() {
    // Test copy constructor
    LinkedList list1;
    list1.append("A");
    list1.append("B");
    list1.append("C");
    cout << "list1: ";
    list1.printList();

    LinkedList list2(list1);  // Copy constructor
    cout << "list2 (copy of list1): ";
    list2.printList();

    // Test assignment operator
    LinkedList list3;
    list3.append("X");
    cout << "list3 before assignment: ";
    list3.printList();

    list3 = list1;  // Assignment operator
    cout << "list3 after assignment from list1: ";
    list3.printList();

    return 0;
}
Fixes and Improvements
Copy Constructor:
Added LinkedList(const LinkedList& other) to create a deep copy of the input list by appending each element from other.
Assignment Operator:
Fixed the original implementation, which only called removeTail() once if the list wasn’t empty. Now it clears the entire list using a while loop before copying from rhs.
Destructor:
Added ~LinkedList() to deallocate all nodes by repeatedly calling removeTail().
removeTail():
Fixed a bug where if (m_head->m_next = nullptr) used assignment (=) instead of comparison (==).
Properly handled the single-node case and multi-node case.
Other Functions:
Implemented front(), tail(), and printList() to make the class fully usable.
Output of Test Code
Running the main() function will produce something like:

text

Collapse

Wrap

Copy
list1: A -> B -> C -> nullptr
list2 (copy of list1): A -> B -> C -> nullptr
list3 before assignment: X -> nullptr
list3 after assignment from list1: A -> B -> C -> nullptr
Key Differences in Implementation
Copy Constructor:
Starts with an empty list (m_head = nullptr) and builds it by copying nodes from other.
No need to deallocate anything since the object is newly created.
Assignment Operator:
Must first clear the existing list (this) to avoid memory leaks before copying from rhs.
Checks for self-assignment (this != &rhs) to prevent issues like deleting its own data.
Both ensure a deep copy of the linked list, meaning each node is duplicated rather than just copying pointers (which would be a shallow copy).

Let me know if you need further clarification or additional test cases!

*/

/*
– For the LinkedList class mentioned above implement an overloaded assignment operator.
The assignment operator must create an exact deep copy of the rhs object. An exact copy means
the order of the nodes in both lists will be the same. You are not allowed to call other functions
from the class or the constructor. To write an efficient function all remove or insert operations
must happen at the head of the list not at the tail. (15 points)

*/


#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    Node() : m_next(nullptr), m_elem("") {}

private:
    string m_elem;  // element value
    Node* m_next;   // next item in the list
    friend class LinkedList;
};

class LinkedList {
public:
    LinkedList() : m_head(nullptr) {}
    ~LinkedList() {
        // Minimal destructor for cleanup (not using other functions here)
        Node* current = m_head;
        while (current != nullptr) {
            Node* next = current->m_next;
            delete current;
            current = next;
        }
    }

    // Overloaded assignment operator
    const LinkedList& operator=(const LinkedList& rhs) {
        // Step 1: Check for self-assignment
        if (this != &rhs) {
            // Step 2: Delete all nodes in the current list (remove from head)
            Node* current = m_head;
            while (current != nullptr) {
                Node* next = current->m_next;
                delete current;
                current = next;
            }
            m_head = nullptr;  // List is now empty

            // Step 3: Create a deep copy of rhs, inserting at head in reverse order
            Node* rhs_current = rhs.m_head;
            Node* new_head = nullptr;  // Temporary head for building the list

            // First, copy all nodes from rhs
            while (rhs_current != nullptr) {
                Node* new_node = new Node();
                new_node->m_elem = rhs_current->m_elem;
                new_node->m_next = new_head;  // Insert at head
                new_head = new_node;
                rhs_current = rhs_current->m_next;
            }

            // Step 4: Reverse the list to match rhs order
            m_head = nullptr;  // Final head starts as nullptr
            while (new_head != nullptr) {
                Node* temp = new_head;
                new_head = new_head->m_next;
                temp->m_next = m_head;  // Insert at head of final list
                m_head = temp;
            }
        }
        return *this;
    }

    // Helper function to print (for testing, not part of requirement)
    void printList() {
        Node* temp = m_head;
        while (temp != nullptr) {
            cout << temp->m_elem << " -> ";
            temp = temp->m_next;
        }
        cout << "nullptr" << endl;
    }

    // Helper function to append (for testing, not used in operator=)
    void append(const string& value) {
        Node* new_node = new Node();
        new_node->m_elem = value;
        if (m_head == nullptr) {
            m_head = new_node;
        } else {
            Node* temp = m_head;
            while (temp->m_next != nullptr) {
                temp = temp->m_next;
            }
            temp->m_next = new_node;
        }
    }

private:
    Node* m_head;  // Pointer to the head of the list
};

// Test code
int main() {
    LinkedList list1;
    list1.append("A");
    list1.append("B");
    list1.append("C");
    cout << "list1: ";
    list1.printList();

    LinkedList list2;
    list2.append("X");
    cout << "list2 before assignment: ";
    list2.printList();

    list2 = list1;  // Assignment operator
    cout << "list2 after assignment: ";
    list2.printList();

    return 0;
}