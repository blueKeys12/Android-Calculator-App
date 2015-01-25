#include <iostream>
using namespace std;

void main(){
	int *p;

	int x = 0;
	p = &x;
	*p = 5;
	p = new int;
	*p = 7;
	p = new int;
	*p = 8;
	delete p;
	*p = 9;
	cout << *p << endl;
}

// p = new int();
//
// *p = 7;
//
// p = new int();
//
// *p = 9;
//
//delete p;
//
// *p = 15;