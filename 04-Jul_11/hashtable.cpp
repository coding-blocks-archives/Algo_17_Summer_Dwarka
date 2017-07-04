//Deepak Aggarwal, Coding Blocks
#include "hashtable.h"
#include <iostream>
using namespace std;
int main(){
	Hashtable H;
	H.insert("abc", 123);
	H.insert("def", 456);

	int d = H.getData("def");
	cout << d << endl;
}
