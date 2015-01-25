#include <iostream>
using namespace std;

int countOdds(int array[], int size){
	

	if (size == 0)
		return 0;
	
	int count = 0;
	for (int i = 0; i < size; i++){
		if (array[i] % 2 != 0)
			count++;
	}
	return count;
}

int findMinMultof10(int array[], int size){

	
	if (size == 0)
		return -1;

	int minTen = -1;
	for (int i = 0; i < size; i++){
		
		if (array[i] % 10 == 0){
			if (minTen == -1 || minTen > array[i])
				minTen = array[i];
		}
		
	}
	return minTen;
}


int findLastOddIndex(int array[], int size){

	if (size == 0) 
		return -1;


	
	for (int i = size-1; i>=0; i--){  //since we are trying to find the last odd index, start from the back of the array.
		if (array[i] % 2 != 0)
			return i;
	}

	return -1;

}


bool remove(int array[], int size, int index){ 

	if (size == 0 || index < 0 || index >= size) 
		return false;

	if (index + 1 == size){
		return true; //last index in the array is being removed so no shifting is needed.
	}

	

	for (int i = index; i < size; i++){
		array[i] = array[i + 1];
	}
	return true;
}


