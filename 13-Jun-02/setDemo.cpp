#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
	set<string> ss;

	ss.insert("def");
	ss.insert("abc");
	ss.insert("ghi");
	ss.insert("abc");

	// set<string>::iterator it = ss.find("ab");
	// if (it != ss.end()) cout << *it;
	// else cout << "Value not found";


	//read full set
	for(set<string>::iterator it = ss.begin(); it != ss.end(); ++it){
		cout << *it << endl;
	}
}