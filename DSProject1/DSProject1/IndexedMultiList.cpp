#include "IndexedMultiList.h"
#include <iostream>
using namespace std;


IndexedMultiList::IndexedMultiList(){
	siz = 0;
}

bool IndexedMultiList::empty(){
	return (siz == 0);
}//returns true iff (if and only if) list is empty


int IndexedMultiList::uniqueSize(){
	  return siz;
}//returns number of positions in the list in use


int IndexedMultiList::size(){
	if (siz == 0) return 0;

	int counter = 0;
	int total = 0;
	while (counter!=siz){
		total = arr[counter].count + total;
		counter++;
	}//adding up the total counts in the array 

	return total;

}	
//returns total number of items in list using counts
//If 2 A, 3 C, 1 D are inserted into an IndexedMultiList iml then 
//iml.uniqueSize() would return 3 and iml.size() would return 6.


int IndexedMultiList::find(char val){
	if (siz==0)return -1;
	for (int i = 0; i < siz; i++){
		if (arr[i].val == val)
			return i;
	}
	return -1;
}//returns index of first position with val in it or –1 if not found

int IndexedMultiList::countItem(char val){
	if (siz==0)return 0;

	int counter = 0;

	for (int i = 0; i < siz; i++){
		if (arr[i].val == val)
			counter++;
	}//counter increases as the number of times val is located in the array
	return counter;
}//returns number of locations val is in the list (vacuously 0 if not found)


int IndexedMultiList::totalItemCount(char val){
	if (siz==0) return 0;

	int counter = 0;
	for (int i = 0; i < siz; i++){
		if (arr[i].val == val)
			counter = counter + arr[i].count;
	}//counter increases whenever val is located in the array. 
	return counter;
}//returns total number of val in the list (vacuously 0 if not found)



int IndexedMultiList::countPosition(int index){
	if (siz==0 || index < 0 || index >= siz)return 0;
	
	return arr[index].count;

}//returns number of items at position index (0 based) or 0 if index is invalid

 bool IndexedMultiList::getAt(int index, char &out){
	if (siz == 0 || index<0 || index>=siz) return false;

	out = arr[index].val;
	return true;
}//if position index is in use, out is set to char at that position and true is returned, otherwise false is returned. This is kind of like [] for an array but with error checking*/


 void IndexedMultiList::print(){
	if (siz != 0){
		for (int i = 0; i < siz; i++){
			cout << arr[i].count << " " << arr[i].val << endl;
		}
	}

}//prints out the content of the list in order by position, see below

//mutators
bool IndexedMultiList::insert(int index, char val, int count){
	if (siz == DEFAULT_MAX_ITEMS || count <= 0 || index < 0) return false;
	for (int i = siz; i > index; i--){
		arr[i].val = arr[i - 1].val;
		arr[i].count = arr[i - 1].count;
	}
	arr[index].val = val;
	arr[index].count = count;
	siz++;
	return true;
}//insert count number of val into the list at position index shifting the rest of the values and returns true iff val was able to fit in list, index was valid and count >=1. Valid indices range from 0 up to unique size (inclusive). So for an empty list, 0 is the only valid index. insert should do nothing if index is invalid, the list is full, or count <1. If the list has 3 A’s in the first position, then 0 and 1 are the only valid indices.*/

bool IndexedMultiList::update(char val, int amount){
	if (siz == 0) return false;

	for (int i = 0; i < siz; i++){
		if (arr[i].val == val){
			arr[i].count = arr[i].count + amount; // if val located, add amount to its count
			if (arr[i].count <= 0){
				for (int j = i; j < siz; j++){
					arr[j].count = arr[j + 1].count;
					arr[j].val = arr[j + 1].val;
				}
				siz--;
			} // if count is less than 0, remove it from the list by shifting and subtract 1 from siz
			return true;
		}
	}
	return false;
}/*finds val in list and adds amount (which could be negative) return true iff found, works similarly to change but is based on the character to find instead of the position. If val is in multiple locations within the list, then only change the first location */

bool IndexedMultiList::change(int index, int amount){
	if (siz == 0  || index < 0 || index >= siz) return false;

	arr[index].count = arr[index].count + amount;
	if (arr[index].count <= 0){
		for (int i = index; i < siz; i++){
			arr[i].count = arr[i + 1].count;
			arr[i].val = arr[i + 1].val;
		}
		siz--; 
	}// if count is less than 0, remove it from the list by shifting and subtract one from siz
	return true;
}///*add amount to item in position index and returns true iff index was valid. change should do nothing if index is invalid. amount could be negative. If adding amount to the current count results in a count of <= 0 then that position should be ‘removed’ (shift the rest of the items). For example, if there are 3 A’s at index 0 and 2 B’s at index 1 in the list iml then


bool IndexedMultiList::remove(char val){
	if (siz == 0) return false;
	int index = find(val);
	if (index == -1)return false;
		
	arr[index].count--;
	if (arr[index].count <= 0){
		for (int i = index; i < siz; i++){
			arr[i].count = arr[i + 1].count;
			arr[i].val = arr[i + 1].val;
		}
		siz--;
	}
		
		return true;
}	//removes 1 instance of val from list and //returns true iff val was in list, if val is in multiple locations, then //only remove from the first location. This may result in a shift.

int IndexedMultiList::removeIndex(int index){
	if (siz == 0|| index < 0 || index >= siz) return -1;
	int total = arr[index].count;
		for (int i = index; i < siz; i++){
			arr[i].count = arr[i + 1].count;
			arr[i].val = arr[i + 1].val;
		}
		siz--;
		return total;
}	//remove all items in position index,


int IndexedMultiList::removeAll(char val){
	if (siz == 0) return 0;

	
	for (int i = 0; i < siz; i++){
		if (arr[i].val == val){
			removeIndex(i);
			return i;
		}// if val is found, call removeIndex to the location of i. 
	}
	return 0;
}//removes all instances of val from list
//returns number of items removed, which could be 0, if val is in 
