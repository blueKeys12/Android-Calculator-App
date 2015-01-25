#include <iostream>
#include <string>
using namespace std;
typedef string ItemType;

class Stack {
public:
	Stack(int size);	//use size for the length of the underlying array
	~Stack();		//clean up dynamic memory
	bool empty() const;	//return true iff stack has no elements
	bool top(ItemType &output) const;
	bool push(ItemType item);
	bool pop();
private:
	ItemType *arr;
	int siz;
	int index;
};

