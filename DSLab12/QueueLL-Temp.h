#include <iostream>
using namespace std;

// Template declaration for ItemType
template<typename ItemType>

class QueueLL {
public:
	QueueLL();
	~QueueLL();
	bool empty();	//return true iff queue is empty
	bool front(ItemType &output);	//output set to first ‘front’ (oldest) item, 
	//return true iff item exists, i.e. queue isn’t empty
	bool back(ItemType &output);	//like front but for most recent item
	void push(ItemType val);		//add val to ‘back’ of queue
	bool pop();				//remove item from ‘front’ of queue
private:
	//declare your Node structure here, any class data needed and any private members you would like.
	struct Node{
		ItemType data;
		Node * next;
		Node * prev;
	};
	Node head;
	Node tail;
};
//Put your implementations here
template<typename ItemType>
QueueLL::QueueLL(){
	head = NULL;
	tail = NULL;
}
template<typename ItemType>
QueueLL::~QueueLL(){
	Node * cur = head;
	while (cur) {
		cur = cur->next;
		delete head;
		head = cur;
	}
}

template<typename Itemtype>
bool QueueLL::empty(){
	return(!head);
}

template<typename Itemtype>
bool QueueLL::front(Itemtype &output){
	if (!head)return false;
	output = head->data;
	return true;
}

template<typename Itemtype>
bool QueueLL::back(Itemtype &output){
	if (!head)return false;
	output = tail->data;
	return true;
}

template<typename Itemtype>
void QueueLL::push(Itemtype val){
	Node * newGuy = new Node;
	newGuy->data = val;
	tail->next = newGuy;
	tail->prev = tail;
	tail = tail->next;
}

template<typename Itemtype>
bool QueueLL::pop(){
	if (!head) return false;
	if (head->next = NULL) delete head;
	else{
		head->prev = head;
		head = head->next;
		delete head->prev;
	}
	
	return true;
}