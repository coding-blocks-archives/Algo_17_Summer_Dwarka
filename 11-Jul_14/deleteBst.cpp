#include <iostream>
#include "bst.h"
using namespace std;

Node* successor(Node* root){
	if (root == NULL){
		return NULL;
	}

	Node * tmp = root->right;
	while(tmp && tmp->left){
		tmp = tmp->left;
	}
	return tmp;
}

Node* deleteNode(Node* root, int d){
	if (root == NULL){
		return NULL;
	}

	if (root->data == d){
		//we have the node to be deleted
		if (!root->left && !root->right){
			delete root;
			return NULL;
		}
		else if(!root->left){
			Node* tmp = root->right;
			delete root;
			return tmp;

		}
		else if(!root->right){
			Node* tmp = root->left;
			delete root;
			return tmp;
		}
		else{
			Node* justGreater = successor(root);
			swap(justGreater->data, root->data);
			root->right = deleteNode(root->right, justGreater->data);	//Noteworthy
			return root;
		}
	}

	if (d < root->data){
		root->left = deleteNode(root->left, d);
		return root;
	}
	else {
		root->right = deleteNode(root->right,d);
		return root;
	}
}


int main() {
	Node * root = takeInput();
	printLevel(root);
	
	int data;
	cout << "Enter node to be deleted\n";
	cin >> data;

	root = deleteNode(root, data);
	printLevel(root);
	
	return 0;
}