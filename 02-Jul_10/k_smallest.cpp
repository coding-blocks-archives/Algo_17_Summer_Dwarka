//Deepak Aggarwal, Coding Blocks
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// bool more(int x, int y){
// 	return x > y;
// }

class more{
public:
	bool operator()(int x, int y){
		return x > y;
	}
};


int main(){
	
	// priority_queue<int> q;				//default maxHeap

	//minHeap
	priority_queue<int, vector<int>, more> q;	
	//more is a COMPARATOR which is serves as basis for comparison
	//q is now a minHeap :)

	// q.push(1);
	// q.push(2);
	// cout << q.top() << " ";
	
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	random_shuffle(arr, arr + 8);

	for(int i = 0; i < 8; ++i)		 cout << arr[i] << " ";
	cout << endl;

	int k; cin >> k;

	for(int i = 0; i < k; ++i)	q.push(arr[i]);

	for(int i = k; i < 8; ++i){
		int maxEle = q.top();
		if (maxEle < arr[i]){
			q.pop();
			q.push(arr[i]);
		}
	}

	while(q.empty() == false){
		cout << q.top() << " ";
		q.pop();
	}

}