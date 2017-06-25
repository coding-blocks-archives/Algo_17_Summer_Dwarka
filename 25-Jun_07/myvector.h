//Deepak Aggarwal, Coding Blocks

#ifndef MYVECOTR_H_	
//if THIS(MYVECTOR_H_) block is not defined till this line, execute the following code
#define MYVECOTR_H_
//name this piece of code as MYVECTOR_H_ !!!conditional compilation
//avoids nesting of classes

#include <iostream>
class myVector{
	int * arr;	//to store a dynamic array
	int sze;
	int capacity;

	void reconstruct(){
		//reconstructs the arr into 2x capacity
		int * tmp = new int[2 * capacity];
		for(int i = 0; i < sze; ++i){
			tmp[i] = arr[i];
		}
		capacity = 2 * capacity;
		delete [] arr;
		arr = tmp;
	}
public:
	myVector(){
		//constructor 1
		arr = new int[10];
		capacity = 10;
		sze = 0;
	}

	myVector(int n){
		//ctor 2
		//function overloading based on parameters
		capacity = n;
		arr = new int[capacity];
		sze = 0;
	}

	void push_back(int x){
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

	int at(int idx){
		if (idx < sze && idx >= 0)	return arr[idx];
		return -1;
	}

	~myVector(){
		//no arg is given in destructors
		std::cout << "Destructor is called\n";
		delete [] arr;
	}

};
#endif