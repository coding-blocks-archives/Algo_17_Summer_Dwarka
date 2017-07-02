//Deepak Aggarwal, Coding Blocks
#include "mytree.h"
#include <iostream>
#include <climits>
using namespace std;

bool isBst(Node* root, int minVal, int maxVal){
	if (root == NULL){
		return true;
	}

	return (
		root->data >= minVal && root->data <= maxVal &&
		isBst(root->left, minVal, root->data) &&
		isBst(root->right, root->data, maxVal)
		);
}


bool isIdentical(Node *root1, Node * root2 ){
	if (root1 == NULL && root2 == NULL){
		return true;
	}

	if (root1 == NULL || root2 == NULL){
		return false;
	}

	return (
		(root1->data == root2->data) &&
		isIdentical(root1->left, root2->left) &&
		isIdentical(root1->right, root2->right)
		);
}


int main(){
	Node * root = takeInputLevel();
	const int inf = INT_MAX;
	bool res = isBst(root, -inf, inf);
	cout << res << endl;

	return 0;
	
}