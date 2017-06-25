//Deepak Aggarwal, Coding Blocks
#ifndef VECTORTEMP_H_
#define VECTORTEMP_H_

#include <iostream>
template <typename T> 

class myVectorTemp{
	T * arr;
	int sze;
	int capacity;

	void reconstruct(){
		//reconstructs the arr into 2x capacity
		T * tmp = new T[2 * capacity];
		for(int i = 0; i < sze; ++i){
			tmp[i] = arr[i];
		}
		capacity = 2 * capacity;
		delete [] arr;
		arr = tmp;
	}
public:
	myVectorTemp(){
		//constructor 1
		arr = new T[10];
		capacity = 10;
		sze = 0;
	}

	myVectorTemp(int n){
		//ctor 2
		//function overloading
		capacity = n;
		arr = new T[capacity];
		sze = 0;
	}

	void push_back(T x){
		if (sze == capacity){
			reconstruct();
		}

		arr[sze] = x;
		++sze;
	}

	void pop_back(){
		if (sze > 0){
			--sze;
		}
	}

	int size(){
		return sze;
	}

	//operator overloading concept introduced
	//same as T at(int idx){
	T operator[](int idx){
		if (idx < sze && idx >= 0)	return arr[idx];
		return -1;
	}

	~myVectorTemp(){
		//no arg is given
		std::cout << "Destructor is called\n";
		delete [] arr;
	}

};

#endif