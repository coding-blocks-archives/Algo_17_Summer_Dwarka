#include <iostream>
using namespace std;

int myPow(int x, int y){
	if (y == 0) return 1;

	int smallerans = myPow(x, y - 1);
	int currAns = smallerans * x;
}
//fast power function



int main(){
	int x, n;
	cin >> x >> n;
	int xtoN = myPow(x,n);
	cout << xtoN;
}