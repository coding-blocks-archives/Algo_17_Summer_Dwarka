//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	char arr[100];
	int x;
	cin >> x;
	cin.ignore();
	for(int i = 0; i < 5; ++i){
		// cin >> arr;
		cin.getline(arr, 90);
		cout << arr << endl;
	}	
}