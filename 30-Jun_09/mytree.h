//Deepak Aggarwal, Coding Blocks
#ifndef MYTREE_H_
#define MYTREE_H_

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

Node * takeInputLevel(){
	//function to take Input as a tree --levelwise
	int data;
	cin >> data;
	if (data == -1) return NULL;

	Node * root = new Node(data);
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		//there is a node with potential to become parent
		Node *curParent = q.front();
		q.pop();

		int leftData;	cin >> leftData;
		//left child exists, hence create and attach to the parent
		//Also, this child can become Parent in the near future ;)
		if (leftData != -1){
			Node * tmp = new Node(leftData);
			curParent->left = tmp;
			q.push(tmp);
		}

		//similarly for right child
		int rightData; 	cin >> rightData;
		if(rightData != -1){
			Node * tmp = new Node(rightData);
			curParent->right = tmp;
			q.push(tmp);
		}
	}
	return root;
}

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
#endif