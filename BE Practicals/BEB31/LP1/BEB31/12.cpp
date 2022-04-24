#include<iostream>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std:: chrono;

int main()
{
//	int r= 3, c= 2;
	int mat[3][2], vec[2], mul[3], ch;
	
	//Create matrix 
	for(int i= 0; i< 3; i++)
	{
		for(int j= 0; j< 2; j++)	
		{
			mat[i][j]= 1;

		}
	}
	
	//Display Matrix:
	cout<< "Matrix is: \n";
	for(int i= 0; i< 3; i++)
	{
		for(int j= 0; j< 2; j++)	
		{
			cout<< mat[i][j]<< "\t";
		}
		cout<< endl;
	}	
	
	//Column vector :
	for(int i= 0; i<2; i++)
	{
		vec[i]= 2;
	}
	
	//Display vector:
	cout<< "\nVector is: \n";
	for(int i= 0; i< 2; i++)
	{
		cout<< vec[i]<< "\n";
	}
	
	do
	{
		cout<< "--------------------------------------------------------\n";
		cout<< "\t\t MATRIX AND VECTOR MULTIPLICATION\n";
		cout<< "\n--------------------------------------------------------\n";
		cout<< "Select choice: \n 1. Sequential multiplication \n 2. Parallel Multiplication \n 0. Exit: \t";
		cin>> ch;
		
		switch(ch)
		{
			case 0: 
			{
				exit(0);
				break;
			}
			case 1: 
			{
				auto start= high_resolution_clock:: now();
				cout<< "\n Time count started...........\n";
				for(int i= 0; i< 3; i++)	
				{
					mul[i]= 0;
					for(int j= 0; j< 2; j++)
					{
						mul[i]+= mat[i][j]* vec[j];
					}
				}
				auto stop= high_resolution_clock:: now();
				cout<< "\n Time count stopped...........\n";
				auto duration= duration_cast<nanoseconds>(stop- start);
				cout<< "\nTime taken by sequential multiplication: "<< duration.count()<< " ns"<< endl;
				//Display multiplication:
				cout<< "\nMultiplication is: \n";
				for(int i= 0; i< 3; i++)
				{
					cout<< mul[i]<< "\n";
				}
				break;
			}
			
			case 2: 
			{	//Multiplication:
				auto startp= high_resolution_clock:: now();
				cout<< "\n Time count started..........\n";
				#pragma omp parallel for
				for(int i= 0; i< 3; i++)	
				{
					mul[i]= 0;
					for(int j= 0; j< 2; j++)
					{
						mul[i]+= mat[i][j]* vec[j];
					}
				}
				auto stopd= high_resolution_clock:: now();
				cout<< "\n Time count stopped.\n";
				auto durationp= duration_cast<nanoseconds>(stopd- startp);
				cout<< "Time taken by parallel ultiplication is "<< durationp.count()<< " ns";
				//Display multiplication:
				cout<< "\nMultiplication is: \n";
				for(int i= 0; i< 3; i++)
				{
					cout<< mul[i]<< "\n";
				}
				break;
			}
		}
	}while(ch!= 0);
}

/*
OUTPUT:
pozzo@pozzo-VirtualBox:~/Documents/LP1Me$ g++ 12.cpp
pozzo@pozzo-VirtualBox:~/Documents/LP1Me$ ./a.out
Matrix is: 
1	1	
1	1	
1	1	

Vector is: 
2
2
--------------------------------------------------------
		 MATRIX AND VECTOR MULTIPLICATION

--------------------------------------------------------
Select choice: 
 1. Sequential multiplication 
 2. Parallel Multiplication 
 0. Exit: 	1

 Time count started...........

 Time count stopped...........

Time taken by sequential multiplication: 14875 ns

Multiplication is: 
4
4
4
--------------------------------------------------------
		 MATRIX AND VECTOR MULTIPLICATION

--------------------------------------------------------
Select choice: 
 1. Sequential multiplication 
 2. Parallel Multiplication 
 0. Exit: 	2

 Time count started..........

 Time count stopped.
Time taken by parallel ultiplication is 14498 ns
Multiplication is: 
4
4
4
--------------------------------------------------------
		 MATRIX AND VECTOR MULTIPLICATION

--------------------------------------------------------
Select choice: 
 1. Sequential multiplication 
 2. Parallel Multiplication 
 0. Exit: 	0
pozzo@pozzo-VirtualBox:~/Documents/LP1Me$ 

*/
