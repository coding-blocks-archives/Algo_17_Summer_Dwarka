//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string largestString(const vector<string>& vs){
	int maxLength = 0;
	string largest = "";

	//for (vector<string>::iterator it = vs.begin(); it != vs.end(); ++it)
	// if current string greater than GreatestSoFar
	//if (*it).length or it->length()

	for(int i = 0; i < vs.size(); ++i){
		//vs[i] is a string and we get the length of THAT string using vs[i].length()
		if(vs[i].length() > maxLength){
			largest = vs[i];
			maxLength = vs[i].length();
		}
	}

	return largest;
}


int main(){
	vector<string> vs;
	int n;	cin >> n;
	cin.ignore();

	for(int i = 0; i < n; ++i){
		string s;
		// cin >> s;
		// cin.getline(s, 100);
		getline(cin, s);
		vs.push_back(s);
	}

	string largest = largestString(vs);
	cout << largest << " " << largest.size();
 }