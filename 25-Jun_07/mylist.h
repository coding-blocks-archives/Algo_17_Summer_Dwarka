#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node * next;	//self referential class
	
	Node(int num){
		data = num;
		next = NULL;	//NULL is a macro
	}
};

void addToFront(Node* &head, Node* nodeToAdd){
	if (head == NULL){
		head = nodeToAdd;
		return;
	}

	nodeToAdd->next = head;
	head = nodeToAdd;
}

Node* takeInput(){
	int num;
	Node * head = NULL;

	while(cin >>num && num != -1){
		Node * newNode = new Node(num);
		addToFront(head, newNode);
	}
	return head;
}

void print(Node* head){
	//prints the Linked list
	Node * tmp = head;
	while(tmp != NULL){
		//I have not reached the end
		cout << tmp->data << "-->";
		tmp = tmp->next;
	}
	cout << endl;
}
