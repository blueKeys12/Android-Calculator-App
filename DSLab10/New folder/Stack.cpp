#include "Stack.h"

Stack::Stack(int size){
	siz = size;
	arr = new ItemType[size];
	index = -1;
}

Stack::~Stack(){
	delete [] arr;
}

bool Stack::empty()const{
	if (index != -1)return false;
	return true;
}

bool Stack::top(ItemType &output) const{
	if (index == -1)return false;
	output = arr[index];
	return true;
}


bool Stack::push(ItemType item){

	if (index + 1 != siz){
		arr[index + 1] = item;
		index++;
		return true;
	}
	return false;
}

bool Stack::pop(){
	if (index == -1) return false;
	index--;
	return true;
}



void main() {
	Stack myStack(5);	//space for 5 elements
	string x;
	cout << myStack.empty() << endl;	// should print true
	cout << myStack.pop() << endl;	//should print false since there is nothing to pop
	cout << myStack.top(x) << endl;	//should print false, x should remain unchanged

	cout << myStack.push("hello") << endl;//should print true;
	cout << myStack.empty() << endl;	// should print false
	cout << myStack.top(x) << endl;	//should print true, x should now be "hello"
	cout << x << endl << endl;//should print "hello"

	cout << myStack.pop() << endl;	//should print true, 
	cout << myStack.empty() << endl;	// should print true

	string arr[] = { "first", "second", "third", "fourth", "fifth" };
	for (int i = 0; i<5; i++) cout << myStack.push(arr[i]) << endl;	//all 5 should print true

	cout << myStack.push("bob") << endl;	//should print false; all full

	bool ret;
	for (int i = 4; i >= 0; i--) {
		ret = myStack.top(x);
		if (ret && x == arr[i]) cout << "OK on " << i << endl;
		else cout << "Error on " << i << endl;
		myStack.pop();
	}
	cout << myStack.empty() << endl;	// should print true

}
