
	
#include <vector>
#include <list>
#include <iostream>
#include <string>
	using namespace std;

	class HashTable {
	public:
		HashTable(int arraySize){
			int pList[] = { 2, 11, 101, 503, 1009, 5003, 7717, 12829, 17929, 51539, 104729 }; //I really am not sure how many we need.
			int count = 0; 
			while (arraySize > pList[count])count++;
		
			size = pList[count];
			tableV = new vector<string>[size];
		}
		~HashTable(){
			delete []tableV; 
		}//since array is dynamic, this is needed.
		void insert(const string &val){
			int pos = hash(val); //position to be inserted at
			tableV[pos].push_back(val);
		}//allows duplicates
		bool search(const string &val) const{
			unsigned int pos = hash(val); //this will give me the position to check in the table
			for (vector<string>::iterator it = tableV[pos].begin(); it != tableV[pos].end(); it++)  {
				if (*it == val) return true;
			}
			return false; 
		}//return true iff found
		bool remove(const string &val){
			int pos = hash(val);
			for (vector<string>::iterator it = tableV[pos].begin(); it != tableV[pos].end(); it++)  {
				if (*it == val) {
					*it= tableV[pos].back(); // 
					tableV[pos].pop_back(); 
					return true;
				}
			}
			return false; 
		}//return true iff found, remove if found, 
		//if multiple instances exist, remove any 1 of them
		bool empty() const { //return true iff no items in hash
			for (unsigned int i = 0; i < size; i++){
				if (tableV[i].size() > 0) return false;
			}
			return true;
		}
	private:
		unsigned int size;
		vector<string> * tableV; 

		int hash(const string &input) const {
			if (input == "") return size-1; //place it to the back. 
			unsigned int pos = 0;
			for (unsigned int i = 0; i < input.length(); i++){
				pos = pos * input[i];
			}
			while (pos > size){
				pos = pos / 2;
			}
			return pos % size;
		} //take the 

		//name your hash function hash or h, you may assume input is 
		//suitably random and use simple hash functions
		//array goes here together with whatever else you want/need
	};


	void main() {

		HashTable test(10);
		cout << test.empty() << endl; 
		test.insert("dust");
		test.insert("hello");
		cout << test.empty() << endl; 
		cout << test.search("hello") << endl; 
		cout << test.remove("dust") << endl;
		cout << test.search("dust") << endl; 
		test.insert("this is a big string of banananananananananananananananananananas");
		cout << test.search("this is a big string of banananananananananananananananananananas") << endl; 
		cout << test.remove("dust") << endl; //0
		cout << test.empty() << endl; 
		test.insert(""); 
		test.insert("he");
		test.insert("hi");
		test.insert("ha");
		test.insert("heyah");
		test.insert("goodbye");
		test.insert("argh");

		//create a HashTable then insert, search, and remove strings to test it.
	}