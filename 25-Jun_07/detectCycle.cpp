//Deepak Aggarwal, Coding Blocks
#include "mylist.h"
#include <iostream>
using namespace std;


// bool detectCycle(Node* head){
Node* detectCycle(Node* head){
	//detectCycle modified to return the node where fast and slow intersects
	Node* slow = head;
	Node* fast = head;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast){
			// return true;
			return fast;
		}
	}
	// return false;
	return NULL;
}


bool removeCycle(Node* head, Node* intersect){
	//Do that m+k is an INTEGRAL multiple of no of nodes in the loop
	Node *slow = head;
	//need previous to set remove the loop
	Node *prev = NULL;

	while(slow != intersect){
		slow = slow->next;
		prev = intersect;
		intersect = intersect->next;
	}

	prev->next = NULL;	//loop removed
}

int main(){
	Node * head = takeInput();
	print(head);
	head->next->next->next->next = head->next;

	// bool isCycle = detectCycle(head);
	removeCycle(head, detectCycle(head));
	
	print(head);

	
}