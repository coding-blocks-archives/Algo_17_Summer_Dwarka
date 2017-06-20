//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char str[] = "Hey, Coding Blocks is Fun";

	char* token = strtok(str, " ,");
	//strtok MODIFIES the original string
	cout << str << endl;

	//prints the first token
	cout << token << endl;

	while(token){
		//call to print subsequent tokens
		//NULL should be given. Why? Specification :)
		token = strtok(NULL, " ");
		cout << token << endl;
	}
	
}