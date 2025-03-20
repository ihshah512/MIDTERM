#ifndef _NODE_H_
#define _NODE_H_
#include <string>
using namespace std;
class Node {				// a node in a linked list
  public:
  Node():m_next(nullptr),m_elem(""){};
  private:
    Node* m_next;		// next item in the list
    string m_elem;	// element value
    friend class LinkedList;// provide LinkedList access
  };
#endif 
  