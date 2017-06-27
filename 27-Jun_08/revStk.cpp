//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int x){
	if (s.empty()){
		s.push(x);
		return;
	}
	int cur = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(cur);
}


void reverseStk(stack<int>& s){
	if (s.empty() == true){
		//nothing to do 
		return;
	}

	int cur = s.top();
	s.pop();
	reverseStk(s);	//stack of 1 element less than "N" will be reversed
	//HOW??? Recursion is the ans, Man!
	insertAtBottom(s, cur);
}


int main(){
	stack<int> s;
	for(int i = 0; i < 5; ++i){
		int x; cin >> x;
		s.push(x);
	}

	reverseStk(s);

	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();

	}

}