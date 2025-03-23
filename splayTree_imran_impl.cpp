#include <splay_header.h>

SplayTree::SplayTree()
{

    root = nullptr;
}
/*
Before:

       x
      /
     y
    /
   key
After:

      y
     / \
   key  x
*/
Node *SplayTree::rightRotate(Node *x){

    Node * y = x->left;
    x->left = y->right;
    return y;
}
/*
  x
    \
     y
      \
      key
       y
      / \
     x  key
*/

Node *SplayTree::leftRotate(Node *x){

    Node *y = x->right;
    x->right = y->left;
    return y;
}


Node *SplayTree::splay(Node *root, int key){

    if(!root || root->key == key){

        return root;
    }


    if(key < root->key){
        if(!root->left){
            return root;
        }
        if(){
            
        }

    }

}