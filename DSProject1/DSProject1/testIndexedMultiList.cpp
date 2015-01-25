#include "IndexedMultiList.h"
#include <iostream>

using namespace std;

void main(){


	IndexedMultiList iml;
	char check = '0';


	//WHEN LIST IS EMPTY
	cout << iml.empty() << endl;		//prints 1  (which is how true prints)
	cout << iml.uniqueSize() << endl; //prints 0
	iml.print(); //prints nothing 
	cout << iml.find('A') << endl; //returns -1
	cout << iml.countItem('B') << endl; //returns 0
	cout << iml.totalItemCount('C') << endl; //returns 0
	cout << iml.countPosition(0) << endl; //returns 0
	cout << iml.change(0, 10) << endl; //returns 0
	cout << iml.remove('A') << endl; // returns 0
	cout << iml.removeIndex(0) << endl; //returns -1
	cout << iml.removeAll('A') << endl; //returns 0
	cout << iml.getAt(0, check) << endl; //returns 0
	cout << endl;
	//*************************************************************


	//FOR insert, uniqueSize, size, empty, print
	cout << iml.insert(0, 'Z', 0) << endl; //prints 0  when count is invalid
	cout << iml.insert(-1, 'B', 10) << endl; //prints 0 when index is invalid
	cout << iml.insert(0, 'D', 4) << endl; //prints 1 and inserts 4 D into iml
	cout << iml.size() << endl; //prints 4 
	cout << iml.uniqueSize() << endl;//prints 1
	cout << iml.empty() << endl;		//prints 0 (false)
	cout << iml.insert(0, 'C', 3) << endl;	//prints 1 and inserts 3 C before the D in iml
	cout << iml.insert(1, 'Z', 33) << endl;	//prints 1 and inserts 33 Z at index 1, between C and D
	cout << iml.insert(3, 'E', 5) << endl;	//prints 1 and inserts 5 E’s at index 3 which is at end
	cout << iml.uniqueSize() << endl; // prints 4
	cout << iml.size() << endl;	//prints 47
	iml.print();			//prints out the following 4 lines:
	/*3 C
		33 Z
		4 D
		5 E*/
	cout << endl;
	//**********************************************************************

	//FOR getAT
	cout << iml.getAt(-1, check) << endl; //prints 0 when index is invalid
	cout << iml.getAt(10, check) << endl; //prints 0 when index is not in use
	cout << iml.getAt(0, check) << endl; //print 1 testing first spot in array
	cout << check << endl; //prints C checks to see that check changed to val at 0 index
	cout << iml.getAt(3, check) << endl; //prints 1 checks the end of the arry
	cout << check << endl;//prints E checks to see that check changed to val at 3 index
	cout << endl;
	//****************************************************************************************


	//FOR find
	cout << iml.find('C') << endl;	//prints 0, C is at index 0
	cout << iml.find('D') << endl;	//prints 2
	cout << iml.find('A') << endl;	//prints –1, it isn’t found
	cout << endl;
	//*******************************************************************


	//For countItem
	cout << iml.countItem('F') << endl; //prints 0 because F is not in the array
	cout << iml.countItem('C') << endl; // prints 1, testing that total instance of C is included
	iml.insert(4, 'C', 3);
	cout << iml.countItem('C') << endl; //prints 2, testing that both instances of C are included
	cout << endl;
	//***************************************************************************************

	//For totalItemCount
	cout << iml.totalItemCount('F') << endl; // prints 0 because F is not in the array
	iml.insert(5, 'F', 20);
	cout << iml.totalItemCount('F') << endl; //prints 20 testing that totalItemCount works for one instance of F
	iml.insert(6, 'F', 10);
	cout << iml.totalItemCount('F') << endl; // prints 30, testing that total count of both F's are included
	cout << endl;
	//*********************************************************************************

	//For countPosition
	cout << iml.countPosition(-4) << endl; //prints 0 testing when index is invalid
	cout << iml.countPosition(19) << endl; //prints 0 testing when index is not in use
	cout << iml.countPosition(0) << endl; // prints 3 testing beginning array
	cout << iml.countPosition(5) << endl; //prints 20 testing middle of array
	cout << iml.countPosition(6) << endl; //prints 10 testing end of array
	cout << endl;
	//********************************************************************************

	//For update
	cout << iml.update('K', 20000) << endl; //returns 0 because K is not in array
	iml.print();
	cout << iml.update('C', -20) << endl; //returns 1, testing that the first C gets removed from array
	cout << iml.update('F', 10) << endl; //returns 1, testing that 10 is added to first instance of F
	iml.print();
	cout << endl;
	//*******************************************************************************

	//For Remove
	cout << iml.remove('O') << endl; //prints 0, O does not exist in the list
	cout << iml.remove('F') << endl;//prints 1, testing that 1 item will be removed
	iml.insert(6, 'R', 1);
	iml.print();
	//33 Z
	//4 D
	//5 E
	//3 C
	//29 F
	//10 F
	//1 R
	cout << iml.remove('R') << endl;//prints 1, testing that R will be completely removed. 
	iml.print();
	//33 Z
	//4 D
	//5 E
	//3 C
	//29 F
	//10 F
	cout << endl;
	//****************************************************************************************

	//For removeIndex
	cout << iml.removeIndex(19) << endl;//prints -1 when index is not in use
	cout << iml.removeIndex(-5) << endl;//prints -1  when index is invalid
	cout << iml.removeIndex(5) << endl;//prints 10, testing removing from the middle. Removes last F
	cout << iml.removeIndex(0) << endl;//prints 33, testing removing from the beginning of array
	cout << iml.removeIndex(3) << endl;//prints 29, testing removing from the end off array. Removes C
	iml.print();
	//4 D
	//5 E
	//3 C
	cout << endl;
	//***********************************************************************

	//for removeAll
	cout << iml.removeAll('K') << endl; //return 0
	iml.insert(3, 'D', 5);
	iml.print();
	//4 D
	//5 E
	//3 C
	//5 D
	cout << iml.removeAll('D') << endl;//returns 1, testing that first D is removed from the list
	iml.print();
	//5 E
	//3 C
	//5 D
	cout << iml.removeAll('D') << endl;//returns 1, testing 
	iml.print();
	//5 E
	//3 C
	cout << endl;
	//************************************************************************

	//For Change
	cout << iml.change(-5, 20) << endl; //returns 0 when index is invalid
	cout << iml.change(20, 20) << endl; //returns 0 when index is not in use
	cout << iml.change(0, 10) << endl; //reteurns 1 changes 5 E to 15 E
	iml.print();
	//15 E
	//3 C
	cout << iml.change(0, -15) << endl; //returns 1 changes 15 E to 0 and shifts everything over 
	iml.print();
	//3 C
}