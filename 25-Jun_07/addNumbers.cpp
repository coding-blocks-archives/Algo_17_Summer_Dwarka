//Deepak Aggarwal, Coding Blocks
#include "mylist.h"
#include <iostream>
using namespace std;

Node* myreverse(Node * head){
	if (head == NULL || head->next == NULL){
		return head;
	}

	Node * remList = myreverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return remList;
}

Node * addNumbers(const Node* no1, const Node* no2){
// HW--- Node * addNumbers(const Node* no1, const Node* no2){
	no1 = myreverse(no1);
	no2 = myreverse(no2);

	Node* head = NULL;
	Node* tail = NULL;
	int carry = 0;

	while(no1 || no2){
		//while(no1 != NULL || ...)
		int sum = 0;
		if (no1){
			sum += no1->data;
			no1 = no1->next;
		}

		if (no2){
			sum += no2->data;
			no2 = no2->next;
		}

		sum += carry;
		carry = sum / 10;
		sum = sum % 10;

		if (head == NULL){
			head = new Node(sum);
			tail = head;
		}
		else {
			tail->next = new Node(sum);
			tail = tail->next;
		}
	}

	if (carry != 0){
		tail->next = new Node(carry);
		tail = tail->next;
	}

	head = myreverse(head);
	return head;
	//very bad!! we have left the original numbers no1 and no2 in reverse order...should not have
	//done that
}





int main(){
	Node * no1 = takeInput();
	Node * no2 = takeInput();
	print(no1);
	print(no2);

	Node * ans = addNumbers(no1, no2);
	


	print(ans);
}