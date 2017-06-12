#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void outputVector(const vector<int>& v){
	for(int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << endl;
}

void outputarray(const int arr[], int n){
	for(int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	// vector<int> vi;
	int n;
	cin >> n;
	// vi.resize(n);

	int vi[100];
	for(int i = 0; i < n; ++i){
		cin >> vi[i];
	}
	// sort(vi.begin(), vi.end());
	// sort(&vi[0], &vi[0] + n);
	sort(vi, vi + n);

	// outputVector(vi);
	outputarray(vi, n);

}