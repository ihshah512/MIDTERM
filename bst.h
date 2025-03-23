#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
    friend class BST;
    Node(string val){
        m_value=val;
        m_left = nullptr;
        m_right = nullptr;
    }
    friend ostream& operator<<(ostream& sout, const Node* aNode);
    private:
    string m_value;
    Node* m_left;
    Node* m_right;
};
class BST{
    public:
    BST();
    BST(const BST & rhs);
    ~BST();
    bool empty();
    void insert(string val);
    void insert1(string val);
    Node* find(string val);
    void remove(string val);
    void dump();
    void clear(); 
    private:
    Node* m_root;

    void clear(Node* & aNode);
    void insert(string val, Node* & aNode);
    Node* insert1(string val, Node* aNOde);
    void printSorted(Node * aNode);
    Node* find(string val, Node* aNode); 
    Node* findMin(Node* aNode);
    Node* remove(string val, Node* aNode);
    void copy(Node * & aNode, Node * rhs);
};
#endif