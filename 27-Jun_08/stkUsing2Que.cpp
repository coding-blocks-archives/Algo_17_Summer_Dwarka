//Deepak Aggarwal, Coding Blocks
#include <iostream>
#include <queue>
using namespace std;
queue<int> q1;
queue<int> q2;

void myPush(int x){
	//push into empty queue
	//POP all elements FROM empty queue and push them into another queue

	if(q1.empty()){
		q1.push(x);
		//moving elements from q2 to q1
		while(q2.empty() == false){
			int curEle = q2.front();
			q2.pop();
			q1.push(curEle);
		}
	}
	else {
		q2.push(x);
		//moving elements from q1 to q2
		while(!q1.empty()){
			int curEle = q1.front();
			q1.pop();
			q2.push(curEle);
		}
	}
	//Complexity of Push operation is O(N)
	//HW : Make pop costly instead of myPush
}


int myPop(){
	//simply pop the element
	//Wait!!! I cant do that...need to check if the container contains data
	if (!q1.empty()){
		int ele = q1.front();
		q1.pop();
		return ele;
	}
	else if (q2.empty() == false){
		int ele = q2.fron();
		q2.pop();
		return ele;
	}
	else return -1;
}

int main(){
	int oper, x;
	while(true){
		cin >> oper;	//which OPERation to perform
		if (oper == 3) return 0;
		else if (oper == 1){
			//push
			cin >> x;
			myPush(x);
		}
		else if (oper == 2){
			//pop
			int ele = myPop();
			cout << ele << endl;
		}
	}
}