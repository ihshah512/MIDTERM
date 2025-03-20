#ifndef _LIST_H_
#define _LIST_H_
#include "node.h"
#include <iostream>
#include <stdexcept>

class LinkedList {			    // a linked list
  public:
    LinkedList();				    // empty list constructor
    ~LinkedList();			    // destructor
    bool empty() const;			// is list empty?
    const string& front() const;// get front element
    void addFront(const string& toInsert);	// add to front of list
    void removeFront();			// remove front item from list
    //insert an item before the item with value e
    void addInBetween(const string& e, const string& toInsert);
    //remove the item with value e
    void remove(const string& e);
    void append(const string& toInsert);//insert at the tail of list
    void removeTail();//remove the last member of the list
    void printList();
  private:
    Node* m_head;				      // pointer to the head of list
  };
  #endif

  