#include<iostream>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std:: chrono;
#define MAX 10000

int main()
{
	int a[MAX], b[MAX], c[MAX], ch;
	
	cout<< "\n Vector 1: \n";
	#pragma omp parallel for
	for(int i= 0; i< MAX; i++)
	{
		a[i]= rand()% 1000;
	}

	for(int i= 0; i< MAX; i++)
	{
		cout<< a[i] << " ";
	}

	
	cout<< "\n Vector 2: \n";
	#pragma omp parallel for
	for(int i= 0; i< MAX; i++)
	{
		b[i]= rand()% 1000;
	}

	for(int i= 0; i< MAX; i++)
	{
		cout<< b[i] << " ";
	}
	
	do
	{
		cout<<"\n ------------------------------------------------------------";
		cout<< "\n\t\t VECTOR ADDITION";
		cout<<"\n ------------------------------------------------------------\n";
		cout<< "Enter choice:"<< endl<< "1. Add given matrices sequentially"<< endl<< "2. Add given matrices parallelly"<< endl<< "0. Exit: \t";
		cin>> ch;
		cout<<"\n ------------------------------------------------------------\n";
		switch(ch)
		{			
			case 1:
			{
				cout<< "\n Vector Addition:\n";
				auto starts= high_resolution_clock:: now();
				cout<<"\nTime count started............\n";
				for(int i= 0; i< MAX; i++)
				{
					c[i]= a[i]+ b[i];
				}
				auto stops= high_resolution_clock:: now();
				cout<<"\nTime count stopped............\n";
				
				auto durations= duration_cast<microseconds>(stops- starts);
				for(int i= 0; i< MAX; i++)
				{
					cout<< a[i]<< "+ "<< b[i]<< "= "<< c[i] << " "<< endl;
				}
				
				cout<< "Time taken by sequential addition:"<< durations.count()<< " microseconds"<< endl;		
				break;
			}
			case 2:
			{
				cout<< "\n Vector Addition:\n";
				auto start= high_resolution_clock:: now();
				#pragma omp parallel for
				cout<<"\nTime count started............\n";
				for(int i= 0; i< MAX; i++)
				{
					c[i]= a[i]+ b[i];
				}
				auto stop= high_resolution_clock:: now();
				cout<<"\nTime count stopped............\n";
				
				auto duration= duration_cast<microseconds>(stop- start);
				for(int i= 0; i< MAX; i++)
				{
					cout<< a[i]<< "+ "<< b[i]<< "= "<< c[i] << " "<< endl;
				}
				
				cout<< "Time taken by parellel addition:"<< duration.count()<< " microseconds"<< endl;		
				break;
			}	
			case 0:
			{
				exit(0);
				break;
			}
			cout<< "\n=====================================================================\n";
		}
	}while(ch!= 0);
}


/*
Time taken for addition of 10, 000 numbers:
 Sequentially: 86 microseconds 	Parellelly: 39 microseconds
*/
