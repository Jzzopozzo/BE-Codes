// C program for implementation of Bubble sort 
#include <stdio.h> 
#include<iostream>
#include<stdlib.h>

using namespace std;

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
int i, j; 
for (i = 0; i < n-1; i++)	 

	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

void oddEven(int arr[], int n)
{
	bool isSorted= false;
	while(!isSorted)
	{
		isSorted= true;
		//cout<<"1";	
		#pragma omp parallel for
		for(int i= 1; i<= n-2; i= i+ 2)
		{
		//cout<< "2";
			if(arr[i]> arr[i+ 1])
			{
				swap(arr[i], arr[i+ 1]);
				isSorted= false;
			}
		}
		
		#pragma omp parallel for
		for(int i= 0; i<= n-2; i= i+ 2)
		{
//		cout<<"3";
			if(arr[i]> arr[i+ 1])
			{
				swap(arr[i], arr[i+ 1]);
				isSorted= false;
			}
		}
	}
	return;
	
}

// Driver program to test above functions 
int main() 
{ 
	int arr[] = {44, 94, 55, 29, 22, 11, 58}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout<<"\n---------------------------------";
	cout<<"\n\t  PARALLEL BUBBLE SORT";	
	cout<<"\n---------------------------------";
	
	int menu;
	cout<< "\nChoose operation to be performed:\n 1. Normal Bubble Sort \n 2. Parallel Bubble Sort \n 3. Exit\t:";
	cin>> menu;
	
	switch(menu)
	{
		case 1: bubbleSort(arr, n); 
			printf("\nSorted array: \n"); 
			printArray(arr, n);
			break;
			
		case 2:	oddEven(arr, n);
			printf("\nSorted array: \n"); 
			printArray(arr, n);
			break; 
			
		case 3: exit(0);
			break;
	}
	return 0; 
} 

