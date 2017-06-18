//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

int rotatedSearch(int arr[], int low, int high, int searchFor){
	while(low <= high){
		int mid = (low + high) / 2;

		//found the key??
		if (arr[mid] == searchFor){
			return mid;
		}

		//to check if the array is sorted or not
		if (arr[low] < arr[mid]){
			//binary search condition
			//we are sure that IFF searchFor exists it exists in [low, mid)
			if (arr[low] <= searchFor && arr[mid] >= searchFor){
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		//left array is not sorted, that means the other half has to be scanned
		else {
			//we are sure that IFF searchFor exists, it exists in (mid, high]
			if (arr[mid] <= searchFor && arr[high] >= searchFor){
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
	}
	return -1;

}

int main(){
	int arr[] = {3, 4, 5, 1, 2};
	int n = sizeof(arr) / sizeof(int);
	int x;	cin >> x;

	int idx = rotatedSearch(arr, 0, n - 1, x);

	cout << idx << endl;

}