#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;
int main()
{
	int search;
	int arr[]= {5, 9, 16, 26, 34, 45, 56, 67, 78, 87, 90, 100};
	cout<< "\n Elements of array are:\n";
//	int n = sizeof(arr)/sizeof(arr[0]); 
	int count= sizeof(arr)/sizeof(arr[0]);
	for (int i= 0; i< sizeof(arr); i++)
	{
		cout<< arr[i] << "\t";
	}
	
	cout<< "\n Enter element to be searched:\t";
	cin>> search;
	cout<<sizeof(arr);
}
/*
void binarySearch(int arr[], int key, int n)
{
	int first, last, count, mid;
	first= arr[0];
	last= arr[11];
	mid= (first+ last) / 2;
	
	while(key!= a[mid])
	{
		if(key< a[mid])
		{
			binarySearch(arr, key, mid- 1);
		}
		else if(key== arr[mid])
			return mid;
		else
		{
			binarySearch(arr, key, last);
		}
	}
	for(int i= 0; i< 11; i++)
	{
		
	}
}*/
