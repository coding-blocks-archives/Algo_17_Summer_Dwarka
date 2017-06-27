//Deepak Aggarwal, Coding Blocks
#include <stack>
#include <iostream>
using namespace std;

int redundPara(const string& str){
	int i = 0;
	int cnt = 0;

	stack<char> s;

	while(i < str.size()){
		char cur = str[i];
		//a closed bracket is encountered, search for the opening one
		if (cur == ')'){
			bool isRedundant = true;
			
			while(s.empty() == false){
				if(s.top() != '('){
					//I have found an operator
					isRedundant = false;
					s.pop();
				}
				else {
					s.pop();
					break;
				}
			}

			if (isRedundant == true) ++cnt;
		}

		else switch(cur){	//Hack!!!
			case '+':
			case '-':
			case '/':
			case '*':
			case '(': s.push(cur);
		}
		++i;
	}
	return cnt;
}



int main(){
	string s;
	cin >> s;
	int cnt = redundPara(s);
	cout << cnt << " ";		
}