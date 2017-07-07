//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include "graph.h"
#include <iostream>
using namespace std;
int main(){
	//Lets go Mauritius
	//P T I V E G
	//6 4 3 5 1 2

	Graph G(6);
	G.addEdge(6, 4, true);	//Passport->Ticket
	G.addEdge(6, 3, true); 	//Passport->Insurance
	G.addEdge(4, 5, true);	//Ticket->Visa
	G.addEdge(3, 5, true);	//Insurance->Visa
	G.addEdge(5, 2, true);	//Visa->Gifts
	G.addEdge(5, 1, true);	//Visa->Forex

	vector<int> topo_res = G.topologicalSort();
	printContainer(topo_res.begin(), topo_res.end());
}