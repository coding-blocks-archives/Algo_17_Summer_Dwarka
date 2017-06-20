//Deepak Aggarwal, Coding Blocks
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


Node* takeInput(int n){
	//take n numbers and add each successive number to the front of LL
	Node * head = NULL;
	for(int i = 0; i < n; ++i){
		int num;
		cin >> num;
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

//cout << head
//prints the linked list


int main(){
	int n;
	cout << "Enter no of elements in the list: ";
	cin >> n;
	Node * head = takeInput(n);
	print(head);
		
}