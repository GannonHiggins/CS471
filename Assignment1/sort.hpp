//Gannon Higgins
//CS471 Assignment 1
//8/30/2012

#include <algorithm>
#include <iostream>

/* 

function to sort the array using the Lomuto partiton Scheme

Preconditions:
Array bust have at least 1 element and contain only integer values.
lo must be equal to zero.
hi must be the last element of the array.


postconditions:
Functions will that the array and sort 
the values from least to greatest. 

*/

int partition(int arr[], int lo, int hi){

	int pivot = arr[hi];

	int i = (lo - 1);

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

