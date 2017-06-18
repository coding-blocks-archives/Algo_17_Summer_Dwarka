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

void substrings(char s[], int be, int len){
	if (s[be] == '\0'){
		// I have nothing to print 
		return;
	}
	for(int en = be; en < len; ++en){
		print(s, be, en);
		cout << " ";
	}
	cout << endl;
	substrings(s, be + 1, len);
}


int main(){
	char s[100];
	cin >> s;
	int len = strlen(s);
	//prints all the substrings starts from i
	substrings(s, 0, len);	
}