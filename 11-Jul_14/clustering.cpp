//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;
int M, N;
char mat[10][10];

enum choice {input, display};
template<typename T>
void io(T mat[][10], int M, int N, choice ch) {
	for (int r = 0; r < M; ++r) {
		for (int c = 0; c < N; ++c) {
			if (ch == input) cin >> mat[r][c];
			else if (ch == display) cout << mat[r][c] << " ";
		}
		if (ch == display) cout << endl;
	}
}


void dfs(int x, int y, char mat[][10], bool visited[][10]) {
	visited[x][y] = true;

	//directions
	static const int row[] = { -1, -1, -1, 0, 1, 1, 1, 0};
	static const int col[] = { -1, 0, 1, 1, 1, 0, -1, -1};

	//implicit graph
	//we deduced the adjacent edges
	for (int i = 0; i < 8; ++i) {
		int curRow = x + row[i];
		int curCol = y + col[i];
		if (curRow < M && curCol < N && curRow >=0 && curCol >= 0){
			if (!visited[curRow][curCol] && mat[curRow][curCol] == '.'){
				dfs(curRow, curCol, mat, visited);
			}
		}
	}
}


int clustering(char mat[][10]) {
	bool visited[10][10] = {};
	int numOfCC = 0;


	for (int r = 0; r < M; ++r) {
		for (int c = 0; c < N; ++c) {
			if (visited[r][c] == false && mat[r][c] != '#') {
				++numOfCC;
				dfs(r, c, mat, visited);
			}
		}
	}
	io(visited, M, N, display);

	return numOfCC;
}




int main() {

	cin >> M >> N;
	io(mat, M, N, input);

	int k = clustering(mat);


	cout << k;
}