//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <numeric>
using namespace std;

int operation(int x, int y){
	//like compare in sort
	return x ^ y;
}

int findUnique(int arr[], int n){
	//take xor of all numbers
	//same numbers will cancel each other : XOR is associative
	int res = accumulate(arr, arr + n, 0, operation);
	//avoid in interview but in contest
	return res;
}


int main(){
	int arr[] = {1,2,3,4,1,2,3};
	int n = sizeof(arr) / sizeof(int);

	int res = findUnique(arr, n);
	cout << res;	
	return 0;
}