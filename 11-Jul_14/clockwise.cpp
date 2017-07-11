//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
using namespace std;

enum choice {input, display};	
//choice is a TYPE which can hold values input and display ONLY
//Note input and display are VALUES and not identifiers (contextually)

int mat[10][10];

void io(int mat[][10], int N, choice ch) {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (ch == input) cin >> mat[r][c];
			else if (ch == display) cout << mat[r][c] << " ";
		}
		if (ch == display) cout << endl;
	}
}


void rotate(int mat[][10], int N) {
	for (int x = 0; x < N / 2; ++x) {	//represent cycles
		for (int y = x; y < N - x - 1; ++y) {	//represent elements
			int tmp = mat[x][y];
			mat[x][y] = mat[N - y - 1][x];
			swap(mat[y][N - x - 1], tmp);
			swap(mat[N - x - 1][N - y - 1], tmp);
			swap(mat[N - y - 1][x], tmp);
		}
	}
}

int main() {
	int N;
	cout << "Enter dim of Mat\n";
	cin >> N;

	io(mat, N, input);
	rotate(mat, N);
	io(mat, N, display);
}
