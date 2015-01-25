#include <vector>
#include <string>
#include <iostream>
#include "StopWatch.h"
#include "MiniSearch.h"
using namespace std;

void main(){

	vector<string> files;
	files.push_back("Doc1.txt");
	files.push_back("Doc2.txt");
	files.push_back("Doc3.txt");
	files.push_back("Doc4.txt");
	files.push_back("Doc5.txt");
	files.push_back("Doc6.txt");
	MiniSearch test(files);
	vector<string> testV;
	bool print = true;

	test.query("middle", testV, print); 
	
}


//
//
//void runTest(const MiniSearch &ms, const string &query, const bool &print) {//not required to use
//	vector <string> res;
//	if (print) cout << query << ":\t ";
//	ms.query(query, res, print);
//}
//vector< string> getFileList(const char * list) {//returns a vector of filenames 
//	//this allows list to be things like *.txt or test1\*.txt or documents/tests/files*.txt
//	HANDLE hFind;
//	WIN32_FIND_DATA FindFileData;
//	vector< string> ret;
//	//if there is a path part of the parameter, prepend it to all returned filenames
//	string lis = list;
//	unsigned int loc = lis.find_last_of("\\/");
//	if (loc != -1)  lis = lis.substr(0, loc + 1);
//	else		  	  lis.clear();
//	hFind = FindFirstFile(list, &FindFileData);
//	if (hFind != INVALID_HANDLE_VALUE){
//		do{
//			//	  printf("%s\n", FindFileData.cFileName); 
//			ret.push_back(lis + FindFileData.cFileName);
//		} while (FindNextFile(hFind, &FindFileData));
//		FindClose(hFind);
//	}
//	return ret;
//}
//void testSet1() {//runs a bunch of tests just using doc1, doc2, and doc3.
//	//tests are not exhaustive
//	bool print = true;
//	cout << "\t\t\t 1 \n";
//	MiniSearch ms;
//	ms.addDocument("Doc1.txt");
//	runTest(ms, "like NEAR 2 class", print);
//	runTest(ms, "like NEAR 2 structures", print);
//	runTest(ms, "like AND blah", print);
//	runTest(ms, "like OR blah", print);
//	runTest(ms, "like AND class", print);
//	runTest(ms, "like OR hate", print);
//
//	cout << "\t\t\t 2 \n";
//	ms.addDocument("Doc2.txt");
//	runTest(ms, "like NOT blah", print);
//	runTest(ms, "like NOT class", print);
//	runTest(ms, "class NOT like", print);
//	runTest(ms, "like AND blah", print);
//	runTest(ms, "like OR blah", print);
//	runTest(ms, "like AND class", print);
//	runTest(ms, "like OR hate", print);
//	runTest(ms, "data AND hate", print);
//
//	cout << "\t\t\t 3 \n";
//	ms.addDocument("Doc3.txt");
//	runTest(ms, "data", print);
//	runTest(ms, "data AND structures", print);
//	runTest(ms, "like OR survey", print);
//	/*  If nothing is printed then there were no files found
//	1
//	like NEAR 2 class:   Doc1.txt,
//	like NEAR 2 structures:
//	like AND blah:
//	like OR blah:        Doc1.txt,
//	like AND class:      Doc1.txt,
//	like OR hate:        Doc1.txt,
//	2
//	like NOT blah:		Doc1.txt,
//	like NOT class:
//	class NOT like:		Doc2.txt,
//	like AND blah:
//	like OR blah:        Doc1.txt,
//	like AND class:      Doc1.txt,
//	like OR hate:        Doc1.txt, Doc2.txt,
//	data AND hate:       Doc2.txt,
//	3
//	data:				Doc1.txt, Doc2.txt, Doc3.txt,
//	data AND structures: Doc1.txt, Doc2.txt,
//	like OR survey:      Doc1.txt, Doc3.txt,
//	*/
//
//}
//int main(int argc, char* argv[]) {
//	int count = 0, totalCount = 0;
//	bool print = true;
//	CStopWatch s;
//	double time, total = 0;
//	//parameter checks
//	if (argc <4) {
//		printf("Error, not enough parameters.  They can be entered by:\n  Project, properties, configuration properties, debugging, command arguments.\nParameters are files to search, yes or no for printing, and the search string(s) to test.\n");
//		return 1;
//	}
//	if (strcmp(argv[2], "yes") == 0) print = true;
//	else if (strcmp(argv[2], "no") == 0) print = false;
//	else {
//		printf("error in 2nd parameter which must be yes or no (for printing), got %s\n", argv[2]);
//		return 2;
//	}
//	vector< string> files = getFileList(argv[1]);
//
//	if (print) {//print out filenames
//		cout << "Vector (" << argv[1] << "):";
//		for (unsigned int i = 0; i<files.size(); i++) cout << files[i] << ", ";
//		cout << endl;
//	}
//
//	s.startTimer();
//	MiniSearch ms(files);
//	s.stopTimer();
//	time = s.getElapsedTime();
//	printf("Preprocess time: %4.4f\n", time);
//
//	vector <string> res;
//
//	for (int i = 3; i<argc; ++i) {//run and time each query call
//		printf("\tInput phrase %s\n", argv[i]);
//		res.clear();
//		s.startTimer();
//		count = ms.query(argv[i], res, print);
//		s.stopTimer();
//		if (print) {
//			cout << count << "   " << argv[i] << ":\t ";
//			for (unsigned int j = 0; j<res.size(); j++) cout << res[j] << ", ";
//			cout << endl;
//		}
//		time = s.getElapsedTime();
//		total += time;
//		totalCount += count;
//		printf("Query total of %d matches time: %4.4f\n", totalCount, total);
//	}
//
//	return 0;
//}
