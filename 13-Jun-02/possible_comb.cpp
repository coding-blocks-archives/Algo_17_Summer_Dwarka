#include <iostream>
using namespace std;

char result[20];

void printCombinations(char str[], int be, int ridx){
	if (str[be] == '\0'){
		result[ridx] = '\0';
		cout << result << endl;
		return;
	}

	int dig = str[be] - '0';
	char c = 'A' + dig - 1;		//c is the equivalent English character to digit
	result[ridx] = c;
	printCombinations(str, be + 1, ridx + 1);

	if (str[be + 1] == '\0') return;

	int nextDig = str[be + 1] - '0';
	int num = 10 * dig + nextDig;
	if (num > 26) return;
	char new_c = 'A' + num - 1;
	result[ridx] = new_c;
	printCombinations(str, be + 2, ridx + 1);

}



int main(){
	char inp[20];
	cin >> inp;

	//prints all the possible combination of inp starting from i
	printCombinations(inp, 0, 0);
}