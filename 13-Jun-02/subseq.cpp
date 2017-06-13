#include <iostream>
using namespace std;

int cnt = 0;

void subseq(char arr[], int be, char decisionSoFar[], int i){
	if (arr[be] == '\0'){
		decisionSoFar[i] = '\0';
		cout << ++cnt << " " << decisionSoFar <<"\n";
		return;
	}

	subseq(arr, be + 1, decisionSoFar, i);
	decisionSoFar[i] = arr[be];
	subseq(arr, be + 1, decisionSoFar, i + 1);

}


int main(){
	char inp[100];
	cin >> inp;

	char output[100] = "";	//represents decsofar

	//Print all the subsequences of inp starting at pos i
	subseq(inp, 0, output, 0);
	// cout << cnt;
}