#include <iostream>
#include <string>
//#include <cstdio>
using namespace std;

string listOf(const string &ch, const string &str){
	int length = str.length();
	int index = 0;
	int prev = -1;
	string output = "";

	for (int i = 0; i < length; i++){
		index = str.find_first_of(ch, i);
		if (index != -1 && index != prev){
			output = output + std::to_string(index) + " ";
			prev = index;
		}

	}
	return output;
}

string format(const string &name){
	int lastIndex = name.find_last_of(" ");
	string last = name.substr(lastIndex+1);
	int firstIndex = name.find_first_of(" ");
	last = last + ", " + name.substr(0, firstIndex) + ", " + name.substr(firstIndex+1, (lastIndex)- firstIndex-1) + "!";
	
	/*string first = name.substr(0, firstIndex-1);
	string middle = name.substr(firstIndex, lastIndex - firstIndex);
	return first + last + middle;*/
	return last;
}

string findNumbers(const string &expr){
	int length = expr.length();
	
	string output = "";
	int outLength = 0;

	for (int i = 0; i < length; i++){

		if (expr[i] - '0' > 9 || expr[i] - '0' < 0){
			if (outLength > 0 && output[outLength - 1] != ' '){
				output = output + ' ';
				outLength++;
			}		
		}
		else{
			output = output + expr[i];
			outLength++;
		}
	}
	
	return output;
}


void main(){
	string hello = "";
	cout << listOf("d",hello) << endl;
	cout << format(hello) << endl;
	cout << findNumbers(hello) << endl;

	string ch = "H";
	string str = "HHllH WorlH";
	cout << listOf(ch, str) << endl;
	cout << format("Dustin Ryan Hughes") << endl;
	
	string check = "4+ 293*(12 + var* 1838 +-31 )/18";

	cout << findNumbers(check) << endl;
}