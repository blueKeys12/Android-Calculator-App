#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class AnagramMaker{
public: 
	AnagramMaker(const std::string &dictionaryFile);
	unsigned int findAnagrams(const string &input, const bool &print) const;


private:
	vector<string> dict;

	unsigned int findAnagrams(vector<string> &smallD, string &sofar,const string &input, const bool &print , std::vector<string>::iterator &Dit) const{
		
		int count = 0;
		string str = input;
		string pastsofar = sofar;
		std::vector<string>::iterator git = Dit; 
		for (std::vector<string>::iterator it =Dit; it != smallD.end(); it++){
			if ((*it).length()> input.length()) break; //cuts the time down in half by breaking out of the loop if any word is bigger than input
				if (checkRemoveWord(*it, str)){		//this checks to see if the word can be part of a anagram. if it is, then the word	
			if (str == ""){ //an anagram has been found
						if (print){
							cout << sofar << " " << *it << endl;
						}
						count++;
					}
					else{
						sofar = sofar + " " + *it;	
						count += findAnagrams(smallD, sofar, str, print, it); //recursive call with the changed str,
						//the iterator is being passed by reference so when the function returns, it should be changed to be 
						//pointing at the spot in smallD when return is called.
					}
				}
				sofar = pastsofar;
				str = input;
		}
		return count; 
	}

	bool checkWord(const string &word, const string &input)const{
		string in = input;
		int loc = 0;
		for (size_t i = 0; i < word.length(); i++){
			loc = in.find(word[i]);
			if (loc == string::npos) return false;
			else in.erase(loc,1);
		}
		return true; 
	} //returns true if the word can be made from input else false

	bool checkRemoveWord(const string &word, string &input)const{
		string in = input;
		int loc = 0;
		for (size_t i = 0; i < word.length(); i++){
			loc = in.find(word[i]);
				if (loc == string::npos)return false;
				else
					in.erase(loc,1);
		}
		input = in; 
		return true;
	} //returns true if the word can be made from input, also changes input.
};