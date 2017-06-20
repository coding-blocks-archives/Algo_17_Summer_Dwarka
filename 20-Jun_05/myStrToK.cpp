//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <cstring>
using namespace std;

char* mystrtok(char* str, char delimiter){
	static char *token_start;
	//when the first call is made
	if (str != NULL){
		token_start = str;
	}

	//I dont have more tokens to find
	if (token_start == NULL){
		return NULL;
	}

	//dynamic since output has to be returned	
	char * output = new char[strlen(token_start) + 1];

	int i;
	for(i = 0; token_start[i] != '\0'; ++i){
		//the current char is not delimiter
		if (token_start[i] != delimiter){
			output[i] = token_start[i];
		}
		//oops! I have found the delimiter
		//time to return the token
		else{
			output[i] = '\0';
			token_start = token_start + i + 1;
			return output;
		}
	}

	//I have reached the end of string
	output[i] = '\0';
	token_start = NULL;
	return output;
}

int main(){
	char str[] = "Hey, Coding Blocks is Fun";

	char* token = mystrtok(str, ' ');
	// cout << str << endl;
	// cout << token << endl;

	while(token){
		cout << token << endl;
		token = mystrtok(NULL, ' ');
	}
	
}