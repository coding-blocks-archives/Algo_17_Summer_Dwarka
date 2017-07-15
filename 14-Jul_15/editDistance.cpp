//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
using namespace std;


int editDistance(char s1[], int n1, char s2[], int n2) {
	//n1 and n2 are the last indices
	if (n1 < 0) {
		return n2 + 1;
	}

	if (n2 < 0) {
		return n1 + 1;
	}

	if (s2[n2] == s1[n1]) {
		return editDistance(s1, n1 - 1, s2, n2 - 1);
	}

	return 1 + min(
	           editDistance(s1, n1 - 1, s2, n2),	//insert
	           min(editDistance(s1, n1, s2, n2 - 1), 	//deletion
	               editDistance(s1, n1 - 1, s2, n2 - 1)	//replace
	              )
	       );
}




int main() {
	int ans = editDistance("saturday", 7, "sunday", 5);
	cout << ans;
}