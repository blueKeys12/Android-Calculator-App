#include "AnagramMaker.h"
#include <queue>
#include <algorithm>
bool compare(string& first, string& second) {
	return first.size() < second.size();
}//predicate function for sort called in public findAnagrams
AnagramMaker::AnagramMaker(const std::string &dictionaryFile){
	ifstream read;
	read.open(dictionaryFile);
	string line;
	if (read){
		while (getline(read, line)){
			dict.push_back(line);
			}
		}
		read.close();
}

unsigned int AnagramMaker::findAnagrams(const string &input, const bool &print) const{

	vector<string> smallD;
	string word = "";
	for (std::vector<string>::const_iterator i = dict.begin(); i != dict.end(); i++){
		word = *i; 
		if (word.size() <= input.size()){
			if (checkWord(word, input)) smallD.push_back(*i);
		}
		
	}// shrink down the main dictionary into smallD by removing anything bigger than input or anything that absolutely cannot be in the anagram
		
	sort(smallD.begin(), smallD.end(), compare); //sorts small words to big words. uses predicate

	string sofar = "";
	vector<string>::iterator Dit = smallD.begin(); 	
	 return findAnagrams(smallD, sofar, input, print, Dit);
}


