//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include "mylist.h"
using namespace std;

Node * middle(Node* head){
	Node * slow_p = head;
	Node * fast_p = head;
	// while(slow_p != NULL) ==> slow_p exists
	while(slow_p && fast_p && fast_p->next && fast_p->next->next){
	// while(slow_p && fast_p && fast_p->next){
	// cant be used because requirement of mergesort says that middle element in 
	// even case should be the first elemen

		slow_p = slow_p->next;
		fast_p	= fast_p->next->next;
	}

	return slow_p;
}


Node * myMerge(Node *left, Node* right){
	if (left == NULL){
		return right;
	}

	if (right == NULL){
		return left;
	}

	if (left->data < right->data){
		left->next = myMerge(left->next, right);
		return left;
	}
	else {
		right->next = myMerge(right->next, left);
		return right;
	}
}


void mergeSort(Node* &head){
	//list is empty
	if (head == NULL){
		return;
	}

	//if just one element
	if (head->next == NULL){
		return;
	}

	//its confirmed that there are ATLEAST 2 elements
	Node * midEle = middle(head);
	Node * right = (midEle == NULL) ? NULL : midEle->next;
	
	if (midEle)	midEle->next = NULL;	
	//head now is a "new" list with termination at midEle

	mergeSort(head);
	mergeSort(right);
	Node * sortedList = myMerge(head, right);
	head = sortedList;

}


int main(){
	// Node *head1 = takeInput();
	// Node *head2 = takeInput();
	// print(head1);
	// print(head2);
	// print(myMerge(head1, head2));


	Node * head = takeInput();
	print(head);
	mergeSort(head);
	print(head);		
}