//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
using namespace std;
int N = 5;

int maxProfit(int arr[]) {

	int dp[10][10] = {};

	for (int i = N - 1; i >= 0; --i) {
		for (int j = i; j < N; ++j) {
			int curYr = N - (j - i);
			if (i == j){
				dp[i][j] = curYr * arr[i];
			}

			else {
				dp[i][j] = max(curYr * arr[i] + dp[i + 1][j],
			                 curYr * arr[j] + dp[i][j - 1]
			                );
			}
		}
	}
	return dp[0][N -1];
}


int main() {
	int arr[] = {2, 3, 5, 1, 4};

	int ans = maxProfit(arr);

	cout << ans << endl;
}
