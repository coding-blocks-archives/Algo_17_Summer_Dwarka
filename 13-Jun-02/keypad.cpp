#include <iostream>
#include <string>
using namespace std;

const string table[] = {
	" ", "abc", "def",
	"ghi", "jkl", "mno",
	"pqrs", "tuv", "wxyz"
};

void possibleCodes(char num[], int be, char result[], int ridx){
	if (num[be] == '\0'){
		result[ridx] = '\0';
		cout << result << "\n";
		return;
	}


	int dig = num[be] - '0';
	string code = table[dig];
	for (int curCharat = 0; curCharat < code.size(); ++curCharat){
		result[ridx] = code[curCharat];
		possibleCodes(num, be + 1, result, ridx + 1);
	}
}





int main(){
	char inp[10];
	cin >> inp;

	char result[10];	//act as temp to store result
	//prints all possible codes corresponding to number inp starting from 0
	possibleCodes(inp, 0, result, 0);
	return 0;
}