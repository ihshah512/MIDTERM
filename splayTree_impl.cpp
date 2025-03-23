#include "SplayTree.h"
#include <iostream>

SplayNode::SplayNode(int value) : key(value), left(nullptr), right(nullptr), parent(nullptr) {}

SplayTree::SplayTree() : root(nullptr) {}

SplayTree::~SplayTree() {
    deleteTree(root);
}

void SplayTree::deleteTree(SplayNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Left Rotation (Zig for Right Child)
/*
Before:       After:
    y            x
   /            / \
  x      =>    T1  y
   \              /
    T1           T2
     \
      T2
*/
void SplayTree::leftRotate(SplayNode* x) {
    SplayNode* y = x->parent;
    SplayNode* T1 = x->left;

    if (y->parent) {
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }
    x->parent = y->parent;
    y->parent = x;
    x->left = y;
    y->right = T1;
    if (T1)
        T1->parent = y;
    if (x->parent == nullptr)
        root = x;
}

// Right Rotation (Zig for Left Child)
/*
Before:       After:
    x            y
     \          / \
      y   =>   x  T2
     /            \
    T1             T1
   /
  T2
*/
void SplayTree::rightRotate(SplayNode* x) {
    SplayNode* y = x->parent;
    SplayNode* T2 = y->left;

    if (x->parent) {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    y->parent = x->parent;
    x->parent = y;
    y->left = x->right;
    if (y->left)
        y->left->parent = y;
    x->right = y;
    if (x->parent == nullptr)
        root = x;
}

// Splay operation to move node x to root
void SplayTree::splay(SplayNode* x) {
    while (x->parent) {
        SplayNode* p = x->parent;
        SplayNode* g = p->parent;

        if (!g) { // Zig step
            if (x == p->left)
                rightRotate(p);
            else
                leftRotate(x);
        }
        else if (x == p->left && p == g->left) { // Zig-Zig (Left-Left)
            rightRotate(g);
            rightRotate(p);
        }
        else if (x == p->right && p == g->right) { // Zig-Zig (Right-Right)
            leftRotate(p);
            leftRotate(x);
        }
        else if (x == p->right && p == g->left) { // Zig-Zag (Left-Right)
            leftRotate(x);
            rightRotate(g);
        }
        else { // Zig-Zag (Right-Left)
            rightRotate(p);
            leftRotate(x);
        }
    }
}

// Insert function with tree diagram
void SplayTree::insert(int key) {
    SplayNode* z = new SplayNode(key);
    if (!root) {
        root = z;
        return;
    }

    SplayNode* x = root;
    SplayNode* p = nullptr;
    while (x) {
        p = x;
        if (key < x->key)
            x = x->left;
        else if (key > x->key)
            x = x->right;
        else {
            delete z; // Duplicate key
            splay(p);
            return;
        }
    }

    z->parent = p;
    if (key < p->key)
        p->left = z;
    else
        p->right = z;

    splay(z); // Move newly inserted node to root
}

/* Insert Example Tree (Inserting 5 into tree with 10, 3)
Initial:
   10 (root)
  /
 3
Insert 5:
   10 (p)
  /
 3 (x)
  \
   5 (z) <- Newly inserted
After Splay(z):
   5 (root)
  / \
 3   10
*/

// Remove function with tree diagram
void SplayTree::remove(int key) {
    SplayNode* x = search(key);
    if (!x)
        return;

    splay(x); // Move node to delete to root
    SplayNode* leftTree = root->left;
    SplayNode* rightTree = root->right;

    delete root;
    if (leftTree)
        leftTree->parent = nullptr;
    if (rightTree)
        rightTree->parent = nullptr;

    if (!leftTree)
        root = rightTree;
    else {
        root = leftTree;
        SplayNode* max = findMax(leftTree);
        splay(max);
        root->right = rightTree;
        if (rightTree)
            rightTree->parent = root;
    }
}

/* Remove Example Tree (Removing 10 from tree with 10, 5, 15)
Initial:
   10 (root)
  /  \
 5    15
After splay(10):
   10 (root)
  /  \
 5    15
After Remove:
   5 (root)
    \
     15
*/

// Search function
SplayNode* SplayTree::search(int key) {
    SplayNode* x = root;
    while (x) {
        if (key == x->key) {
            splay(x);
            return x;
        }
        else if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return nullptr;
}

// Find maximum node in a subtree
SplayNode* SplayTree::findMax(SplayNode* node) {
    while (node->right)
        node = node->right;
    return node;
}

// Utility to print tree
void SplayTree::printTree(SplayNode* node, int level) {
    if (node) {
        printTree(node->right, level + 1);
        for (int i = 0; i < level; i++)
            std::cout << "  ";
        std::cout << node->key << std::endl;
        printTree(node->left, level + 1);
    }
}