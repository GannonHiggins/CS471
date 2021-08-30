#include <algorithm>
#include <iostream>
/*
Functions to sort Vectors of Integers

Precondition:
A =  MUST be a Vector of Integers
lo = Mst be a Value lower than the hi value of the hi value and must be greater than zero 
hi = Must be a values higher than lo and be greater than zero 
*/


int partition(int arr[], int lo, int hi){

	int pivot = arr[hi];

	int i = (lo -1);

	for(int j = lo; j <= hi - 1; j++){
		if(arr[j] <= pivot){
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[hi]);
	return (i+1);
}

void quicksort(int arr[], int lo, int hi){
	if(lo < hi){

		int pi = partition(arr,lo,hi);

		quicksort(arr,lo,pi - 1);
		quicksort(arr, pi + 1, hi);
	}
}

