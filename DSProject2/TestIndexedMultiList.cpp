#include "IndexedMultiList.h"
#include <iostream>
using namespace std;

void main(){

	IndexedMultiList iml;
	char test = 'a';
	


	cout << iml.uniqueSize() << endl;
	iml.insert(0, 'a', 1);
	iml.insert(0, 'a', 1);
	iml.insert(0, 'a', 1);
	iml.insert(0, 'a', 1);
	iml.insert(0, 'a', 1);
	iml.insert(0, 'a', 1);
	iml.insert(0, 'a', 1);
	iml.insert(0, 'a', 1);
	cout << iml.uniqueSize() << endl;
	iml.update('a', -4);
	cout << iml.uniqueSize() << endl;
	iml.change(4, -10);
	cout << iml.uniqueSize() << endl;
	iml.remove('a');
	cout << iml.uniqueSize() << endl;
	iml.removeIndex(4);
	cout << iml.uniqueSize() << endl;
	iml.removeAll('a');
	cout << iml.uniqueSize() << endl;



	/*cout << iml.empty() << endl;
	cout << iml.uniqueSize() << endl;
	cout << iml.insert(0, 'a', 1) << endl;
	cout << iml.insert(10, 'a', 5) << endl;
	cout << iml.insert(1, 'b', -5) << endl;
	cout << iml.insert(1, 'c', 2) << endl;
	cout << iml.insert(2, 'd', 3) << endl;
	cout << iml.insert(0, 'e', 4) << endl;
	cout << iml.insert(4, 'f', 5) << endl;
	cout << iml.insert(4, 'c', 6) << endl; 
	cout << iml.empty() << endl;
	cout << iml.uniqueSize() << endl;

	cout << iml.find('e') << endl;
	cout << iml.find('z') << endl;
	cout << iml.find('f') << endl;
	cout << iml.find('d') << endl;
	iml.print();
	cout << iml.update('c', -7) << endl;
	iml.print();
	cout << iml.change(0, -10) << endl;
	iml.print();
	cout << endl;
	iml.insert(2, 'a' , 5);
	iml.insert(2, 'a', 6);
	iml.print();
	cout << iml.removeAll('a') << endl;
	iml.print();*/

}