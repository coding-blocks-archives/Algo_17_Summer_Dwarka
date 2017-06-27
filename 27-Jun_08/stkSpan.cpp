//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> stkSpan(int prices[], int n){
	vector<int> span(n);
	stack<int> prevGreater;		//stores index
	
	for(int i = 0; i < n; ++i){
		while(prevGreater.empty() == false){
			int idx = prevGreater.top();
			//remove all useless elements---Useless because they will not be encountered in the calculation
			//of span of upcoming stock days
			if (prices[idx] < prices[i]){
				prevGreater.pop();
			}
			else {
				break;
			}
		}
		int best = prevGreater.empty() ? 0 : prevGreater.top();
		span[i] = i - best;
		prevGreater.push(i);	
	}

	return span;
}


int main(){
	int prices[10];
	int n; cin >> n;

	//input
	for(int i = 0; i < n; ++i){
		cin >> prices[i];
	}	

	vector<int> ans = stkSpan(prices, n);

	//for each available in C++ 99
	for_each(prices, prices + n, [](int x){cout << x <<  " ";});	//print prices
	//[](int x) can be replaced by a COMPARATOR like function

	cout << endl;

	for_each(ans.begin(), ans.end(), [](int x){ cout << x << " ";});	//print ans
}