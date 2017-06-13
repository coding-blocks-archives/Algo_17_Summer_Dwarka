#include <iostream>
using namespace std;

int step = 0;

void toh(int n, char src, char dest, char helper){
	if (n == 0) return;

	toh(n - 1, src, helper, dest);
	cout << ++step << ". Move " << n << "th disc from " << src << " to " << dest << endl;
	toh(n-1, helper, dest, src);
}


int main(){
	int n; cin >> n;

	// prints the steps required to shift n disc from src to dest using helper
	toh(n, 'A', 'B', 'C');
}