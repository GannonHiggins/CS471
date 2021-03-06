//Gannon Higgins
//CS471 Assignment 1
//8/30/2012

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cstdio>
#include "doctest.h"
#include "sort.hpp"

int size_int = sizeof(int); // Size of int value, ued to calculate the size of arrays

/* 
Preconditions: 
	Arrays must contain only elements of type Int.
	n must be equal to the size of the array.


Postcondition: 
	Function will check each element of the array 
	and make sure that it is ordered from least to greatest value
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
void print_array(int arr[],int n){
	for(int i =0; i<n; i++){
		std::cout<<arr[i]<<" ";
	}
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
	quicksort(arr2,0,n3-1);

	CHECK(CheckSorted(arr,n1) == true);
	CHECK(CheckSorted(arr1,n2) == true);
	CHECK(CheckSorted(arr2,n3) == true);

}

TEST_CASE("Sorted Arrays"){
	int arr[]= {1,2,3,4,5,6};
	quicksort(arr,0,(sizeof(arr)/size_int)-1);

	int arr1[] = {10,50,60,70,80,90,99,100,101};
	quicksort(arr1,0,(sizeof(arr1)/size_int)-1);

	int arr2[] = {0,10,88,99,100};
	quicksort(arr2,10,(sizeof(arr2)/size_int)-1);



	CHECK(CheckSorted(arr,sizeof(arr)/size_int) == true);
	CHECK(CheckSorted(arr1,sizeof(arr1)/size_int) == true);
	CHECK(CheckSorted(arr2,sizeof(arr2)/size_int) == true);

}

TEST_CASE("Arrays of size 1"){
	int arr[]= {1};
	int array_size = sizeof(arr)/size_int;
	quicksort(arr,0,array_size);
	
	int arr1[] = {10};
	quicksort(arr1,0,array_size);

	int arr2[] = {0};
	quicksort(arr2,0,array_size);

	int arr3[] = {100};
	quicksort(arr3,0,array_size);

	CHECK(CheckSorted(arr,1) == true);
	CHECK(CheckSorted(arr1,1) == true);
	CHECK(CheckSorted(arr2,1) == true);
	CHECK(CheckSorted(arr3,1) == true);

}

TEST_CASE("Arrays that contain negative Values"){

	int arr[] = {3,5,-4,6,7,-1};
	int n = sizeof(arr)/size_int;
	quicksort(arr,0,n-1);

	int arr1[] = {3,8,-9,2,4};
	int n1 = sizeof(arr1)/size_int;
	quicksort(arr1,0,n1-1);

	int arr2[] = {-3,-8,-9,-2,-4,-10};
	int n2 = sizeof(arr2)/size_int;
	quicksort(arr2,0,n2-1);

	CHECK(CheckSorted(arr,n) == true);
	CHECK(CheckSorted(arr1,n1) == true);
	CHECK(CheckSorted(arr2,n2) == true);
}
