#include <iostream>
#include <algorithm>

class AVLNode
{
public:
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    int getHeight(AVLNode *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Right rotation (Left-Left case)
    AVLNode *rightRotate(AVLNode *z)
    {
        AVLNode *y = z->left;
        AVLNode *T2 = y->right;

        y->right = z;
        z->left = T2;

        z->height = std::max(getHeight(z->left), getHeight(z->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Left rotation (Right-Right case)
    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLNode *getMinValueNode(AVLNode *node)
    {
        AVLNode *current = node;
        while (current->left)
            current = current->left;
        return current;
    }

public:
    AVLNode *insert(AVLNode *root, int key)
    {
        // Standard BST insert
        if (!root)
            return new AVLNode(key);

        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        else
            return root; // Duplicate keys not allowed

        // Update height
        root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;

        // Get balance factor
        int balance = getBalance(root);

        // Left-Left Case
        if (balance > 1 && key < root->left->key)
            return rightRotate(root);

        // Right-Right Case
        if (balance < -1 && key > root->right->key)
            return leftRotate(root);

        // Left-Right Case
        if (balance > 1 && key > root->left->key)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right-Left Case
        if (balance < -1 && key < root->right->key)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLNode *remove(AVLNode *root, int key)
    {
        if (!root)
            return nullptr;

        // Standard BST delete
        if (key < root->key)
            root->left = remove(root->left, key);
        else if (key > root->key)
            root->right = remove(root->right, key);
        else
        {
            // Node with only one child or no child
            if (!root->left)
            {
                AVLNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                AVLNode *temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            AVLNode *temp = getMinValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }

        if (!root)
            return nullptr;

        // Update height
        root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;

        // Get balance factor
        int balance = getBalance(root);

        // Left-Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left-Right Case
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right-Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right-Left Case
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Utility function to print tree
    void printTree(AVLNode *root, int level = 0)
    {
        if (root)
        {
            printTree(root->right, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "  ";
            std::cout << root->key << std::endl;
            printTree(root->left, level + 1);
        }
    }

    // Destructor to free memory
    void deleteTree(AVLNode *root)
    {
        if (root)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }
};

int main()
{
    AVLTree avl;
    AVLNode *root = nullptr;

    // Insert some nodes
    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int key : keys)
    {
        root = avl.insert(root, key);
    }

    std::cout << "AVL Tree after insertions:" << std::endl;
    avl.printTree(root);

    // Remove a node
    root = avl.remove(root, 20);
    std::cout << "\nAVL Tree after removing 20:" << std::endl;
    avl.printTree(root);

    // Clean up
    avl.deleteTree(root);
    return 0;
}