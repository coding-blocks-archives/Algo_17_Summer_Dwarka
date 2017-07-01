//Deepak Aggarwal, Coding Blocks
#include "mytree.h"
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int height(Node *root) {
	if (root == NULL)	return 0;

	int l_ht = height(root->left);
	int r_ht = height(root->right);
	int c_ht = max(l_ht, r_ht) + 1;
	return c_ht;
}

int diameter(Node * root) {
	if (root == NULL) {
		return 0;
	}

	int l_diameter = diameter(root->left);
	int r_diameter = diameter(root->right);
	int root_diameter = height(root->left) + height(root->right) + 1;
	int c_diameter = max(root_diameter, max(l_diameter, r_diameter));
	return c_diameter;

}

class Pair {
public:
	int diameter;
	int height;
	Pair(int x, int y) {
		height = x;
		diameter = y;
	}
};


Pair diameter_opt(Node * root) {
	if (root == 0) {
		Pair p(0, 0);
		return p;
	}

	Pair left = diameter_opt(root->left);
	Pair right = diameter_opt(root->right);
	Pair cur(0, 0);

	cur.height = max(left.height, right.height) + 1;
	int tmp_dia = left.height + right.height + 1;
	cur.diameter = max(tmp_dia, max(left.diameter, right.diameter));

	return cur;
}


void mirror (Node * root) {
	if (root == NULL) {
		return ;
	}

	// swap(root->left, root->right);

	//swapping root->left and root->right
	Node * tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	mirror(root->left);
	mirror(root->right);
}

// pair<int, int> is equ pair<inc, exc>
typedef pair<int, int> pii;

pair<int, int> maxSum(Node* root) {
	if (root == NULL) {
		pii tmp(0, 0);
		return tmp;
	}

	pii lf = maxSum(root->left);
	pii rt = maxSum(root->right);
	pii cur;

	cur.first = root->data + lf.second + rt.second; //inc root node
	//cur.inc = root->data + lf.exc + rt.exc

	cur.second = max(lf.first, lf.second) +  max(rt.first, rt.second);
	return cur;
}

void printVec(const vector<Node*>& v){
	for(int i = 0; i < v.size(); ++i){
		cout << v[i]->data << " ";
	}
	cout << endl;
}


void printPaths(Node* root, vector<Node *>& path){
	if (root == NULL){
		return;
	}

	if (root->left == NULL && root->right == NULL){
		//add leaf to path
		path.push_back(root);
		printVec(path);
		path.pop_back();
		return;
	}

	path.push_back(root);
	printPaths(root->left, path);
	printPaths(root->right, path);
	path.pop_back();
}


int main() {
	Node * root = takeInputLevel();

	// int ht = height(root);
	// cout << ht;

	// int d = diameter(root);
	// cout << d << " ";

	// Pair D = diameter_opt(root);
	// cout << D.height << " " <<  D.diameter << endl;

	// mirror(root);
	// printLevel(root);

	// pii ans = maxSum(root);
	// cout << "Including " << root->data << " " << ans.first << endl;
	// cout << "Excluding " << root->data << " " << ans.second << endl;

	vector<Node*> tmp;
	printPaths(root, tmp);

}