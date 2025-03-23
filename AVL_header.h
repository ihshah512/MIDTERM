#ifndef AVLTREE_H
#define AVLTREE_H

class AVLNode
{
public:
    friend class AVLTree;
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(int value);
};

class AVLTree
{
private:
    int getHeight(AVLNode *node);
    int getBalance(AVLNode *node);
    AVLNode *rightRotate(AVLNode *z);
    AVLNode *leftRotate(AVLNode *x);
    AVLNode *getMinValueNode(AVLNode *node);

public:
    AVLTree() {}
    ~AVLTree();
    AVLNode *insert(AVLNode *root, int key);
    AVLNode *remove(AVLNode *root, int key);
    void printTree(AVLNode *root, int level = 0);
    void deleteTree(AVLNode *root);
    int updateHeight(AVLNode *node);
};

#endif // AVLTREE_H