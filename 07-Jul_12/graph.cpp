#include <list>
#include <queue>
#include <iostream>
using namespace std;
class Graph{
	int nV;
	int nE;
	list<int>* adjList;

public:
	Graph(int n){
		nV = n;
		nE = 0;
		adjList = new list<int>[nV];
	}

	void addEdge(int v1, int v2, bool directional = false){
		adjList[v1].push_back(v2);
		++nE;

		if (directional){
			return;
		}

		adjList[v2].push_back(v1);
		++nE;
	}

	void dfs_helper(int v, bool visited[]){
		visited[v] = true;
		cout << v << " ";

		for(list<int>::iterator it = adjList[i].begin(); it != adjList[v].end(); ++it ){
			if (visited[*it] == false) dfs(*it, visited);
		}
	}

	void dfs(int n){
		bool* visited = new bool[nV]();
		dfs_helper(n, visited);
	}

	void bfs(int v){
		bool* visited = new visited[nV];
		queue<int> q;	//list of visited nodes
		q.push_back(v);
		visited[v] = true;

		while(q.empty() == 0){
			int top = q.front();

			cout << top << " ";

			for(auto it = adjList[top].begin(); it != adjList[top].end(); ++it){
				if (visited[*it]) continue;
				q.push(*it);
				visited[*it] = true;
			}
		}
	}

	int shortestPath(int src, int dest){
		int* dist = new int[nV];

		queue<int> q;
		bool* visited = new bool[nV]();	
		q.push(src);
		visited[src] = true;
		dist[src] = 0;
		parent[];

		parent[src] = 0;

		while(q.empty() == 0){
			int v = q.front();
			q.pop();

			for(auto it = begin(); it != end(); ++it){
				if (visited[*it] == false){
					parent[*it] = v;
					dist[*it] = dist[v] + 1;
					visited[*it] = true;
					q.push(*it);
				}
			}
		}

		int i = dest;
		while(parent[i] != src){
			print i;
			i = parent[i];

		}

		print(dist);
	}

	void topologicalSort(){
		//calculate indegree
		int indegree[nV];

		for(int v = 0; v < nV; ++i){
			for(every neighbour){
				indegree[neighbour] ++;
			}
		}

		//scan for 0 indegree
		int v;
		v.push(v);
		visited[v] = ture;

		while(q.empty){
			int cur = pop();
			v.push(cur);

			//reduce indegree
			for(every neighbout){
				reduce 
				if (degree == 0) 	next potential vertex
			}
		}
		//push those nodes with indegree 0 until everything has been visited

	}

	//save into array the edges
	for(every box){
		for(every throw there exists an edge of throw length)
			if (throw reaches a sanke/ladder edge does not exits)
	}

	dijikstra(int src, int dest){
		// start from src
		//dist of curVer from src = inf

		dist[src] = 0;
		minHeap;
		minHeap.push src;

		//pus

		while(there are vertex){
			pop();
			//push all connected nodes
			
			if (wt to reach cur node is > already dist) continue;	//visited

			// insert all nodes connected to cur vertex with updated distance

			set dist = dist[cur] + cur
		}

	}


};