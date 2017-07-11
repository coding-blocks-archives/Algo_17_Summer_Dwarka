//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Node {
public:
	int data;
	Node* random, *next;
	Node(int d) {
		data = d;
		random = NULL;
		next = NULL;
	}
};

void print(Node* head) {
	while (head) {
		cout << head->data << " (" << ((head->random) ? head->random->data : -1) << ")-->";
		head = head->next;
	}
	cout << endl;
}

void setRandom(Node* head) {
	vector<Node *> v;

	Node* tmp = head;
	while (tmp) {
		v.push_back(tmp);
		tmp = tmp->next;
	}

	random_shuffle(v.begin(), v.end());

	tmp = head;
	int i = 0;
	while (tmp) {
		tmp->random = v[i];
		tmp = tmp->next;
		++i;
	}
}

Node* createList() {
	int n;
	Node * head = NULL;
	Node * tail = NULL;

	while (cin >> n && n != -1) {
		Node * tmp = new Node(n);
		if (head == NULL) head = tail = tmp;
		else {
			tail->next = tmp;
			tail = tail->next;
		}
	}
	return head;
}

Node* duplicate(Node* head){
	if (head == NULL){
		return NULL;
	}

	Node * newNode = new Node(head->data);
	newNode->next = duplicate(head->next);
	head->next = newNode;
	return head;
}

typedef pair<Node*, Node*> pnn;
pnn cloning(Node* head){
	if (head == NULL){
		return pnn(NULL, NULL);
	}

	head->next->random = head->random->next;
	pnn remList = cloning(head->next->next);
	
	pnn res;
	res.first = head;
	res.second = head->next;

	res.first->next = remList.first;
	res.second->next = remList.second;
	return res;
}



Node* clonelinked(Node* head){
	Node* duplicated = duplicate(head);
	pair<Node*, Node*> clone = cloning(duplicated);
	return clone.second;
}



Node* cloneLL(Node* head){
	map<Node* , Node*> m;

	//fillMap
	Node* ohead = head;
	Node* chead = NULL;
	Node* ctail = NULL;

	while(ohead){
		Node * newNode = new Node(ohead->data);
		if (chead == NULL){
			chead = ctail = newNode;
		}
		else {
			ctail->next = newNode;
			ctail = ctail->next;
		}

		m[ohead] = newNode;
		ohead = ohead->next;
	}

	//setRandom
	ohead = head;
	Node *clone = chead;
	while(ohead){
		clone->random = m[ohead->random];
		ohead = ohead->next;
		clone = clone->next;
	}

	return chead;
}

int main() {
	Node * head = createList();
	setRandom(head);
	print(head);

	// Node* clone = cloneLL(head);	//mapping
	Node* clone = clonelinked(head);

	print(clone);
}