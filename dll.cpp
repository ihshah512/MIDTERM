#include "dll.h"
DLL::DLL()
{
    m_head = nullptr;
    m_tail = nullptr;
}
DLL::~DLL()
{
    Node *temp = nullptr;
    while (!empty())
    {
        temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
    m_head = nullptr;
    m_tail = nullptr;
}
void DLL::insertAtHead(string toInsert)
{
    /*Cases:
    1. Check if list is empty then insert at head
    2. if not insert and readjsutnode
    */
    Node *newNode = new Node(toInsert);
    if (empty())
    {
        m_head = newNode;
        m_tail = newNode; // was a mistake that not take this line
        newNode->m_previous = nullptr;
        newNode->m_next = nullptr;
        return; // major mistake alway doing it did not return
    }
    Node *temp = m_head;
    newNode->m_next = m_head;
    newNode->m_previous = nullptr;
    temp->m_previous = newNode;
    m_head = newNode;
}
void DLL::addInBetween(string location, string toInsert)
{
    Node *newInsert = new Node(toInsert);
    if (empty())
    {
        return;
    }

    // Missing case if head is the location

    if (m_head->m_data == location)
    {

        newInsert->m_next = m_head;
        newInsert->m_previous = nullptr;
        m_head->m_previous = newInsert;
        m_head = newInsert; // missing line of code
        return;             // missing line of code
    }

    Node *temp = m_head;

    while (m_head != m_tail && temp->m_next->m_data == location)
    {
        temp = temp->m_next;
    }

    if (temp->m_next->m_data == location)
    {

        newInsert->m_next = temp->m_next;
        newInsert->m_previous = temp;
        temp->m_next->m_previous = newInsert;

        temp->m_next = newInsert;
    }

    delete newInsert;
    newInsert = nullptr;
}
bool DLL::empty() const
{
    return (m_head == nullptr);
}

void DLL::dump() const
{
    if (!empty())
    {
        Node *temp = m_head;
        while (temp != nullptr)
        {
            cout << temp->m_data << " ";
            temp = temp->m_next;
        }
    }
}