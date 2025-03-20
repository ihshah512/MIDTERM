#include "list.h"
using namespace std;
bool testAddFront1();
bool testAddFront2();
void testRemoveFront1();
//this is a sample driver program
//it is not a rigorous test program
//in projects we need to test rigorously
int main(){
    try{
       testAddFront1();
        testAddFront2();
        testRemoveFront1();
    }
    catch(std::runtime_error &e){
        cout << "testRemoveFront1() PASSED!" << endl;
        cout << e.what() << endl;
    }
    return 0;
}
/***************************************
 * Test removeFront() on empty list
 * ************************************/
void testRemoveFront1(){
    LinkedList aPath;
    aPath.removeFront();
}
/***************************************
 * Test addFront() on empty list
 * ************************************/
bool testAddFront1(){
    LinkedList aPath;
    aPath.addFront("ATL");
    if ("ATL" == aPath.front()){
        cout << "testAddFront1() PASSED!" << endl;
        return true;
    }
    else{
        cout << "testAddFront1() FAILED!" << endl;
        return false;
    }
    
}
/***************************************
 * Test addFront() on non-empty list
 * Test removeFront() on non-empty list
 * Test front() on non-empty list
 * ************************************/
bool testAddFront2(){
    bool returnVal = false;
    LinkedList aPath;
    string airports[] = {"BOS","ATL","MSP","LAX"};
    for (int i=0;i<4;i++)
        aPath.addFront(airports[i]);
    for (int j=4;j>0;j--){
        if (aPath.front() == airports[j]){
            returnVal = true;
            aPath.removeFront();
        }
        else
            returnVal = false;
    }
    return returnVal;
}
