#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cstdio>
#include "doctest.h"
#include "sort.hpp"

int size_int = sizeof(int);

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

	int arr[] = {3,4,5,6,7};
	int n1 = sizeof(arr)/size_int;
	quicksort(arr,0,n1-1);

	int arr1[] = {3,8,9,2,4};
	int n2 = sizeof(arr1)/size_int;
	quicksort(arr1,0,n2-1);

	int arr2[] = {3,8,9,2,4,10};
	int n3 = sizeof(arr2)/size_int;

	CHECK(CheckSorted(arr,n1) == true);
	CHECK(CheckSorted(arr1,n2) == true);
	CHECK(CheckSorted(arr2,n3) == false);

}

TEST_CASE("Sorted Array"){
	int arr[]= {1,2,3,4,5,6};
	int arr1[] = {10,50,60,70,80,90};
	int arr2[] = {0,10,88,99,100};
	int arr3[] = {100,0,5,10,3,2};



	CHECK(CheckSorted(arr,sizeof(arr)/size_int) == true);

}
