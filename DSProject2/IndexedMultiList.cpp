#include "IndexedMultiList.h"
#include <iostream>
using namespace std;

IndexedMultiList::IndexedMultiList(){
	siz = 0;
	head = NULL;
}

IndexedMultiList::~IndexedMultiList(){
	Node * curr = head;
	while (head != NULL){
		head = head->next;
		delete curr;
		curr = head;
	}
}


bool IndexedMultiList::insert(int index, char val, int count){
	if (index > siz || index < 0 || count <= 0) return false;

	Node * newGuy = new Node;
	if (newGuy == NULL) return false; //out of memory
	newGuy->val = val;
	newGuy->count = count;

	Node * curr = head;
	Node * trail = NULL;

	for (int i = 0; i < index; i++){
		trail = curr;
		curr = curr->next;
	}

	if (curr == head){
		head = newGuy;
		head->next = curr;
	}//head check 
	else{
		trail->next = newGuy;
		newGuy->next = curr;
	}
	siz++;
	return true;
}

void IndexedMultiList::print()const{
	
		Node * curr = head;
		while (curr){
			cout << curr->val << " " << curr->count << endl;
			curr = curr->next;
		}
	
		
		 
}

bool IndexedMultiList::empty()const{
	 return(!head);
 }
 
int IndexedMultiList::uniqueSize()const{
	return siz;
}

 int IndexedMultiList::size()const{
	 if (!head) return 0;
	  
	 int total = 0;
	 Node * curr = head;
	 while (curr){
		 total = total + curr->count;
		 curr = curr->next;
	 }
	 return total;
 }

 int IndexedMultiList::find(char val)const{
	 if (!head) return -1;

	 Node * curr = head;
	 int index = 0;
	 while (curr && curr->val != val){
		 index++;
		 curr = curr->next;
	 }

	 if (!curr) return -1;
	 return index; 
 }

 int IndexedMultiList::countItem(char val)const{
	 if (!head) return 0; 

	 Node * curr = head;
	 int counter = 0;
	 while (curr){
		 if (curr->val == val) counter++;
		 curr = curr->next;
	 }
	 return counter;
 }


 int IndexedMultiList::totalItemCount(char val)const{
	 if (!head) return 0;

	 Node * curr = head;
	 int total = 0;
	 while (curr){
		 if (curr->val == val) total = total + curr->count;
		 curr = curr->next;
	 }
	 return total;
 }


 int IndexedMultiList::countPosition(int index)const{
	 if (!head || index < 0 || index >= siz) return 0;

	 Node * curr = head;
	 for (int i = 0; i < index; i++){
		 curr = curr->next;
	 }
	 return curr->count;
 }

 bool IndexedMultiList::getAt(int index, char &out)const{
	 if (!head || index < 0 || index >= siz) return false;
	
	 Node * curr = head;
	 for (int i = 0; i < index; i++){
		 curr = curr->next;
	 }
	 out = curr->val;
	 return true;
 }

 bool IndexedMultiList::update(char val, int amount){
	 if (!head) return false;

	 Node * curr = head;
	 Node * trail = NULL; //needed if needing to remove a node
	 while (curr && curr->val != val){
		 trail = curr;
		 curr = curr->next;
	 }

	 if (!curr) return false;
		curr->count = curr->count + amount;
		if (curr->count <= 0){
			siz--;
			remove(curr, trail); //if curr->count is less than 0, remove that node. 
		}
	 return true;
 }

 bool IndexedMultiList::change(int index, int amount){
	 if (!head || index < 0 || index >= siz) return false;

	 Node * curr = head;
	 Node * trail = NULL;
	 for (int i = 0; i < index; i++){
		 trail = curr;
		 curr = curr->next;
	 }

	 if (!curr) return false;
	 curr->count = curr->count + amount;
	 if (curr->count <= 0) {
		 siz--;
		 remove(curr, trail);
	 }
	 return true;
 } 

 bool IndexedMultiList::remove(char val){
	 if (!head) return false;

	 Node * curr = head;
	 Node * trail = NULL;
	 while (curr && curr->val != val){
		 trail = curr;
		 curr = curr->next;
	 }

	 if (!curr) return false;
	 curr->count--; 
	 if (curr->count == 0){
		 siz--;
		 remove(curr, trail);
	 }//Calls the Private remove function when Count is 0.
	 return true;
 }

int IndexedMultiList::removeIndex(int index){
	 if (!head || index < 0 || index >= siz) return -1;

	 Node * curr = head;
	 Node * trail = NULL;
	 for (int i = 0; i < index; i++){
		 trail = curr;
		 curr = curr->next;
	 }
	 int total = curr->count;
	 siz--;
	 remove(curr, trail);
	 return total;
 }

int IndexedMultiList::removeAll(char val){
	 if (!head) return 0;

	 Node * curr = head;
	 Node * trail = NULL;
	 int total = 0;

	 while (curr && curr->val != val){
		 trail = curr;
		 curr = curr->next;
	 }

	 if (curr) total = curr->count;
	 siz--;
	 remove(curr, trail);
	 return total;
 }
