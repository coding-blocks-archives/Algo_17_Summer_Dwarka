//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int i = 0;

void permutations(char s[], int be, char output[]){
	if (s[be] == '\0'){
		// I am at the string 
		cout << ++i << " " << s << endl;
		return;
	}


	//while I have an element to swap within the range [be, '\0')
	for(int i = be; s[i] != '\0'; ++i){
		swap(s[be], s[i]);

		permutations(s, be + 1, output);
		//all permutation starting with s[be] have been printed

		swap(s[be], s[i]);	//restored the original array
	}
}


int main(){
	char input[100];
	cin >> input;

	char output[100] = "";
	permutations(input, 0, output);	
}