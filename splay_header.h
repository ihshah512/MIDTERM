#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class SplayTree
{
private:
    Node *root;

    Node *rightRotate(Node *x);
    Node *leftRotate(Node *x);
    Node *splay(Node *root, int key);
    Node *insertUtil(Node *root, int key);
    Node *deleteUtil(Node *root, int key);
    Node *findMax(Node *node);

public:
    SplayTree();
    void insert(int key);
    void remove(int key);
    Node *find(int key);
    void printTree();
    void inorder(Node *root);
};

#endif // SPLAYTREE_H
