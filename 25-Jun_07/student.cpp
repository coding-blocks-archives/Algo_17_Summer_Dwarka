//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;

class Student{
	int roll;
	int grade;
public:
	Student(int r, int g){
		roll = r;
		grade = g;
	}

	void plusGrade(int x){
		grade += x;
	}

	// Student plus(Student S){		//COPY by value
	// void operator+(Student S){	//A + B + C won't work
	Student& operator+(Student S){
		// grade += S.grade;
		//this is a POINTER which refers to the calling object
		this->grade += S.grade;
		return *this;	//Student should be returned and not its address
	}

	void print(){}	//function with empty definition
	// void operator<<(ostream& obj){

	//friend function is NOT a member method of CLASS Student
	friend ostream& operator<<(ostream& obj, Student S){
		//ostream& for cout << A << B where A, B are students
		obj << S.roll << " " << S.grade << endl;
		return obj;
	}
	
};


int main(){
	Student A(1, 8);
	Student B(2, 6);
	Student C(3, 5);
	
	// cout << A << B;;
	// A << cout;

	B.print();
	C.print();
	

	// A.plusGrade(2);
	// cout << "After calling plusGrade ";
	// A.print();


	// A + B + C;			// A.plus(B);
	// cout << "After calling plusStudent ";
	// A.print();
	// B.print();
	// C.print();


	
}