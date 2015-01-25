#include <iostream>
using namespace std;

bool twoTwo(int nums[], int size){
	if (size < 0) return false;
	if (size==0 ) return true; //special case when nothing is being checked return true

	if (size == 1){
		if (nums[0] == 2)return false;
		else return true;
	}//special case when only one number is being checked

	
		for (int i = 1; i < size ; i++){
			if (nums[i] == 2){
				if ((nums[i + 1] != 2) && (nums[i - 1] != 2))	return false;
			
			}

		}
		return true;
}



bool balanced(int nums[], int size){
	if (size <= 0) return false;
	int total1 = 0;
	int total2 = 0;
	
	for (int i = 0; i < size-1; i++){
			total1 = nums[i] + total1;
			for (int j = (size - 1); j > i; j--){
				total2 = nums[j] + total2;

			}//for loop adds up all the numbers from the end of the array to the index of i
			if (total1 == total2) return true; 
			total2 = 0;
			
	}

	return false;

}

int findAny(int array1[], int size1, int array2[], int size2){
if (size1 <= 0 || size2<=0) return false;



for (int i = 0; i < size1; i++){
	for (int j = 0; j < size2; j++){
		if (array1[i] == array2[j]){
			return i;
		}
	}

}


}


void main(){

	int arr1[] = { 4, 2, 2, 3 };
	int arr2[] = { 2, 2, 4 };
	int arr3[] = { 2, 2, 4, 2 };
	int arr4[] = { 1, 3, 4 };
	int arr5[] = { 1, 2, 2, 3, 4 };
	int arr6[] = { 1, 2, 3, 4 };
	int arr7[] = { 2, 2 };
	int arr8[] = { 2, 2, 7 };
	int arr9[] = { 2, 2, 7, 2, 1 };
	int arr10[] = { 4, 2, 2, 2 };
	int arr11[] = { 2, 2, 2 };
	int arr12[] = { 1, 2 };
	int arr13[] = { 2 };
	int arr14[] = { 1 };
		
	int arr16[] = { 5, 2, 2, 3 };
	int arr17[] = { 2, 2, 5, 2 };
	
	
	cout << twoTwo(arr1, 4)<< endl;// should be   true
	cout << twoTwo(arr2, 3) << endl;// should be  true
	cout << twoTwo(arr3, 4) << endl;// should be  false
	cout << twoTwo(arr4, 3) << endl;// should be  true
	cout << twoTwo(arr5, 5) << endl;// should be  true
	cout << twoTwo(arr6, 5) << endl;// should be  false
	cout << twoTwo(arr7, 2) << endl;//should be  true
	cout << twoTwo(arr8, 5) << endl;//should be  true
	cout << twoTwo(arr9, 5) << endl;//should be  false
	cout << twoTwo(arr10, 4) << endl;// should be  true
	cout << twoTwo(arr11, 3) << endl;//should be  true
	cout << twoTwo(arr12, 2) << endl;// should be  false
	cout << twoTwo(arr13, 1) << endl;// should be  false
	cout << twoTwo(arr14, 1) << endl;//should be  true
	cout << twoTwo({}, 0) << endl;//should be  true
	cout << twoTwo(arr16, 4) << endl;// should be  true
	cout << twoTwo(arr17, 4) << endl;// should be  false

}