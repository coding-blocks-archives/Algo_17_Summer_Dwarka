//Deepak Aggarwal, Coding Blocks
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
using namespace std;

class Node {
public:
	string key;
	int data;
	Node* next;		//pointer to the next node in the linked list
	Node() {}		//default ctor should be given, otherwise temporary objects won't be created
	Node(string s, int d) {
		key = s;
		data = d;
		next = NULL;
	}

	~Node() {
		//if next is not null I am going to delete the whole list
		if (next != NULL ) delete next;
	}
};

class Hashtable {
	Node** table;	//table is a pointer to an array of Node* type elements
	int size;		//size of table/array
	int n;			//no of nodes in the table

	void clear() {
		for (int i = 0; i < size; ++i) {
			table[i] = NULL;
		}
	}

	int hash_function(string s) {
		//"abc" = a * 37^0 + b * 37^1 +...
		int pow = 1;
		int idx = 0;

		for (int i = 0; i < s.size(); ++i) {
			idx = idx + s[i] * pow;
			pow = pow * 37;		//prime number reduces collision...Maths!
			pow %= size;		//Modulo Arithmetic : (a + b) % c = (a % c + b % c) % c
			idx %= size;
		}

		return idx;
	}

	void rehash() {
		int oldSize = size;
		size = 2 * oldSize;
		Node ** oldTable = table;
		table = new Node*[size];
		clear();	//sets table to NULL
		n = 0;		//because n will be updated in the insert function

		//for every node in every linked list, insert into the new table
		for (int i = 0; i < oldSize; ++i) {
			Node * ll = oldTable[i];
			while (ll) {
				insert(ll->key, ll->data);
				ll = ll->next;
			}
			delete oldTable[i];

			/*Homework Implement insert function which performs the desired task
			Node* ll = oldTable[i];
			while(ll){
				Node * tmp = ll;
				ll = ll->next;
				tmp->next = NULL;
				insert(tmp);
			}*/
		}

		delete [] oldTable;		//free the reserved memory...Important
	}

	double load_factor() {
		return 1.0 * n / size;	// n and size - both are integers
	}

public:
	Hashtable() {
		size = 7;				//prime is good
		n = 0;
		table = new Node*[size];
		clear();
	}

	void insert(string s, int d) {
		Node * newEle = new Node(s, d);
		int idx = hash_function(s);

		//inserting the new element
		newEle->next = table[idx];	//Make newEle the head of already exisitng LL(if any)
		table[idx] = newEle;
		++n

		if (load_factor() > 0.7) {
			rehash();
		}
	}

	int getData(string s) {
		int idx = hash_function(s);		//Get the index for the right bucket/cell

		Node * cur = table[idx];
		//search in the linked list
		while (cur) {
			if (cur->key == s) {
				return cur->data;
			}
			cur = cur->next;
		}

		return -1;
	}

	bool empty() {
		return n == 0;
	}

	int getSize() {
		return n;
	}

	void remove(string s) {
		if (n == 0) return;

		int idx = hash_function(s);
		Node* cur = table[idx];
		Node* prev = NULL;	//initialisation

		//delete cur from Linked list
		while (cur) {
			if (cur->key == s) {
				if (prev) prev->next = cur->next;	//node is not head
				else table[idx] = cur->next;	//node is head

				cur->next = NULL;	//Imp: Otherwise the whole list will be deleted--See ~Node()
				delete cur;	//free the memory
				--n;
				return;
			}
			prev = cur;
			cur = cur->next;
		}
	}
};

#endif
