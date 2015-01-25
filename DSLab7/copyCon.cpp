#include <iostream>
using namespace std;

/*Declare an implement the copy constructor for the LList class.*/

class LList {
public:
	LList() { head = 0; }
	LList(const LList &src){
		if (src.head){
			head = new Node(src.head->data);
			Node * curr = head;
			Node * currsrc = src.head->next;
			while (currsrc != NULL){
				curr->next = new Node(currsrc->data);
				curr = curr->next;
				currsrc = currsrc->next;
			}

		}
	}
	void insert(int val) {// always add to the beginning, ignoring memory issues
		head = new Node(val, head);
	}
	void print() const {
		for (Node * cur = head; cur != 0; cur = cur->next) cout << cur->data << ", ";
		return; //return?
	}
	bool removeLast(int val) {
		/* search through the linked list and remove the LAST Node with val in it
		return true iff you find a Node with val in it.*/
		if (head == NULL)return false;

		Node * curr = head; //needed three node pointers. curr is to travel through the list.
		Node * trail = NULL;// trail is so I don't lose the previous node from the last node that holds val
		Node * place = NULL;// place is so I don't lose where val is last found.

		if (curr->data == val){
			trail = head;
			place = curr;
		}//special case for when head is val so not to lose it before entering loop

		while (curr->next != NULL){
			if (curr->next->data == val){
				trail = curr;
				place = curr->next;
			}
			curr = curr->next;
		}
		
		if (place == NULL)return false;//

		if (place == head){
			head = head->next;
		}//check head
		else
			trail->next = place->next;
		delete place;
		return true;
	}

private:
	struct Node {
		Node(int d, Node *n = 0) { data = d; next = n; }
		int data;
		Node *next;
	};
	Node * head;
};


void main() {
	LList list1;
	list1.insert(5);
	list1.insert(6);
	list1.print(); //should output 6 5
	LList listCopy(list1);
	listCopy.print(); //should output 6 5
	listCopy.insert(19);
	list1.insert(-5);
	cout << endl;
	listCopy.print(); //should print 19 6 5
	list1.print(); //should print -5 6 5
	cout << endl;
	LList listR;
	listR.insert(5);
	listR.insert(4);
	listR.insert(5);
	listR.insert(6);
	listR.insert(5);
//	cout << "removeLast(5) returned: " << listR.removeLast(5) << endl;
	listR.print();
	cout << "\nremoveLast(5) returned: " << listR.removeLast(5) << endl;
	listR.print();
	cout << "\nremoveLast(5) returned: " << listR.removeLast(5) << endl;
	listR.print();
	cout << "\nremoveLast(5) returned: " << listR.removeLast(5) << endl;
	listR.print();
}