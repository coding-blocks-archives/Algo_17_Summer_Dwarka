#include <vector>
#include <iostream>
using namespace std;

class Graph{
	typedef vector<int> vi;	//vi is another name for type vector<int>
	int nV;
	int nE;
	vector<int>* adjList;
public:

	Graph(int n){
		nV = n;
		nE = 0;
		adjList = new vi[nV + 1];		//dynamic memeory allocation
	}

	void addEdge(int x, int y, bool directional = false){
		adjList[x].push_back(y);
		++nE;

		if(directional) return;

		adjList[y].push_back(x);
		++nE;
	}

	void dfs_helper(int src, bool visited[]){
		visited[src] = true;
		cout << src << " ";

		// for(int i = 1; i <= nV; ++i){
		//for every vertex if it has NOT been visited visit it
		
		for(int i = 0; i < adjList[src].size(); ++i){
			int neighbor = adjList[src][i];

			if (visited[neighbor] == false){
				dfs_helper(neighbor, visited);
			}
		}
	}

	void dfs(int src){
		bool* visited = new bool[nV]();		//arr={}
		dfs_helper(src, visited);
	}
};