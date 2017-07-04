//Deepak Aggarwal, Coding Blocks
#include <map>
#include <iostream>
#include <utility>
using namespace std;

int main(){
	map<string, int> m;	//m contains nodes which are pair<key, val>

	m["abc"] = 1;	//automatically creates a pair
	m.insert(make_pair("xyz", 3));
	
	pair<string, int> p("def", 2);
	m.insert(p);

	map<string, int>::iterator it = m.begin();		//begin of container...conceptually
	map<string, int>::iterator it_end = m.end();	//end of container

	while(it != it_end){
		pair<const string, int>& p = *it;	
		//reference to an already existing object
		//avoids unnecessary copying
		cout << p.first << " " << p.second << endl;
		//first element is key
		//second element is value
		++it;
	}
}