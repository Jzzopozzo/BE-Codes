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

int binarySearch(int *a, int low, int high, int key)
{
	int mid;	
	mid=(low+high)/2;
	int low1,low2,high1,high2,mid1,mid2,found=0,loc=-1;

	#pragma omp parallel sections
	{
	    #pragma omp section
    	{ 
			low1=low;
			high1=mid;
			
			while(low1<=high1)
			{
				if(!(key>=a[low1] && key<=a[high1]))
				{
					low1=low1+high1;
					continue;
				}
				
				mid1=(low1+high1)/2;
				
				if(key==a[mid1])
				{
					found=1;
					loc=mid1;
					low1=high1+1;
				}
				else if(key>a[mid1])
				{

					low1=mid1+1;
				}
				
				else if(key<a[mid1])
					high1=mid1-1;
			
			}
		}
				   			
			#pragma omp section
    		{ 
      		low2=mid+1;
			high2=high;
			while(low2<=high2)
			{
				if(!(key>=a[low2] && key<=a[high2]))
				{
					low2=low2+high2;
					continue;
				}
				
				
				mid2=(low2+high2)/2;
				
				if(key==a[mid2])
				{

					found=1;
					loc=mid2;
					low2=high2+1;	
				}									
				else if(key>a[mid2])
				{

				low2=mid2+1;
				}
				else if(key<a[mid2])
				high2=mid2-1;

			}	
    		}
	}
	return loc;
}

// Driver program to test above functions 
int main() 
{ 
	int a[10], loc;
	int n, search; 
	cout<<"\n---------------------------------";
	cout<<"\n\t  BINARY SORT";	
	cout<<"\n---------------------------------";
	
	cout<<"\nEnter size of array:\t";
	cin>>n;
	cout<<"Enter elements of array:";
	for(int i= 0; i< n; i++)
	{
		cin>> a[i];
	}
	oddEven(a, n);
	printArray(a, n);
	cout<<"\nEnter key to be found out:\t";
	cin>>search;
	binarySearch(a, 0, n, search);
	
	loc=binarySearch(a, 0, n-1, search);
	
	if(loc==-1)
		cout<<"\n\n Key not found.";

	else
		cout<<"\n\nKey found at position: "<<loc<<"\n\n";
	
	
} 
