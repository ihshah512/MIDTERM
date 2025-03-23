#include "bst.h"
 BST::BST(){
   m_root=nullptr;
}
 BST::~BST(){
    clear();
 }
 void BST::clear(){
    clear(m_root);
 }
 void BST::clear(Node* & aNode){
   // this traverses the tree in the post-order form
   // we are doing post order tranversal becasuse we dont want to remove root node
   // first ; first we would remove childresn then we would remove root

   if (aNode != nullptr){
        clear(aNode->m_left);
        clear(aNode->m_right);
        delete aNode;
        aNode = nullptr;
    }
 }
 void BST::insert(string val){
    insert(val, m_root);
 }
 void BST::insert(string val, Node* & aNode){
   // we are performing insertion in top to down patrren 

 
  
   if (aNode == nullptr){
        aNode = new Node(val);
    }
    else if (aNode->m_value > val){
        // move to left
        insert(val, aNode->m_left);
    }
    else{
        // move to right
        insert(val, aNode->m_right);
    }
 }

 void BST::dump(){
   printSorted(m_root);
 }

 void BST::printSorted(Node* aNode){
   // this traverses the tree in the in-order form
  
   if(aNode != nullptr){
      // 1 - go to left
      printSorted(aNode->m_left);
      // 2 - print
      cout << aNode->m_value << " ";
      //the following calls the overloaded insertion operator from the Node class
      //comment out the regular cout call above and call this one to get an enhanced output
      //cout << aNode << endl;
      // 3 - move to right
      printSorted(aNode->m_right);   
      }
 }
 ostream& operator<<(ostream& sout, const Node* aNode){
   // this is the overloaded insertion operator for the Node class 
   
   if (aNode != nullptr){
      sout << aNode->m_value;
      if (aNode->m_left != nullptr){
         sout << "(Left:" << aNode->m_left->m_value << ")";
      }
      if (aNode->m_right != nullptr){
         sout << "(Right:" << aNode->m_right->m_value << ")";
      } 
   }
   return sout;
 }

 void BST::insert1(string val){
   m_root = insert1(val, m_root);
 }

 Node* BST::insert1(string val, Node* aNode){
   // this version of insert returns newly created pointers as a function return value
   if (aNode == nullptr){
      aNode = new Node(val);
   }
   else if (val < aNode->m_value){
      aNode->m_left = insert1(val, aNode->m_left);
   }
   else{
      aNode->m_right = insert1(val, aNode->m_right);
   }
   return aNode;
 }

 Node* BST::find(string val){
   return find(val, m_root);
 }

 Node* BST::find(string val, Node* aNode){
   
   
      if (aNode == nullptr || aNode->m_value == val)
      {
         return aNode;
   }
   else if (aNode->m_value > val){
      return find(val,aNode->m_left);
   }
   else if(aNode->m_value < val){
      return find(val,aNode->m_right);
   }
   else{
      return nullptr;
   }
 }

 Node* BST::findMin(Node* aNode){
   // if node is null
   // if left child of node is null
   // or move to left

    
   
   if (aNode == nullptr || aNode->m_left == nullptr){
      return aNode;
   }
   else{
      return findMin(aNode->m_left);
   }
 }

 void BST::remove(string val){
   m_root = remove(val,m_root);
 }

 Node* BST::remove(string val, Node* aNode){
   // node is null
   
      //cases if the val is equal to root node then delete root node
      //if not go left and go right 
      //deal with all there cases 
      // 1. After finding the node does the node going to remove has one, two or no child node
      // in case of having two nodes find the minimum one and put that at root node
      // to keep the tree balanced

      //case # 1

   
   if (aNode == nullptr) return aNode;
   // move to left
   else if (val < aNode->m_value)
      aNode->m_left = remove(val,aNode->m_left);
   // move to right
   else if (val > aNode->m_value)
      aNode->m_right = remove(val,aNode->m_right);
   // nodes has two children
   else if (aNode->m_left != nullptr && aNode->m_right != nullptr){
      Node* temp = findMin(aNode->m_right);
      aNode->m_value = temp->m_value;
      aNode->m_right = remove(temp->m_value,aNode->m_right);
   }
   // node has one child/no children
   else{
      Node* temp = aNode;
      if (aNode->m_left == nullptr)
         aNode = aNode->m_right;
      else
         aNode = aNode->m_left;
      delete temp;
   }
   // update heights
   // check if needs rebalance
   // rebalance
   return aNode;
 }

 BST::BST(const BST & rhs){
   copy(m_root, rhs.m_root);
 }
 void BST::copy(Node * & aNode, Node * rhs){
   // if rhs is not null create aNode
   if (rhs != nullptr){
      aNode = new Node(rhs->m_value);
      // move to left
      copy(aNode->m_left, rhs->m_left);
      // move to right
      copy(aNode->m_right, rhs->m_right);
   }
 }