//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
const int N = 9;

void print(int board[][N]){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << board[i][j] << " " ;
		}
		cout << endl;
	}
}

bool canPlace(int board[][N], int x, int y, int num){
	//check in row
	for(int c = 0; c < N; ++c){
		if (board[x][c] == num)	return false;
	}
	//check in col
	for(int r = 0; r < N; ++r){
		if (board[r][y] == num) return false;
	}
	//check in box	
	int rootN = 3;	//sqrt(N)
	int box_rst = (x / rootN) * rootN;
	//				box No
	int box_cst = y / rootN * rootN;

	for(int i = box_rst; i < box_rst + 3; ++i){
		for(int j = box_cst; j < box_cst + 3; ++j){
			if (board[i][j] == num) return false;
		} 
	}

	return true;
}

bool sudoku(int board[][N], int x, int y){
	if (x == N){
		return true;
	}

	//row x was filled
	if (y == N){
		return sudoku(board, x + 1, 0);
	}

	//the x,y cell is filled
	if (board[x][y] != 0){
		return sudoku(board, x, y + 1);
	}

	//for number 1-9
	for(int num = 1; num <= N; ++num){
		//if I can place number, I will place and I hope that I have placed it correctly
		if (canPlace(board, x, y, num)){
			board[x][y] = num;
			//fill the remaining board-->Yup! Number placed was correct
			bool wasSolved = sudoku(board, x, y + 1);
			if (wasSolved == true){
				return true;
			}
			board[x][y] = 0;	//restore the previous state
			//delete the num which I have kept
		}
	}
	//sudoku cant be solved 
	return false;
}

int main(){
	int board[N][N] = 
	    {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};	

    bool solved = sudoku(board, 0, 0);
    if (solved == true){
    	print (board);
    }
    else {
    	cout << "Too Hard for me. Can't be solved";
    	//Invalid input
    }
}