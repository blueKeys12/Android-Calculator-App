#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std; 

class MiniSearch {
public:
	MiniSearch(); //This constructor has no documents

	MiniSearch(const vector<string> &files);
	//files is a vector of filenames, implemented by simply calling addDocument for each filename.

	bool addDocument(const string  &file);
	/*opens and reads file, return true iff it was able to successfully read file. This is the only method that should open a file (other than ignoreWords explained later). The files will contain only lower case words and no punctuation. There may be more than one word on a line. Use simple methods for reading the file rather than being concerned with speed. This means you can use C++ strings for file reading if they are more convenient. addDocument should do something with the words so that queries are fast. */

	int query(const string &q, vector<string> &result, bool print) const;
	/*q is the query string whose format is described in the next section
	result should be set to a list of unique documents for which q is true, it is an output variable
	query returns the size of result, which could be 0
	If print is true, it prints the documents in the result, otherwise it prints nothing
	query is const because asking about the documents shouldn’t change anything*/
private:
	
	int size; 
	
	multimap<string, int> wordMap;
	vector<string> fileVec;

void removeSpacingInsertM(string &line){
	string word = "";
	size_t loc = line.find_first_of(" ");
	while (loc != string::npos){//finds each word from line by locating spaces
		word = line.substr(0, loc);
		if (word != ""){//without this check I kept getting an empty string inserted into my multimap when using Doc2. Not sure why.
			if(!checkDuplicates(word,size)) wordMap.insert(std::pair<string, int>(word, size));
			line = line.substr(loc + 1, line.size() - 1);
			loc = line.find_first_of(" ");
		}
	}
	word = line.substr(0, line.size()); //retrieve the last word from line
	if (word != ""){
	if(!checkDuplicates(word, size))	wordMap.insert(std::pair<string, int>(word, size));
	}
}


bool checkDuplicates(const string &word,const int &fileNum ){
	pair <multimap<string, int>::const_iterator, multimap<string, int>::const_iterator> it;
	it = wordMap.equal_range(word);
	for (multimap<string, int>::const_iterator it2 = it.first; it2 != it.second; it2++){
		if (it2->second == fileNum)return true; 
	}
	return false; 
}


void removeSpacingInsert(const string &input, queue<string> &words, queue<string> &opers)const{
	string line = input; 
	string word = "";
	size_t loc = line.find_first_of(" ");
	vector<string> tempforWords;
	while (loc != string::npos){
		word = line.substr(0, loc);
		if (word != ""){
			if (word == "AND" || word== "OR" || word=="NOT") opers.push(word);
			else tempforWords.push_back(word);
			//else words.push(word);
			line = line.substr(loc + 1, line.size() - 1);
			loc = line.find_first_of(" ");
		}
	}
	word = line.substr(0, line.size()); //retrieve the last word from line
	if (word != ""){
		if (word == "AND" || word=="OR" || word=="NOT") opers.push(word);
		//else words.push(word);
		else tempforWords.push_back(word);
	}
	
	for (vector<string>::iterator it = tempforWords.begin(); it != tempforWords.end(); it++){
		words.push(*it);
	}
}




void andQuery(queue<string> &words, vector<bool> & fileChecks) const{
	while (!words.empty()) oneQuery(words, fileChecks);
}

	



void orQuery(queue<string> &words, vector<bool> & fileChecks) const{
	if (words.empty()) return;
	pair <multimap<string, int>::const_iterator, multimap<string, int>::const_iterator> it;
	it = wordMap.equal_range(words.front());
	if (it.first != it.second){
		multimap<string, int>::const_iterator it2 = it.first;
		for (int i = 0; i < size; i++){
			if (it2 == it.second){
				i = size;
			}
			if (it2->second == i){
				fileChecks[i] = true;
				it2++;
			}
		}
	}
	words.pop();
	orQuery(words, fileChecks);
}


void notQuery(queue<string> &words, vector<bool> & fileChecks) const{
	if (words.empty()) return;
	pair <multimap<string, int>::const_iterator, multimap<string, int>::const_iterator> it;
	it = wordMap.equal_range(words.front()); //this gives me the range within the multimap where the first word in words is found. 
	if (it.first == it.second)return;
	multimap<string, int>::const_iterator it2 = it.first;

	for (int i = it2->second; i < size; i++){
		if (it2 == it.second) break;
		if (it2->second == i){
			if (fileChecks[i] == true) fileChecks[i] = false;
		}	
		it2++;

	}

	words.pop();
	notQuery(words, fileChecks);
}


void oneQuery(queue<string> &words, vector<bool> &fileChecks)const{
	if (words.empty()) return;
	pair <multimap<string, int>::const_iterator, multimap<string, int>::const_iterator> it;
	it = wordMap.equal_range(words.front()); //this gives me the range within the multimap where the first word in words is found. 
	if (it.first == it.second) {
		while (!words.empty()) words.pop();
		for (int i = 0; i < size; i++) fileChecks[i] = false; 
		return;
	}
		multimap<string, int>::const_iterator it2 = it.first;
		for (int i = 0; i < size; i++){
			/*if (i < it2->second) fileChecks[i] = false;
			if (i == it2->second) it2++; */
			if (it2 == it.second){
				while (i != size){
					fileChecks[i] = false;
					i++;
				}
			}
			else{
				if (it2->second > i)fileChecks[i] = false;
				if (it2->second == i) it2++;
			}
		}
	words.pop();
}



void printFound(const bool &print, const vector<bool> &fileChecks)const{
	if (print){
		int counter = 0;
		for (vector<bool>::const_iterator it = fileChecks.begin(); it != fileChecks.end(); it++){
			if (*it) cout << fileVec[counter] << endl;
			counter++;
		}
	}
}



};
