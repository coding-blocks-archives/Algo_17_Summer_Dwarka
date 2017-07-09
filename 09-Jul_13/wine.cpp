//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;
int arr[] = {2, 3, 5, 1, 4};
int N = 5;

int memo[10][10] = {};

int maxProfit(int be, int en, int years){
	if (be > en){
		return 0;
	}

	if (memo[be][en] != 0) return memo[be][en];
	// int year = N - (en - be + 1);
	int left = years * arr[be] + maxProfit(be + 1, en, years + 1);
	int right = years * arr[en] + maxProfit(be, en - 1, years + 1);
	return memo[be][en] = max(left, right);
}




int main(){
	int ans = maxProfit(0, 4, 1);
	cout << ans;
}