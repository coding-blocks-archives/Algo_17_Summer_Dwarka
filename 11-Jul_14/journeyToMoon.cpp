//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <list>
using namespace std;

class Graph {
public:
	int nV;
	list<int>* adjList;
	typedef list<int>::iterator lit;

	Graph(int N) {
		nV = N;
		adjList = new list<int>[nV];
	}

	~Graph() {
		delete [] adjList;
	}

	void addEdge(int src, int dest) {
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}

	void dfs(int src, bool visited[], int &cnt) {
		//find a connceted component
		visited[src] = true;
		++cnt;

		for (lit neigbor = adjList[src].begin(); neigbor != adjList[src].end(); ++neigbor) {
			if (visited[*neigbor] == false) {
				dfs(*neigbor, visited, cnt);
			}
		}
	}
};

long long int findNum(int arr[], int sze, long long int N) {
	long long int totalComb = N * (N - 1) / 2;

	for (int i = 0; i < sze; ++i) {
		// cout << arr[i] << " ";
		totalComb -= arr[i] * (arr[i] - 1) / 2;
	}
	// cout << endl;
	return totalComb;
}


int main() {
	int N;
	int x, y;	//tracks edge;
	int P;

	cin >> N >> P;
	Graph g(N);

	for (int i = 0; i < P; ++i) {
		cin >> x >> y;
		g.addEdge(x, y);
	}

	//find connected components, store their count and
	// no of connected components in each cell
	int numOfCC = 0;
	int cntofCC[(int)1e5] = {};
	bool* visited = new bool[N]();

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			g.dfs(i, visited, cntofCC[numOfCC]);
			++numOfCC;
		}
	}

	delete [] visited;

	//all set just compute the answer from numOfCC and cntOfCC
	long long int ans = findNum(cntofCC, numOfCC, N);
	cout << ans;

}