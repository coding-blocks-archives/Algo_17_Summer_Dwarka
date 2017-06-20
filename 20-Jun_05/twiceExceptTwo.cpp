//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

int findXor(int arr[], int n){
	//calculates xor of all numbers in array of size n
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans ^= arr[i];
	}
	return ans;
}

void findPair(int arr[], int n){
	//finds two elements that occur only once in an array where all other 
	//elements occur exactly twice

	//calculating xor of all numbers
	int xored = findXor(arr, n);
	//xored is now no1^no2

	//Finding the least significant set bit
	int setBit = xored & (-xored);
	// cout << "Number corresponding to Set Bit is  " << setBit << endl;
	
	//find one of the unique numbers
	int no1 = 0;
	for(int i = 0; i < n; ++i){
		//if the number, arr[i] has required bit set to 1, take it
		if ((setBit & arr[i]) != 0){
 			no1 = no1 ^ arr[i];
		}
		// cout << endl;
	}

	//xor of no1 and all numbers (no1^no2), gives no2
	int no2 = no1 ^ xored;

	//try returning two elements
	cout << no1 << " " << no2 << endl;

}

int main(){
	int arr[] = {1,2,1,2,3,5};
	int n = sizeof(arr) / sizeof(int);

	findPair(arr, n);	
}