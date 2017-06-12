#include <iostream>
using namespace std;

int fib(int n){
	//base case
	if (n == 0) return 0;
	if (n == 1) return 2;
	//rescursive step
	int nth = fib(n - 1) + fib(n - 2);
	return nth;
}

int main(){
	int n;
	cin >> n;
	int nthFib = fib(n);
	cout << nthFib;
}