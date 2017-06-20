//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
const int BITS = 32;

int calcNum(int cnt[]){
	int res = 0;
	for(int i = 0; i < BITS; ++i){
		//Avoid pow function
		res += cnt[i] * (1 << i);
		//(1 << i) is same as 2^i 
	}
	return res;
}


void setCnt(int cnt[], int num){
	//updates cnt : Increase the element at index i IF the ith bit of num is 1
	int i = 0;
	while(num){
		//keep updating the cnt
		cnt[i] += num & 1;
		num >>= 1;
		++i;
	}
}


int findUnique(int arr[], int n){
	int cnt[BITS] = {};		//hack---all zero

	//set the cnt array as per requirement
	//requirement is to set each element in cnt as per cnt of set bits in arr
	for(int i = 0; i < n; ++i){
		setCnt(cnt, arr[i]);
	}

	//eliminate all bits that are present because of number occuring thrice
	for(int i = 0; i < BITS; ++i){
		cnt[i] = cnt[i] % 3;
	}

	//calculate the number from cnt ARRAY
	int res = calcNum(cnt);
	return res;
}


int main(){
	int arr[] = {1,2,3,1,2,3,1,2,3,(1<<18) + 999};
	int n = sizeof(arr) / sizeof(int);

	int res = findUnique(arr, n);	
	cout << res;
}