//Deepak Aggarwal, Coding Blocks
#include "bst.h"
#include <iostream>
using namespace std;

Node * arrToTree(int arr[], int be, int en){
	if (be > en){
		return NULL;
	}

	int mid = (be + en) / 2;
	Node * root = new Node(arr[mid]);

	root->left = arrToTree(arr, be , mid - 1);
	root->right = arrToTree(arr, mid + 1, en);

	return root;
}


int main(){
	int arr[] = {1,2,3,4,5,6,7};

	Node * root = arrToTree(arr, 0, 6);
	printLevel(root);

	return 0;	
}