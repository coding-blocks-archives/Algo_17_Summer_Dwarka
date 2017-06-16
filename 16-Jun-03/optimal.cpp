//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

int optimalSol(int arr[], int be, int en){
	//returns the best possible score I can have from coins within [be, en]

	if (be > en){
		return 0;
	}


	int ch1 = optimalSol(arr, be + 2, en);
	int ch2 = optimalSol(arr, be + 1, en - 1);
	//my friend is smart, so he picks the one after which I am left with lower score
	int score1 = arr[be] + min(ch1, ch2);

	//same happens for the right end
	int score2 = arr[en] + min(
		optimalSol(arr, be, en - 2),
		//friend picks from end AFTER I pick arr[en]
		optimalSol(arr, be + 1, en - 1)
		//friend picks arr[be] AFTER I pick arr[en]
		);

	return max(score1, score2);
	//because I play optimally
}


int main(){
	int arr[] = {8, 15, 3, 7};
	int en = sizeof(arr) / sizeof(int) - 1;

	cout << optimalSol(arr, 0, en);	
}