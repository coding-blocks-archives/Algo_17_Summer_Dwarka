//Deepak Aggarwal, Coding Blocks
#include "vectorTemp.h"
#include "myvector.h"	//#ifdef avoids duplicate/nested COPYING
#include <iostream>
using namespace std;

int main(){
	myVectorTemp<int> v;	
	//myVectorTemp is not a class but a TEMPLATE or blueprint
	//but, myVectorTemp<int> read as myVectorTemp of int IS
	myVectorTemp<char> c;

	v.push_back(12); cout << v.at(0) << endl;
	c.push_back('a'); cout << c.at(0) << endl;
}