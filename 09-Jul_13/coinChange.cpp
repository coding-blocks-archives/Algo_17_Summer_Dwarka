//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;
const int inf = 10000;
int arr[] = {1, 3, 5, 6};
int N = 4;


int change(int val, int * memo) {
	if (val == 0) {
		return memo[val] = 0;
	}

	if (val < 0) {
		return inf;
	}

	if (memo[val] != -1) return memo[val];

	int res = inf;

	for (int i = 0; i < N; ++i) {
		int rem = change(val - arr[i], memo);
		int curAns = rem + 1;
		res = min(res, curAns);
	}

	return memo[val] = res;
}

int change(int val){
	int * memo = new int[val + 1];

	// memset(memo, inf, 4 * (val + 1));
	// cout << memo[val] << endl;

	// for(int i = 0; i < val + 1; ++i) memo[i] = inf;

	memo[0] = 0;	//base case

	for(int v = 1; v <= val; ++v){
		for(int i = 0; i < N && arr[i] <= v; ++i){
			int coins = memo[v - arr[i]] + 1;
			memo[v] = min(memo[v], coins);
		}
	}
	return memo[val];
}


int main() {
	int val;	cin >> val;

	// int * memo = new int[val + 1];

	// for(int i = 0;  i <= val; ++i){
	// 	memo[i] = -1;
	// }

	// memset(memo, -1, 4 * (val + 1));	//cstring
	//4 * (val + 1) = 404 bytes

	// cout << change(val, memo);

	cout << change(val);
	// delete [] memo;
}

