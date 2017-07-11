//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;
const int D = 10;

void input(int arr[][D], int k, int N) {
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}
}


void display(int arr[], int N) {
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

class vertex {
public:
	int num, k, i;
	vertex(int n, int _k, int _i) {
		num = n;
		k = _k;
		i = _i;
	}
	bool operator<(const vertex& V) const {
		return num > V.num;		//minHeap
	}
};

void mergeK(int res[], int arr[][D], int k, int N) {

	priority_queue<vertex> q;
	//push first k elements
	for (int i = 0; i < k; ++i) {
		q.push(vertex(arr[i][0], i, 0));
	}

	for (int i = 0; i < k * N; ++i) {
		vertex v = q.top();
		q.pop();
		res[i] = v.num;
		if (v.i + 1 < N) {
			//next element exists
			q.push(vertex(arr[v.k][v.i + 1], v.k, v.i + 1));
		}
	}
}


int main() {
	int a[D][D];	//Try to allocate it dynamically
	int k, N;
	cout << "Enter k N\n";
	cin >> k >> N;

	input(a, k, N);

	int *res = new int[k * N];
	mergeK(res, a, k, N);
	display(res, k * N);
	delete [] res;
}