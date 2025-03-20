#include "dll.h"
DLL::DLL(){
    m_head = nullptr;
    m_tail = nullptr;
}
DLL::~DLL(){
    Node * temp = nullptr;
    while (!empty()){
        temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
    m_head = nullptr;
    m_tail = nullptr;
}
void DLL::insertAtHead(string toInsert){
    // to be implemented
}
void DLL::addInBetween(string location, string toInsert){
    // to be implemented
}
bool DLL::empty() const {
    return (m_head == nullptr);
}

void DLL::dump() const {
    if (!empty()){
        Node * temp = m_head;
        while (temp != nullptr){
            cout << temp->m_data << " ";
            temp = temp->m_next;
        }
    }
}