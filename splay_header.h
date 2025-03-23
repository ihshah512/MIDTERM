#ifndef SPLAYTREE_H
#define SPLAYTREE_H

class SplayNode {
public:
    int key;
    SplayNode* left;
    SplayNode* right;
    SplayNode* parent;

    SplayNode(int value);
};

class SplayTree {
private:
    SplayNode* root;

    void leftRotate(SplayNode* x);
    void rightRotate(SplayNode* x);
    void splay(SplayNode* x);
    SplayNode* findMax(SplayNode* node);
    SplayNode* join(SplayNode* t1, SplayNode* t2);

public:
    SplayTree();
    ~SplayTree();
    void insert(int key);
    void remove(int key);
    SplayNode* search(int key);
    void printTree(SplayNode* node, int level = 0);
    void deleteTree(SplayNode* node);
};

#endif // SPLAYTREE_H