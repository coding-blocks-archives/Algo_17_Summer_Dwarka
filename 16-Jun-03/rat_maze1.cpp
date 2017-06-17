#include <iostream>
int M, N;
using namespace std;
int path[10][10];   //saves the path

//prints 2D char array
void printChar(char board[][10]){
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j) cout << board[i][j] << " ";
            cout << endl;
    }
}

//prints 2D int array
void printInt(int board[][10]){
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j) cout << board[i][j] << " ";
            cout << endl;
    }
}

//sol finds one of the possible paths and sets the path[][] 2D array 
//with that path
bool sol(char board[][10], int x, int y){
    //if I am goal
    if (x == M - 1 && y == N - 1){
        path[x][y] = 1;
        return true;
    }

    //Oops! I have reached a bomb following the path I am currently following
    if (board[x][y] == 'X') return false;

    //Lets "say" the x,y box CAN be a part of the solution
    path[x][y] = 1;

    //If I am inside the matrix, I ll move in forward
    if (y < N){
        if (sol(board, x, y + 1) == true){
            return true;
        }
    }

    //If I am inside the matrix, I ll move downwards
    if (x < M){
        if (sol(board, x + 1, y) == true){
            return true;
        }
    }

    //Oops! I can't find a way moving in forward AND downward direction
    //x,y cell CANNOT form part of the path
    path[x][y] = 0;     //restoring the previous state of the path[][]

    return false;
}


int main(){
	char maze[][10] = {
		"0000XX",
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