//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <cmath>
using namespace std;
const double epsilon = 0.00001;
double rootFn(double N){
	double low = 1;
	double high = N;
	double root = 0;
	double inc = 0.0001;

	//while I have a valid range
	// while(high - low > epsilon){
	while(low < high){
		root = (low + high) / 2;
		
		// if (root * root == N){	//double should never be equated
		if (abs(root * root - N) < epsilon){
			return root;
		}
		else if ((root * root - N) > epsilon){
		//Not absolute because then I cant determine whether to go to left or right
			high = root - inc;
		}
		else {
			low = root + inc;
		}
	}
	return root - inc;
}


int main(){
	//binary searching the answer
	double N;
	cin >> N;
	cout << rootFn(N);	
	// rootFn(N, precision);
}