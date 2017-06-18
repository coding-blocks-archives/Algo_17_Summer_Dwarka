//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <algorithm>
using namespace std;

void rotatedarr1(int arr[], int n){
	//O(NlogN)
	sort(arr, arr + n);

	for(int i = 0; i < n; i += 2){
		if (i + 1 < n) {
			//swap adjacent elements
			swap(arr[i], arr[i + 1]);
		}
	}
}

void rotatedarr2(int arr[], int n){
	//all even pos elements are GREATER than the prev odd pos and next odd pos elements
	for(int i = 0; i < n; i += 2){
		//i - 1 prevents -ve idx
		if (i - 1 >= 0 && arr[i] < arr[i - 1]){
			swap(arr[i], arr[i -  1]);
		}

		//i+1 prevents idx exceeding last index
		if (i + 1 <= n - 1 && arr[i] < arr[i + 1]){
			swap(arr[i] , arr[i + 1]);
		}
	}
}


int main(){
	int arr[] = {10 , 5, 2, 7, 11, 16, 18};
	int n = sizeof(arr) / sizeof(int);
	// cout << n;
	rotatedarr2(arr, n);

	for(int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
}