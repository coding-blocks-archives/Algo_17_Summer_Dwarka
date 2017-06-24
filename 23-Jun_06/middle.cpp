#include <iostream>
#include "mylist.h"
Node * middle(Node* head){
	Node * slow_p = head;
	Node * fast_p = head;
	// while(slow_p != NULL) ==> slow_p exists
	//returns the later middle
	while(slow_p && fast_p && fast_p->next){
	
	// while(slow_p && fast_p && fast_p->next && fast_p->next->next){
		//will return the first middle
		
		slow_p = slow_p->next;
		fast_p	= fast_p->next->next;
	}

	return slow_p;
}

int main(){
	Node* head = takeInput();
	print(head);
	Node * mid = middle(head);
	cout << mid << endl;
	if (mid) cout << mid->data <<endl;


}