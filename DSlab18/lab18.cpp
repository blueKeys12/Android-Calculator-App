#include <iostream>
using namespace std;

class LL {
public:
	LL() { head = 0; }
	void insertHead(int v) { head = new Node(v, head); }
	int sumRecursive() const { return sumRecursive(head); } //obviously wrong, fix it
private:
	struct Node {
		Node(int d, Node *n) : data(d), next(n) {}
		int data;
		Node * next;
	};
	Node * head;

	int sumRecursive(Node * curr) const { 
		
		if (!curr) return 0;
		
		return sumRecursive(curr->next) + curr->data;

	}
};
void main() {
	LL numbers;
	cout << numbers.sumRecursive() << endl;
	numbers.insertHead(5);
	numbers.insertHead(7);
	numbers.insertHead(3);
	numbers.insertHead(1);
	numbers.insertHead(8);
	cout << numbers.sumRecursive() << endl;
}