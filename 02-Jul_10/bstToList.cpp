//Deepak Aggarwal, Coding Blocks
#include "bst.h"
#include <iostream>
using namespace std;

class LL{
public:
    Node * head;
    Node * tail;
    LL(){
        head = tail = NULL;
    }
} ;

void print(LL myList){
    Node * strt = myList.head;

    while(strt != NULL){
        cout << strt->data << "-->";
        strt = strt->right;
    }
}


LL bstToList(Node * root){
    if (root == NULL){
        LL l;
        l.head = NULL;
        l.tail = NULL;
        return l;
    }

    LL curList;

    LL left = bstToList(root->left);
    if (left.head != NULL){
        curList.head = left.head;
        left.tail->right = root;
    }
    else{
        curList.head = root;
    }

    LL right = bstToList(root->right);
    
    if (right.head != NULL){
        root->right = right.head;
        curList.tail = right.tail;
    }
    else {
        curList.tail = root;
    }

    return curList;
}




int main(){
    Node * root = takeInput();
    
    LL myList = bstToList(root);

    print(myList);

}
