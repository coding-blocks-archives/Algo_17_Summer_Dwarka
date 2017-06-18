//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

bool isPermutation(char s1[], char s2[]){
	// int table[26]= {1,2,3,4...26};
	int table[26] = {}; //table of count of each character in s1
	//arrays in cpp are ZERO INITIALISED...

	for(int i = 0; s1[i] != '\0'; ++i){
		//idx is an integral value which is obtained like this
		//'a' - 'a' = 0
		//'d' - 'a' = 4
		int idx = s1[i] - 'a';
		++table[idx];
	}

	//decrement
	for(int i = 0; s2[i] != '\0'; ++i){
		--table[s2[i] - 'a'];
	}

	//check if all zero
	for(int i = 0; i < 26; ++i){
		//OOPS! something is wrong
		if (table[i] != 0)	return false;
	}

	return true;
}

int main(){
	char s1[100];
	char s2[100];
	cin >> s1 >> s2;

	cout << isPermutation(s1, s2);	
}