#include<stdio.h>
#include<iostream>
using namespace std;

void Input(int arr[], int size)
{
	int i;
	for(i= 0; i< size; i++)
	{
		cin>>arr[i];
	}
}

void Display(int arr[], int size)
{
	int i;
	for(i= 0; i< size; i++)
	{
		cout<<arr[i]<< "\t";
		
	}

}


void swap(int *xp, int *yp)
{
	int temp= *xp;
	*xp= *yp;
	*yp= temp;
}

void bubbleSort(int arr[], int size)
{
	int i, j;
	for(i= 0; i< size- 1; i++)
	{
		for(j= 0; j< size- i- 1; j++)
		{
			if(arr[j]> arr[j+ 1])
				swap(&arr[j], &arr[j+ 1]);
		}
	}
}

void oddEvenSort(int arr[], int n)
{
	bool isSorted= false;
	
	while(!isSorted)
	{
		for(int i= 1; i<= n-2; i= i+ 2)
		{
			if(arr[i]> arr[i+ 1])
			{
				swap(arr[i], arr[i+ 1]);
				isSorted= false;
			}
		}
		
		for(int i= 0; i<= n-2; i= i+ 2)
		{
			if(arr[i]> arr[i+ 1])
			{
				swap(arr[i], arr[i+ 1]);
				isSorted= false;
			}
		}
	}
	return; 
}

int main()
{
	int arr[10];
	int n;
			cout<<"\n---------------------------------";
	cout<<"\n\t BUBBLE SORT";	cout<<"\n---------------------------------";
	cout<<"\nEnter number of array elements:\t";
	cin>>n;
	
	Input(arr, n);
	cout<<"\n Array: ";
	Display(arr, n);
	
	bubbleSort(arr, n);
	cout<< "\n Sorted array:";
	Display(arr, n);
	return 0;
}

