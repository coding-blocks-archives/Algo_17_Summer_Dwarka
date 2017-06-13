#include <iostream>
using namespace std;

void shift2(char arr[], int be){
	int j = be;
	
	while(arr[j] != '\0') ++j;

	while(j >= be){
		arr[j + 2] = arr[j];
		--j;
	}
}


void replacepi(char arr[], int be){
	if (arr[be] == '\0'){
		// I am at the end of the string
		return;
	}

	if (arr[be] == 'p' && arr[be + 1] == 'i'){
		shift2(arr, be + 2);
		arr[be] = '3';
		arr[be + 1] = '.';
		arr[be + 2] = '1';
		arr[be + 3] = '4';
		replacepi(arr, be + 4);
	}
	else{
		replacepi(arr, be + 1);
	}
}



int main(){
	char inp[100];
	cin >> inp;

	replacepi(inp, 0);

	cout << inp;
	return 0;
}