//Deepak Aggarwal, Coding Blocks
#include "heap_template.h"
#include <iostream>
#include <string>
using namespace std;

class Book{
public:
	int isdn;
	string author;
	Book(){};
	Book(int id, string name){
		isdn = id;
		author = name;
	}

	//tell the computer how to compare books
	//resolved like B1.operator<(B2) or B1 < B2
	bool operator<(const Book& B){
		return author.size() < B.author.size();
	}
};

/*class comparator{
public:
	bool operator()(const Book& B1, const Book& B2){
		return B1.author.size() < B2.author.size();
	}
};*/


int main(){
	heap<Book, comparator> hb;
	Book B1(1, "Robin");
	Book B2(2, "Dale");

	hb.push(B1);
	hb.push(B2);

	cout << hb.top().author;
}