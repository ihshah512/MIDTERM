#include <iostream>
#include <string>
#include "bst.h"
using namespace std;
int main(){
    string inputStr[] = {"D", "B", "F", "A", "C", "E", "G"};
    BST aTree;
    
    for (int i=0;i<7;i++){
        aTree.insert(inputStr[i]);
    }
    
    aTree.dump();
    cout << endl;
    BST bTree(aTree);
    bTree.dump();
    cout << endl;
    return 0;
}