#include <vector>
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void printContainer(T be, T en) {
	//be and en are pointers-like(iterators) object
	while (be != en) {
		cout << *be << " ";
		++be;
	}
	cout << endl;
}


class Graph {
	typedef vector<int> vi;		//vi is another name for type vector<int>
	int nV;
	int nE;
	vector<int>* adjList;
public:

	Graph(int n) {
		nV = n;
		nE = 0;
		adjList = new vi[nV + 1];		//dynamic memeory allocation
		//To "address" n vertices I need nV + 1 space--index adjusting
	}

	~Graph() {
		delete [] adjList;
	}

	void addEdge(int x, int y, bool directional = false) {
		adjList[x].push_back(y);
		++nE;

		if (directional) return;

		adjList[y].push_back(x);
		++nE;
	}

	void dfs_helper(int src, bool visited[]) {
		visited[src] = true;
		cout << src << " ";

		// for(int i = 1; i <= nV; ++i){
		//for every vertex if it has NOT been visited visit it

		//for every neighbour which has NOT been visited
		//neighbours of src are stored into adjList[src]
		for (int i = 0; i < adjList[src].size(); ++i) {
			int neighbor = adjList[src][i];

			if (visited[neighbor] == false) {
				dfs_helper(neighbor, visited);
			}
		}
	}

	void dfs(int src) {
		bool* visited = new bool[nV + 1]();		//arr={}
		dfs_helper(src, visited);
		delete [] visited;
	}

	void printConnected() {
		//return "something"
		//return all connected componenets
		//write printConnected outside the class
		//is it possible to write it IFF dfs_helper is private

		bool* visited = new bool[nV + 1]();

		for (int src = 1; src <= nV; ++src) {
			if (visited[src] == false) {
				dfs_helper(src, visited);
				cout << endl;
			}
		}

		delete [] visited;
	}

	void bfs(int src) {
		bool* visited = new bool[nV + 1];
		queue<int> q;	//q contains the vertices that HAS been visited

		visited[src] = true;
		q.push(src);

		while (q.empty() == false) {
			int curVex = q.front();
			q.pop();

			cout << curVex << " ";

			//push all unvisited neighbours
			for (int i = 0; i < adjList[curVex].size(); ++i) {
				int neighbor = adjList[curVex][i];
				if (visited[neighbor] == false) {
					visited[neighbor] = true;
					q.push(neighbor);
				}
			}
		}
		delete [] visited;
	}


	vector<int> shortestDistance(int src, int dest) {
		int* dist = new int[nV + 1]();
		bool* visited = new bool[nV + 1]();
		int* parent = new int[nV + 1];
		//dist[i] == 0 ==>vertex has not been visited
		queue<int> q;

		dist[src] = 0;
		parent[src] = src;		//redundant
		visited[src] = true;
		q.push(src);

		while (q.empty() == false) {
			int curVex = q.front();
			q.pop();

			//set distance of neighors
			for (int i = 0; i < adjList[curVex].size(); ++i) {
				int neighbor = adjList[curVex][i];
				if (visited[neighbor] == false) {
					parent[neighbor] = curVex;
					q.push(neighbor);
					visited[neighbor] = true;
					dist[neighbor] = dist[curVex] + 1;
				}
			}
		}

		// int ans = dist[dest];
		vector<int> ans;
		int i = dest;
		ans.push_back(i);
		while (src != i) {
			ans.push_back(parent[i]);
			i = parent[i];
		}

		delete [] parent;
		delete [] dist;
		delete [] visited;
		return ans;
	}

	vector<int> topologicalSort() {
		//calculate inDegree
		int* inDegree = new int[nV + 1]();	//initialliy set to 0
		for (int ver = 1; ver <= nV; ++ver) {
			//for every neighbour increment the indegree by 1
			for (int i = 0; i < adjList[ver].size(); ++i) {
				int neighbor = adjList[ver][i];
				++inDegree[neighbor];
			}
		}

		queue<int> q;
		//search for potential candidates
		for (int i = 1; i <= nV; ++i) {
			if (inDegree[i] == 0) {
				q.push(i);
			}
		}

		vector<int> ans;
		while (q.empty() == false) {
			//YIPPIE!!! The current requirement has met
			// pop the current requirement...
			int curReq = q.front();
			q.pop();
			ans.push_back(curReq);

			//reduce the requirements for dependant by 1
			for (int i = 0; i < adjList[curReq].size(); ++i) {
				int neighbor = adjList[curReq][i];
				--inDegree[neighbor];
				//check if neigbhour is NOW a potential candidate
				if (inDegree[neighbor] == 0) {
					q.push(neighbor);
				}
			}
		}
		delete [] inDegree;
		return ans;
	}
};