//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <numeric>
using namespace std;

bool canPossible(int pages[], int students, int atmostPages, int n){
	int nStudents = 1;
	int maxPages = 0;
	//maxPages stores the number of pages that CAN be alloted to student
	//Remember!!! the maxPages CANNOT exceed atmostPages

	for (int i = 0; i < n; ++i){
		//the book contain more pages than atMostPages
		if (pages[i] > atmostPages){
			return false;
		}

		else if (pages[i] + maxPages <= atmostPages){
			//Great! allocate ith book to current student
			maxPages += pages[i];
		}
		else {
			//can't allocate ith book to current student; so choose another student
			maxPages = pages[i];
			++nStudents;
			//Need more students than available, if atMostPages is the answer..not possible
			if (nStudents > students){
				return false;
			}
		}
	}
	return true;
}



int minPages(int pages[], int n, int students){
	int maxPages = accumulate(pages, pages + n, 0);	//sum of pages 
	int low = 0;
	int high = maxPages;
	//single student will be given all pages to read...poor chap!
	//the answer, that is, the minimum no of possible pages that shall be given to each
	//student, will definitely lie between [low, high]

	while(low <= high){
		int mid = (low + high) / 2;
		//can mid be the required answer
		if (canPossible(pages, students, mid, n)){
			//Oh yes! it is..lets choose the minimum of cur or the bestSoFar
			maxPages = min(maxPages, mid);
			
			//lets try the next possible solution
			high = mid - 1; 
		}
		else {
			low = mid + 1;
		}
	}

	return maxPages;
}



int main(){
	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr) / sizeof(int);

	int students;
	cin >> students;

	int ans = minPages(arr, n, students);
	cout << ans;
}