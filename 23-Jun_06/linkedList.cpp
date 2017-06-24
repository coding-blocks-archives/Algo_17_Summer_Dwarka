//Deepak Aggarwal, Coding Blocks
#include <iostream>
#include "mylist.h"
using namespace std;

int length(Node* head){
	Node * cur = head;
	int cnt = 0;
	while(cur){
		++cnt;
		cur = cur->next;
	}
	return cnt;
}

void bubbleSort(Node * &head){
	int len = length(head);

	//sort n elements
	for(int i = 0; i < len; ++i){
		Node * prev = NULL;
		Node * cur = head;
		//one element will be placed at the correct position
		//i.e. remaining elements need to be iterated
		while(cur != NULL && cur->next != NULL){
			Node * ahead = cur->next;

			if (cur->data > ahead->data){
				//I have to swap
				if (prev == NULL){
					cur->next = ahead->next;
					ahead->next = cur;
					head = ahead;
					prev = ahead;
				}
				else {
					prev->next = ahead;
					cur->next = ahead->next;
					ahead->next = cur;
					prev = ahead;
				}
			}
			else{
				//no swapping
				prev = cur;
				cur = cur->next;
				// ahead = cur->next->data;
			}
		}

	//DO IT YOURSELF
		// for(int j = 0; j < len - i; ++j){
		// 	if (cur->data > cur->next->data){

		// 	}
		// }

	}
}


int main(){
	Node * head = takeInput();
	print(head);
	bubbleSort(head);
	print(head);
}