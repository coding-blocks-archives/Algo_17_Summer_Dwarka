#include <iostream>
int M, N;
using namespace std;
int path[10][10];   //saves the path

void printChar(char board[][10]){
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j) cout << board[i][j] << " ";
            cout << endl;
    }
}


void printInt(int board[][10]){
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j) cout << board[i][j] << " ";
            cout << endl;
    }
}

bool sol(char board[][10], int x, int y){
    //if I am goal
    if (x == M - 1 && y == N - 1){
        path[x][y] = 1;
        return true;
    }

    if (board[x][y] == 'X') return false;

    path[x][y] = 1;

    if (y < N){
        if (sol(board, x, y + 1) == true){
            return true;
        }
    }

    if (x < M){
        if (sol(board, x + 1, y) == true){
            return true;
        }
    }

    path[x][y] = 0;
    return false;
}


int main(){
	char maze[][10] = {
		"0X00XX",
        "X0XX0X",
        "X000X0",
        "00X000"
    };

    M = 4;	//fixed row size
    N = 6;	//fixed col size

	printChar (maze);
	cout << endl;

    if (sol(maze, 0,0) == true){
    	printInt(path);
    }
    else {
        cout << "Tom! You are smart!";
    }	
}