#include <iostream>
using namespace std;

void myMerge(int arr[], int be, int en){
	int mid = (be + en) / 2;
	int nLeft = mid - be + 1;
	int nRight = en - mid;
	int *left = new int[nLeft];
	int *right = new int[nRight];

	for(int i = 0; i < nLeft; ++i){
		left[i] = arr[i + be]; 
	}

	for(int i = 0; i < nRight; ++i){
		right[i] = arr[mid + i + 1];
	}

	int k = be;	//main array idx
	int i = 0;	//left array idx
	int j = 0;	//right array idx

	while(i < nLeft && j < nRight){
		if (left[i] < right[j]){
			arr[k] = left[i];
			k++;
			++i;
		}
		else {
			arr[k++] = right[j++];
		}
	}

	while(i < nLeft) arr[k++] = left[i++];
	while(j < nRight) arr[k++] = right[j++];

	delete [] left;
	delete [] right;
}




void mergeSort(int arr[], int be, int en){
	if (be >= en){
		//either 1 or 0 elements
		return;
	}

	int mid = (be + en) / 2;
	mergeSort(arr, be, mid);
	mergeSort(arr, mid + 1, en);

	// myMerge(arr, be, mid, arr, mid + 1, en);
	myMerge(arr, be, en);
}


int main(){
	int arr[100];
	int n; cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i];

	mergeSort(arr, 0, n - 1);
	
	for(int i = 0; i < n; ++i) cout << arr[i] << " ";

}