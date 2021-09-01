//Gannon Higgins
//CS471 Assignment 1
//8/30/2012

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cstdio>
#include "doctest.h"
#include "sort.hpp"

int size_int = sizeof(int); // Size of int value, ued to calculate the size of arrays

/* 
This function cheack each element at position n-1 and makes sure it is smaller than 
position n. 
returns True if all elements at position n-1 are smaller than n
returns false if otherwise. 


Preconditions: 
	Arrays must be of Ints and must cuntain at least 1 values within the array
	second value must be the Size of the array.
*/
bool CheckSorted(int arr[],int n){

	if(n == 0 || n == 1) {
		return true;
	}

	for (int i =1; i < n; i++){
		if(arr[i-1] > arr[i]){
			return false;
		}
	}
	return true;
}


TEST_CASE("Unsorted arrays"){

	int arr[] = {3,5,4,6,7,1};
	int n1 = sizeof(arr)/size_int;
	quicksort(arr,0,n1-1);

	int arr1[] = {3,8,9,2,4};
	int n2 = sizeof(arr1)/size_int;
	quicksort(arr1,0,n2-1);

	//Third test will not use quicksort
	// to verify that the arrays are sorted properly
	int arr2[] = {3,8,9,2,4,10};
	int n3 = sizeof(arr2)/size_int;

	CHECK(CheckSorted(arr,n1) == true);
	CHECK(CheckSorted(arr1,n2) == true);
	CHECK(CheckSorted(arr2,n3) == false);

}

TEST_CASE("Sorted Arrays"){
	int arr[]= {1,2,3,4,5,6};
	quicksort(arr,1,6);

	int arr1[] = {10,50,60,70,80,90};
	quicksort(arr1,0,sizeof(arr1)/size_int);

	int arr2[] = {0,10,88,99,100};
	quicksort(arr2,10,sizeof(arr2)/size_int);



	CHECK(CheckSorted(arr,sizeof(arr)/size_int) == true);
	CHECK(CheckSorted(arr1,sizeof(arr1)/size_int) == true);
	CHECK(CheckSorted(arr2,sizeof(arr2)/size_int) == true);

}

TEST_CASE("Arrays of size 1"){
	int arr[]= {1};
	quicksort(arr,0,sizeof(arr)/size_int);
	
	int arr1[] = {10};
	quicksort(arr1,0,sizeof(arr1)/size_int);

	int arr2[] = {0};
	quicksort(arr2,0,sizeof(arr2)/size_int);

	int arr3[] = {100};
	quicksort(arr3,0,sizeof(arr3)/size_int);

	CHECK(CheckSorted(arr,sizeof(arr)/size_int) == true);
	CHECK(CheckSorted(arr1,sizeof(arr)/size_int) == true);
	CHECK(CheckSorted(arr2,sizeof(arr)/size_int) == true);
	CHECK(CheckSorted(arr3,sizeof(arr)/size_int) == true);

}
