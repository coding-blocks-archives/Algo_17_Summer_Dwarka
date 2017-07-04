//Deepak Aggarwal, Coding Blocks

#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>
#include <vector>
using namespace std;

class heap{
	vector<int> v;
	int size;
	int parent(int i) {return i >> 1;} 	//i = i / 2
	int left(int i) { return i << 1;}
	int right(int i) {return (i << 1) + 1;}

	void heapify(int i ){
		if (i >= size) return;

		int pos = i;
		if (left(i) <= size && v[left(i)] < v[pos]){
			pos = left(i);
		}

		if (right(i) <= size && v[right(i)] < v[pos]){
			pos = right(i);
		}

		if (pos == i) return;
		swap(v[pos], v[i]);
		heapify(pos);
	}

public:
	heap(){
		v.push_back(-1);
		size = 0;
	}

	void push(int data){
		v.push_back(data);
		++size;

		int i = size;
		while(parent(i) >= 1 && v[i] < v[parent(i)]){
			swap(v[parent(i)], v[i]);
			i = parent(i);
		}
	}

	void pop(){
		if (size < 1) return ;

		swap(v[1], v[size]);
		--size;
		v.pop_back();
		heapify(1);
	}

	int top(){
		if (size >= 1) return v[1];
		return -1;
	}

	int sze(){
		return size;
	}
};

#endif
