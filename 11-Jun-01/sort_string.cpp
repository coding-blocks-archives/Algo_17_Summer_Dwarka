#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	// char name[20];
	string name;
	cin >> name;
	sort(name.begin(), name.end());
	cout << name;
}