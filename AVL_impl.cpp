#include <AVL_header.h>
#include <iostream>
#include <algorithm>

AVLNode::AVLNode(int value)
{
    key = value;
    left = nullptr;
    right = nullptr;
    height = 1;
}

int AVLTree::getHeight(AVLNode *node)
{

    return node ? node->height : 0;
}

int AVLTree::getBalance(AVLNode *node)
{

    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}
// Right Rotation (Left-Left Case)
/*
Before:          After:
    z             y
   /             / \
  y      =>     x   z
 /
x
*/
AVLNode *AVLTree::rightRotate(AVLNode *z)
{

    AVLNode *y = z->left;
    AVLNode *T2 = y->right;

    y->right = z;
    z->left = T2;

    y->height = updateHeight(y);
    z->height = updateHeight(z);
}
/*
Before:          After:
  x               y
   \             / \
    y     =>    x   z
     \
      z
*/
AVLNode *AVLTree::leftRotate(AVLNode *x)
{

    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = updateHeight(y);
    x->height = updateHeight(x);
}

int AVLTree::updateHeight(AVLNode *node)
{

    return std::max(node->left->height, node->right->height) + 1;
}

AVLNode *AVLTree::getMinValueNode(AVLNode *node)
{

    if (node == nullptr)
    {
        return node;
    }

    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

AVLNode *AVLTree::insert(AVLNode *root, int key)
{

    /*Alog
    1. check the root node if its null put new node their
    2. if not null look on left look on right
    3. check balance after each level of insertion if balance is out
    4. perform rotations
    */
    AVLNode *insertNode = new AVLNode(key);

    if (root == nullptr)
    {
        return insertNode;
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root; // return root becaseu duplicates not allowed
    }

    root->height = updateHeight(root);

    int balance = getBalance(root);
    // left left case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        rightRotate(root);
    }
    // left right rotation
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right right case

    if (balance < 1 && getBalance(root->right) <= 0)
    {
        leftRotate(root);
    }

    if (balance < 1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

AVLNode *AVLTree::remove(AVLNode *root, int key)
{

    if (root == nullptr)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = remove(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = remove(root->right, key);
    }
    else
    {

        // case 1 with no childrens
        if (root->left == nullptr || root->right == nullptr)
        {
            AVLNode *temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        else
        {

            AVLNode *temp = getMinValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    // update the height
    root->height = updateHeight(root);
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    if (balance < 1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // right left rotation
    if (balance < -1 && getBalance(root->right) > 0)
    {
        rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void AVLTree::deleteTree(AVLNode *root)
{
    if (root == nullptr)
        return;

    // First delete left and right subtrees
    deleteTree(root->left);
    deleteTree(root->right);

    // Then delete the current node
    delete root;
}