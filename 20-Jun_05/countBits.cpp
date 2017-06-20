//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;

int countBits(int num){
	int cnt = 0;
	//while I have number to process
	while(num){
		//do something
		cnt += (num & 1);
		//discards the last bit
		// num = num >> 1;
		num >>= 1;
	}
	return cnt;
}


int main(){
	int num;
	cin >> num;
	int res = countBits(num);

	cout << res;	
}