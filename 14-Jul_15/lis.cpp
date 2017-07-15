//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 100000000;

//lis computes the length of LIS ending at index en and also sets the last index of that subsequence
int lis(int arr[], int en, int& endIndex){
//ERROR!!!

	if (en == 0){
		endIndex = en;
		return 1;
	}

	int bestSoFar = -inf;
	int curLen = 0;
	bool endIndexUpdated = false; 

	for(int i = 0; i < en; ++i){
		int len = lis(arr, i, endIndex);
		
		if (arr[endIndex] < arr[en]){
			//I want that IFF en corresponds to the bestSoFar then endIndex should be updated
			endIndexUpdated = true;
			endIndex = en;		
			len += 1;
			curLen = len;
		}
		bestSoFar = max(bestSoFar, len);
	}

	if (bestSoFar == curLen && endIndexUpdated) endIndex = en; 
	
	return bestSoFar;
}


int lis(int arr[], int n){
	int dp[n];		//not allowed by standard
	//dp[x] stores the lis ending at x including the xth element
	
	memset(dp, 1, 4 * n);	//only applicable to small lengths
	
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < i; ++j){
			int curLen = 0;
			
			if (arr[j] < arr[i]){
				curLen = dp[j] + 1;
			}
			
			dp[i] = max(dp[i], curLen);
		}
	}

	int* ans = max_element(arr, arr + n);

	return *ans;
}



int main(){
	// int arr[] = {-4, 2, -5, -3};
	int arr[] = {-3, 4, -100, -98, -97};
	
	int n = sizeof(arr) / sizeof(int);

	int endIndex = -1;

	int ans = lis(arr, n - 1, endIndex);	
	cout << ans << " " << endIndex;
	
	// int ans = lis(arr, n );
	// cout << ans;
}