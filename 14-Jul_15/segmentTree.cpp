//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
using namespace std;
const int N = 1000;

int arr[N] = {1, 2, 3, 4 , 5};
int tree[3 * N];

int left(int i) { return i << 1; }
int right(int i) { return (i << 1) + 1;}



void build(int root, int be, int en) {
	if (be > en) {
		return;
	}

	if (be == en) {
		tree[root] = arr[be];
		return;
	}

	int mid = (en + be) / 2;

	build(left(root), be, mid);
	build(right(root), mid + 1, en);

	tree[root] = min(tree[left(root)], tree[right(root)]);
}

int search(int root, int be, int en, int i, int j) {
	if (j < be || i > en) {
		return INT_MAX;
	}

	if (i <= be && en <= j) {
		return tree[root];
	}

	int mid = (be + en) / 2;

	if (i <= mid && j <= mid) {
		return search(left(root), be, mid, i, j);
	}
	else if (i > mid && j > mid) {
		return search(right(root), mid + 1, en, i, j);
	}

	int leftAns = search(left(root), be, mid, i, j);
	int rightAns = search(right(root), mid + 1, en, i , j);

	return min(leftAns, rightAns);
}


void update(int root, int be, int en, int idx, int val) {
	if (be > en) {
		return;
	}

	if (be == idx && en == idx) {
		tree[root] = val;
		return;
	}

	int mid = (be + en) / 2;

	if (idx <= mid)	update(left(root), be, mid, idx, val);
	
	else update(right(root), mid + 1, en, idx, val);

	tree[root] = min(tree[left(root)], tree[right(root)]);

}

int main() {
	build(1, 0, 4);

	update(1, 0, 4, 2, -100);

	cout << search(1, 0, 4, 1, 4) << endl;
	cout << search(1, 0, 4, 0, 0);

	// cout << search(1, 0, 4, 1,4);


	// for(int i = 1; i < 2 * 5; ++i){
	// 	cout << tree[i] << " ";
	// }

}