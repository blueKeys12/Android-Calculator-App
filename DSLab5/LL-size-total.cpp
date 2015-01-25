#include <iostream>
using namespace std;


//Implement the size and total methods of LList

class LList {
public:
	LList() { head = 0; }
	void insert(int val) {// always add to the beginning, ignoring memory issues
		Node * newGuy = new Node;
		newGuy->data = val;
		newGuy->next = head;
		head = newGuy;
	}
	int size() const{
		if (!head) return 0;
		Node * curr = head;
		int counter = 0;
		while (curr){
			curr = curr->next;
			counter++;
		}
		return counter;

	} //returns number of Nodes in LList
	int total() const{
		if (!head) return 0;
		Node * curr = head;
		int counter = curr->data;
		while (curr->next){
			curr = curr->next;
			counter = counter + curr->data;
		}
		return counter;
	}//returns sum of all the integers in the LList
private:
	struct Node {

		int data;
		Node *next;
	};
	Node * head;
};


void main() {
	LList test;
	cout << test.size() << endl;  //should print 0 since there are 0 nodes (it is empty)
	cout << test.total() << endl;  //should print 0 since the sum of all the values (all none of them) is 0
	test.insert(5);
	test.insert(8);
	test.insert(23);
	test.insert(-6);
	cout << test.size() << endl;  //should print 4 since there are 4 nodes
	cout << test.total() << endl;  //should print 30 since 5 + 8 + 23 + -6 is 30
}