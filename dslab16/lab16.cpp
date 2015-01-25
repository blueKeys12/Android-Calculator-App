#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
	int id() const { return sid; }
	void setId(int s) { sid = s; }				//your code must never call this method
	void print() const { cout << sid << '(' << name << '), '; }
	void setName(const string &n) { name = n; }   //your code must never call this method
	string getName() const { return name; }
private:
	int sid;
	string name;
	char otherData[10000];
	
};

bool sortID(const Student &left, const Student &right){
	
	if (left.id() < right.id()) return true;
	return false;
}//My predicate function for sorting sarray


bool sortPtr(const Student * left, const Student * right){
	if (left->id() < right->id()) return true;
	return false;
}//my predicate function for psarray 

bool sortName(const Student * left, const Student *right){
	if (left->getName() > right->getName())return true;
	return false;
}//my predicate for z to a name pointer sorting

void main() {
	const int backup[10] = { 2, 5, 0, 9, 7, 4, 3, 1, 8, 6 };//constant array with data to sort
	const string names[10] = { "CJ", "F", "A", "JJ", "HZ", "E", "DD", "B", "IM", "G" };
	int n = 10;

	vector<int> vec;
	/*TODO: use an insert out of the vector class to get the integers from backup copied into vec
	should be done in 1 specific insert call, but make a loop if you have to*/

	vec.insert(vec.begin(), &backup[0], &backup[10]);
	cout << "\tunsorted vec print: ";
	for (int i = 0; i<10; i++) cout << vec[i] << ", ";

	/*TODO sort the vector using STL's sort */
	sort(vec.begin(), vec.end());
	cout << "\n\tsorted vec print: ";
	for (int i = 0; i<10; i++) cout << vec[i] << ", ";
	cout << endl << endl;

	Student sarray[10];
	for (int i = 0; i<10; i++) {
		sarray[i].setId(backup[i]);//initialize Student's ids from backup
		sarray[i].setName(names[i]);
	}

	cout << "Unsort Studs ";
	for (int i = 0; i<10; i++) sarray[i].print();

	//TODO: sort sarray using STL's sort, hint: you will need a predicate function
	sort(sarray, sarray+10, sortID);
	///sort(sarray[0], sarray[10], sortID;) THIS DOES NOT WORK. 

	cout << "\nSort Studs ";
	for (int i = 0; i<10; i++) sarray[i].print();
	cout << endl << endl;


	for (int i = 0; i<10; i++) sarray[i].setId(backup[i]);//reset Student's ids from backup

	/*We discussed in class that sorting students directly could be expensive if they were big.
	(Due to the time it takes to swap large data structs). The solution is to pointers instead.

	TODO: Declare an array of pointers to Students, name it psarray.
	initialize the elements so that they point to the contents of sarray*/
	Student * psarray[10];
	for (int i = 0; i < 10; i++){
		psarray[i] = &sarray[i];
	}

	//TODO: use STL to sort the students pointed at by psarray, hint: you need a new predicate
	sort(&psarray[0], &psarray[10], sortPtr);



	
	  //This will print the students from psarray after you have correctly set it up.
	cout <<"sort pointer: ";
	for (int i=0; i<10; i++) psarray[i]->print();
	cout <<endl<<endl;
	

	//TODO:  now figure out how to sort sarray based on the results of sorting psarray
	//notice this is printing sarray, so after sorting psarray, you need to use that info to sort sarray in O(N) time

	for (int i = 0; i < 10; i++){
		sarray[i] = *psarray[i];
	}
	cout << "sort Studs: ";
	for (int i = 0; i < 10; i++){
		sarray[i].print();
	}
	cout << endl << endl;

	//TODO: create another array of pointers to students that again point to the students in sarray
	//name the array psarrayN
	//Then sort just the pointers in DESCENDING (z to a) alphabetical order of Student's names
	Student * psarrayN[10];
	for (int i = 0; i < 10; i++){
		psarrayN[i] = &sarray[i];
	}

	sort(&psarrayN[0], &psarrayN[10], sortName);

	 //This will print the students from psarrayN after you have correctly set it up.
	cout <<"sort pointer: ";
	for (int i=0; i<10; i++) psarrayN[i]->print();
	cout <<endl<<endl;
	

}