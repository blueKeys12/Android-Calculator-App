#include "MiniSearch.h"
#include <map>
#include <fstream>
#include <queue>
#include <algorithm>

MiniSearch::MiniSearch(const vector<string>&files){
	size = 0; 
	for (vector<string>::const_iterator it = files.begin(); it != files.end(); it++){
		fileVec.push_back(*it);
		addDocument(*it);
	}
}

bool MiniSearch::addDocument(const string &file){
	ifstream read;
	read.open(file);
	string line;
	if (read){
		while (getline(read, line)){
			removeSpacingInsertM(line);
		}
		size++;
		return true; 
	}
	read.close();
	return false; 
}

int MiniSearch::query(const string &q, vector<string> &result, bool print) const{
	queue<string> words;
	queue<string> opers; //Currently only using the first item in opers. 
						//if I had more time I would tried to use this for multiple operators.
	removeSpacingInsert(q, words, opers);
	
	vector<bool>fileChecks; 
	
	
	if (opers.empty()){
		for (vector<string>::const_iterator it = fileVec.begin(); it != fileVec.end(); it++)
			fileChecks.push_back(true);
		oneQuery(words, fileChecks);
	}
	else if (opers.front() == "AND"){
		for (vector<string>::const_iterator it = fileVec.begin(); it != fileVec.end(); it++) 
			fileChecks.push_back(true);
		andQuery(words, fileChecks);
	}
	else if (opers.front() == "OR"){
		for (vector<string>::const_iterator it = fileVec.begin(); it != fileVec.end(); it++)
			fileChecks.push_back(false);
		orQuery(words, fileChecks);
	}
	else if (opers.front() == "NOT"){
		for (vector<string>::const_iterator it = fileVec.begin(); it != fileVec.end(); it++) 
			fileChecks.push_back(true);
		oneQuery(words, fileChecks);
		notQuery(words, fileChecks);
	}
	printFound(print, fileChecks);
	return 0;
}




