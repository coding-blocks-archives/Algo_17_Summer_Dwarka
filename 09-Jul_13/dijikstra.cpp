//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Vertex{
public:
	int id;
	int wt;
	Vertex(int i, int w){
		id = i;
		wt = w;
	}

	bool operator<(const Vertex& X) const {
		return wt < X.wt;
	}
};

class comparator{
public:
	bool operator()(Vertex& A, Vertex& B){
		return A.wt < B.wt;
	}
};

class Graph{
	list<Vertex>* adjList;
	int nV;
	int nE;
public:
	Graph(int n){
		nV = n;
		adjList = new list<Vertex>[nV + 1]();
		nE = 0;
	}


	void addEdge(int src, int dest, int wt){
		adjList[src].push_back(Vertex(dest, wt));
		++nE;

		adjList[dest].push_back(Vertex(src, wt));
		++nE;
	}

	int dijikstra(int src, int dest){
		int * dist = new int[nV + 1];
		const int inf = 10000;

		//initially all set to inf
		for(int i = 0; i <= nV; ++i){
			dist[i] = inf;
		}

		// priority_queue<Vertex, vector<Vertex> , comparator> q;
		priority_queue<Vertex> q;

		Vertex V(src, 0);

		q.push(V);

		while(q.empty() == false){
			Vertex curVer = q.top();
			q.pop();
			
			dist[curVer.id] = min(curVer.wt, dist[curVer.id]);

			//push all neighbours
			for(list<Vertex>::iterator it = adjList[curVer.id].begin(); it != adjList[curVer.id].end(); ++it){
				Vertex neighbor = *it;
				int distFromSrc = neighbor.wt + curVer.wt;
				if (distFromSrc < dist[neighbor.id]) {
					Vertex X(neighbor.id, distFromSrc);
					q.push(X);
				}
			}
		}

		int ans = dist[dest];
		delete [] dist;
		return ans;
	}

	~Graph(){
		delete [] adjList;
	}
};


int main(){
	Graph G(7);

	G.addEdge(1, 2, 10);
	G.addEdge(1, 3, 80);
	G.addEdge(2, 5, 20);
	G.addEdge(2, 3, 6);
	G.addEdge(5, 7, 10);
	G.addEdge(5, 6, 50);
	G.addEdge(7, 6, 5);
	G.addEdge(3, 4, 70);


	cout << G.dijikstra(1, 7);
}