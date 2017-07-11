//Deepak Aggarwal, Coding Blocks
#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
	int data;
	Node *left;
	Node* right;
	Node(int n){
		data = n;
		left = NULL;
		right = NULL;
	}
	// friend ostream& operator<<(ostream& writer, Node * root);
};

void printLevel(Node * root){
	queue<Node * > q;
	q.push(root);
	q.push(NULL);

	while(q.empty() == false){
		//I have atleast one node to print
		Node* cur = q.front();
		q.pop();
		
		//delimiter case
		if(cur == NULL){
			cout << endl;
			if (!q.empty()){
				q.push(NULL);
			}
			continue;
		}


		cout << cur->data << " ";
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
}

void inorder(Node * root){
	if (root == NULL) return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

Node * insertInBst(Node * root, int data){
	//Function returns the root of the "updated" tree after insertion 
	if (root == NULL){
		Node *tmp = new Node(data);
		return tmp;
	}

	if (root->data < data){
		root->right =  insertInBst(root->right, data);
		return root;
	}

	else {
		root->left = insertInBst(root->left, data);
		return root;
	}
}



Node* takeInput(){
	int n;
	Node * root = NULL;

	while(cin >> n && n != -1){
		root = insertInBst(root, n);
	}

	return root;
}

#endif