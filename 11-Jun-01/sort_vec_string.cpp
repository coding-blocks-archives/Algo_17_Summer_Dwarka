#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compareStr(const string& A, const string& B){
	return A.size() > B.size();
}

int  main(){
	vector<string> vs;

	int n;	cin >> n;
	vs.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> vs[i];
	}

	sort(vs.begin(), vs.end(), compareStr);

	for(int i = 0; i < n; ++i){
		cout << vs[i] << " ";
	}
}