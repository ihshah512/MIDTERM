#include "list.h"

LinkedList::LinkedList() // constructor
    : m_head(nullptr)
{
}

LinkedList::~LinkedList() // destructor
{
    while (!empty())
        removeFront();
}

bool LinkedList::empty() const // is list empty?
{
    return m_head == nullptr;
}

const string &LinkedList::front() const
{ // get front element
    if (!empty())
        return m_head->m_elem;
    else
        throw runtime_error("Error: Reading front of empty list!");
}
// my impl
void LinkedList::addFront(const string &toInsert)
{

    Node *nodeToAdd = new Node();
    nodeToAdd->m_elem = toInsert;

    if (m_head == nullptr)
    {
        m_head = nodeToAdd;
        nodeToAdd->m_next = nullptr;
    }
    else
    {

        nodeToAdd->m_next = m_head;
        m_head = nodeToAdd;
    }
}

/*void LinkedList::addFront(const string& toInsert) {
    // list is empty
    // there is multiple nodes
    // there is only one node
    Node * newNode = new Node;
    newNode->m_elem = toInsert;
    newNode->m_next = nullptr;
    if (m_head == nullptr){
        m_head = newNode;
    }
    else{
        newNode->m_next = m_head;
        m_head = newNode;
    }
}*/

void LinkedList::removeFront()
{

    if (!empty())
    {

        Node *temp = m_head;
        m_head = temp->m_next; // first update the head location
        delete m_head;         // dont delete it otherwise you will lose the mem address
    }
}

/*void LinkedList::removeFront()
{
    // empty
    // one node
    // multiple nodes
    if (!empty())
    {
        Node *toDelete = m_head;
        m_head = toDelete->m_next;
        delete toDelete;
    }
}
*/
void LinkedList::addInBetween(const string &e, const string &toInsert)
{

    Node *nodeToBeAdded = new Node();
    nodeToBeAdded->m_elem = toInsert;

    // 3 cases should be address 1. If list is empty 2. If head node is the e 3. multiple nodes

    // case 1: List is empty
    if (empty())
    {
        delete nodeToBeAdded;
        nodeToBeAdded = nullptr;
        return;
    }
    // case 2
    if (m_head->m_elem == e)
    {

        m_head->m_next = nodeToBeAdded;
        nodeToBeAdded->m_next = nullptr;
    }
    // case 3 multiple nodes
    Node *temp = m_head;
    while (temp != nullptr && temp->m_next != nullptr && temp->m_next->m_elem != e)
    {

        temp = temp->m_next;
    }

    if (temp != nullptr && temp->m_next != nullptr)
    {
        // ORDER OF FOLLOWING LINES OF CODE MATTERS V IMPORTANT
        nodeToBeAdded->m_next = temp->m_next;
        temp->m_next = nodeToBeAdded;
    }
    delete nodeToBeAdded;
}

/*void LinkedList::addInBetween(const string &e,
                              const string &toInsert)
{
    // list is empty
    // list has one node and we want to insert before that
    // list has one node and we do not want to insert
    // multiple nodes and we want to insert somewhere in the list
    // multiple nodes and we reach the end and we do not want to insert
    if (!empty())
    {
        if (m_head->m_elem == e)
        {
            Node *newNode = new Node;
            newNode->m_elem = toInsert;
            newNode->m_next = m_head;
            m_head = newNode;
        }
        else if (m_head->m_next != nullptr)
        {
            Node *temp = m_head;
            while (temp->m_next->m_next != nullptr &&
                   temp->m_next->m_elem != e)
            {
                temp = temp->m_next;
            }
            if (temp->m_next->m_elem == e)
            {
                Node *newNode = new Node;
                newNode->m_elem = toInsert;
                newNode->m_next = temp->m_next;
                temp->m_next = newNode;
            }
        }
    }
}*/

void LinkedList::remove(const string &e)
{

    if (empty())
    {
        return;
    }
    // if head is the only value and that is e
    if (m_head->m_elem == e && m_head->m_next == nullptr)
    {

        delete m_head;
        m_head = nullptr;
        return;
    }

    // if head is not the only value but head is e

    if (m_head->m_elem == e)
    {
        Node *temp = m_head;
        m_head = temp->m_next;
        delete temp;
        return;
    }

    Node *temp = m_head;

    while (temp->m_next->m_next != nullptr && temp->m_elem != e)
    {
        temp = temp->m_next;
    }

    if (temp->m_next->m_elem == e)
    {
        Node *toDelete = temp->m_next;
        temp->m_next = temp->m_next->m_next;
        delete toDelete;
    }
}

/*void LinkedList::remove(const string &e)
{
    // list is empty
    // list has one node and we want to remove it
    // list has one node and we do not want to remove it
    // multiple nodes and we want to remove somewhere in the list
    // multiple nodes and we reach the end and we do not want to remove
    if (!empty())
    {
        if (m_head->m_elem == e)
        {
            Node *temp = m_head;
            m_head = m_head->m_next;
            delete temp;
        }
        else if (m_head->m_next != nullptr)
        {
            Node *temp = m_head;
            while (temp->m_next->m_next != nullptr &&
                   temp->m_next->m_elem != e)
            {
                temp = temp->m_next;
            }
            if (temp->m_next->m_elem == e)
            {
                Node *toDelete = temp->m_next;
                temp->m_next = temp->m_next->m_next;
                delete toDelete;
            }
        }
    }
}*/

void LinkedList::printList()
{
    // to test this function:
    // case: the list is empty
    // case: the list is not empty
    Node *temp = m_head;
    cout << "The current list is:" << endl;
    while (temp != nullptr)
    {
        cout << temp->m_elem << " => ";
        temp = temp->m_next;
    }
    cout << "END" << endl;
}

void LinkedList::append(const string &toInsert)
{
    Node *appendNode = new Node();
    appendNode->m_elem = toInsert;

    if (empty())
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
    appendNode->m_next = nullptr;
}

void LinkedList::removeTail()
{

    if (empty())
    {
        return;
    }

    if (m_head == nullptr)
    {
        delete m_head;
        m_head = nullptr;
        return;
    }
    Node *temp = m_head;
    // this loop will go the end of the tail and see its next if that null
    while (temp->m_next->m_next != nullptr)
    {

        temp = temp->m_next;
    }
    // in order ot delete tail we have to remove temp next
    delete temp->m_next;
    temp->m_next = nullptr;
}