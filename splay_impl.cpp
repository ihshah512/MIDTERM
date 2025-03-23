#include "SplayTree.h"
using namespace std;

SplayTree::SplayTree() : root(nullptr) {}

Node *SplayTree::rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node *SplayTree::leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node *SplayTree::splay(Node *root, int key)
{
    if (!root || root->key == key)
        return root;

    if (key < root->key)
    {
        if (!root->left)
            return root;

        if (key < root->left->key)
        {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        else if (key > root->left->key)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right)
                root->left = leftRotate(root->left);
        }

        return (root->left == nullptr) ? root : rightRotate(root);
    }
    else
    {
        if (!root->right)
            return root;

        if (key > root->right->key)
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        else if (key < root->right->key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left)
                root->right = rightRotate(root->right);
        }

        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

Node *SplayTree::insertUtil(Node *root, int key)
{
    if (!root)
        return new Node(key);

    root = splay(root, key);

    if (root->key == key)
        return root;

    Node *newNode = new Node(key);

    if (key < root->key)
    {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    }
    else
    {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }

    return newNode;
}

void SplayTree::insert(int key)
{
    root = insertUtil(root, key);
}

Node *SplayTree::deleteUtil(Node *root, int key)
{
    if (!root)
        return nullptr;

    root = splay(root, key);

    if (root->key != key)
        return root;

    if (!root->left)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    else
    {
        Node *temp = splay(root->left, key);
        temp->right = root->right;
        delete root;
        return temp;
    }
}

void SplayTree::remove(int key)
{
    root = deleteUtil(root, key);
}

Node *SplayTree::find(int key)
{
    root = splay(root, key);
    return (root && root->key == key) ? root : nullptr;
}

void SplayTree::printTree()
{
    inorder(root);
    cout << endl;
}

void SplayTree::inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
