//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <cstring>
using namespace std;

void print(char s[], int i, int j){
	//prints s between range i and j
	while(i <= j){
		cout << s[i];
		++i;
	}
}

void substrings(char s[]){
	int len = strlen(s);

	//starting element
	for(int i = 0; i < len; ++i){
		// controls range
		for(int j = i; j < len; ++j){
			//print string from [i,j]
			print(s, i, j);
			cout << " ";
		}
		cout << endl;
	}
}

int main(){
	char s[100];
	cin >> s;

	substrings(s);	
}