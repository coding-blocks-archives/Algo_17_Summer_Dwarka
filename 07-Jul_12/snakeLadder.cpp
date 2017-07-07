#//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include "graph.h"
#include <iostream>
using namespace std;
int main(){

	int snakeLadder[50] = {};
	snakeLadder[2]	= 15;
	snakeLadder[5]	= 7;
	snakeLadder[9]	= 27;
	snakeLadder[17]	= 4;
	snakeLadder[18]	= 29;
	snakeLadder[24]	= 16;
	snakeLadder[25]	= 35;
	snakeLadder[32]	= 30;
	snakeLadder[34]	= 12;

	Graph G(36);
	for(int box = 1; box <= 36; ++box){
		for(int dice = 1; dice <= 6; ++dice){
			int destBox = box + dice;
			if (snakeLadder[destBox] != 0){
				destBox = snakeLadder[destBox];
			}
			if (destBox <= 36) G.addEdge(box,destBox, true);
		}
	} 

	vector<int> path = G.shortestDistance(1, 36);
	printContainer(path.begin(), path.end());

}