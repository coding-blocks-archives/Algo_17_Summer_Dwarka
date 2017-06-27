//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

bool doesKnow(int x, int y){
	static mat[][4] = {
		{0, 0, 1, 1},
		{0, 0, 1, 0},
		{0, 0, 0, 0},
		{1, 1, 1, 1}
	};
	return mat[x][y];
}

int celeb(int N){
	//implement it!
}

int main(){
	int N = 4;
	//Four people viz. 0 1 2 3
	cout << celeb(N); // 2 is the celeb
}