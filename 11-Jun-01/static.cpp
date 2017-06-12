#include <iostream>
using namespace std;

// char * getname(){
string getname(){
	// char name[20];
	// char * name = new char[20];
	string name;
	cin >> name;
	return name;
}


int main(){
	cout << "Enter name ";
	// char * myname = getname();
	string myname = getname();
	cout << myname;
}
