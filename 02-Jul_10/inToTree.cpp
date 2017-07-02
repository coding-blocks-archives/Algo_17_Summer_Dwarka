//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include "mytree.h"
using namespace std;

int search(int arr[], int be, int en, int x){
	while(be <= en){
		if (arr[be] == x)	return be;
		++be;
	}
}

Node * arrToTree(int in[], int pre[], int be, int en){
	/*
	arrToTree RETURNS a tree constructed from in within range [be, en] and using pre
	*/

	static int i = 0;
	if (be > en){
		return NULL;
	}

	Node * root = new Node(pre[i++]);

	int idx = search(in, be, en, root->data);

	root->left = arrToTree(in, pre, be, idx - 1);
	root->right = arrToTree(in, pre, idx + 1, en);
	return root;

}


int main() {

	int pre[] = {5, 4, 3, 2, 7, 6, 1};
	int in[] = {3, 4, 2, 5, 6, 7, 1};

	Node * 	tree = arrToTree(in, pre, 0, 6);

	// preorder(tree);
	// cout << endl;
	// inorder(tree);

	printLevel(tree);
}