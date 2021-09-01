#include <cstdio>
#include "doctest.h"
#include "sort.hpp"

void printArray(int arr[], int size){
	for (int i=0;i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {

	int arr[] = {4,2,3,1,0,5,10};

	int n = sizeof(arr)/sizeof(arr[0]);

	quicksort(arr,0,n-1);
	printf("Sorted array: \n");
	printArray(arr,n);
	return 0; 
}