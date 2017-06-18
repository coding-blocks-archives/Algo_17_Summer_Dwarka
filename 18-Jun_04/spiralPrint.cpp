//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
void input2D(char mat[][10], int m, int n){
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat[i][j];
		}
	}
}


void printSpiral(char mat[][10], int m, int n){
	int left = 0;
	int right = n - 1;
	int top = 0;
	int bottom = m - 1;

	while(left <= right || top <= bottom){
		//print left to right : top elements
		if(top <= bottom){
			for(int i = left; i <= right; ++i){
				cout << mat[top][i];
			}
			top = top + 1;
		}

		if (left <= right){
			//print top to bottom : right elements
			for(int i = top; i <= bottom; ++i){
				cout << mat[i][right];
			}
			right = right - 1;
		}

		//print right to left : bottom
		if (top <= bottom){
			for(int col = right; col >= left; --col){
				cout << mat[bottom][col];
			}
			--bottom;
		}

		//print bottom to top : left
		if (left <= right){
			for(int row = bottom; row >= top; --row){
				cout << mat[row][left];
			}
			left++;
		}
	}
}



int main(){
	char mat[10][10];
	int m, n;
	cin >> m >> n;
	input2D(mat, m, n);

	printSpiral(mat, m, n);	
}