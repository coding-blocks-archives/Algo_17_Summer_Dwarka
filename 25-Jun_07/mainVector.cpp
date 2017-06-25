//Deepak Aggarwal, Coding Blocks

#include "myvector.h"
#include <iostream>
using namespace std;

void foo(){
	myVector V2(10);	
}

int main(){
	foo();
	myVector V1;

	V1.push_back(10);
	int i = V1.size();
	cout << i;
}