#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cstdio>
#include "doctest.h"
#include "sort.hpp"

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
	int n1 = sizeof(arr)/sizeof(arr[0]);
	quicksort(arr,0,n1-1);

	int arr1[] = {3,8,9,2,4};
	int n2 = sizeof(arr1)/sizeof(arr1[0]);
	quicksort(arr1,0,n2-1);

	int arr2[] = {3,8,9,2,4,10};
	int n3 = sizeof(arr2)/sizeof(arr2[0]);

	CHECK(CheckSorted(arr,n1) == true);
	CHECK(CheckSorted(arr1,n2) == true);
	CHECK(CheckSorted(arr2,n3) == false);

}
