//Deepak Aggarwal, Coding Blocks
#include "bst.h"
#include <iostream>
using namespace std;

void printKk(Node * root, int K1, int K2){
	if (root == NULL){
		return;
	}

	if (root->data >= K1 && root->data <= K2){
		cout << root->data << " ";
	}

	//-------K1-----Root-------K2------
	//---------++++++	Printing + elements
	if (K1 < root->data){
		printKk(root->left, K1, K2);
	}

	//------------------+++++++  Printing (Root, K2] elements
	if (K2 > root->data){
		printKk(root->right, K1, K2);
	}
}

Node * searchBST(Node * root, int x){
	if (root == NULL){
		return NULL;
	}

	if (root->data == x){
		return root;
	}
	else if (x > root->data){
		return searchBST(root->right, x);
	}
	else return searchBST(root->left, x);

}



int main(){
	Node * tree = takeInput();
	// printLevel(tree);
	// inorder(tree);

	// int k1, k2;
	// cout << "Enter K1 K2 ";
	// cin >> k1 >> k2;
	// printKk(tree, k1, k2);

	// int x; cin >> x;
	// Node * res = searchBST(tree, x);
	// if (res != NULL) cout << res->data;


}