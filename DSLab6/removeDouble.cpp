#include <iostream>
using namespace std;

class LList {
public:
	LList() :head(0), tail(0) {}  //same as head=tail=0;  same as head=tail=NULL;
	~LList() {//works for both #1 and #2
		Node * cur = head;
		while (cur) {
			cur = cur->next;
			delete head;
			head = cur;
		}
	}
	
	
	void insert(int val) {// always add to the end, ignoring memory issues, for #2
	if (!tail) {
	head=tail=new Node(val);	//new first element is both head and tail
	}
	else {
	tail->next=new Node(val, 0, tail);//new tail, its prev is old tail, no next
	tail=tail->next;
	}
	}

	//this prints the values in reverse starting with the last value, for #2 only
	void printReverse() const;

	
	bool remove(int val);		//return true iff val was found

private:
	struct Node {
		Node(int d, Node *n = 0, Node *p = 0) : data(d), next(n), prev(p) {}
		int data;
		Node *next, *prev;
	};
	Node * head, *tail;
};





bool LList::remove(int val){ //REMINDER TO SELF: check to see if prev and next is null.
	Node * curr = tail;

	while (curr != NULL && curr->data != val){
		curr = curr->prev;
	}//working backwards to val. since its a doubly linked list,  don't need to keep track of what's behind curr

	if (curr == NULL)return false;

	if (curr == head)//if val is head->data, also checks if prev is null for me.
		head = head->next;
	else
		curr->prev->next = curr->next;  //since curr->prev exists, set its next equal to curr->next

	if (curr == tail)//if val is tail->data, also checks if next is null for me.
		tail = tail->prev;
	else
		curr->next->prev = curr->prev; //since curr->next exists, set its prev equal to curr->prev. 

	delete curr;
	return true;



}


void LList::printReverse()const{
	Node * curr = tail;
	while (curr){
		cout << curr->data << endl;
		curr = curr->prev;
	}

}

void main(){
	LList hello;
	hello.insert(1);
	hello.insert(2);
	hello.insert(3);
	hello.printReverse();//123
	hello.remove(2);
	hello.printReverse();//13
	hello.remove(3);
	hello.printReverse();//1
	hello.remove(1);
	hello.printReverse();//NOTHING 


}