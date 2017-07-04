//Deepak Aggarwal, Coding Blocks
#include <map>
#include <iostream>
#include "mytree.h"
using namespace std;

typedef  map<int, vector<int> > miv;

void setMap(Node *root, int hd, miv& m){
	if (root == NULL){
		return;
	}

	m[hd].push_back(root->data);

	setMap(root->left, hd - 1, m);	//left tree horizontal distance is 1 less than the parent
	setMap(root->right, hd + 1, m);
}


int main(){

	map<int, vector<int> > m;
	int hd = 0;

	setMap(root, hd, m);

	//printing all data corresponding to all keys:)
	//auto : automatically DEDUCES type from the value right to "equal to" operator--C++11 feature
	for(auto it = m.begin(); it != m.end(); ++it){
		auto & p = *it;		//auto == pair<const int, vector<int> >; Note space between ...<int> > 
		for(int i = 0; i < p.second.size(); ++i){
			cout << p.second[i] << " ";
		}
		cout << endl;
	}

}