#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<algorithm>
#include<chrono>

using namespace std;
using namespace std:: chrono;
#define N 4

int main()
{
	int A[N][N], B[N][N], c[N][N], ch;
	for(int i= 0; i< N; i++)
	{
		for(int j= 0; j< N; j++)
		{
			A[i][j]= (rand()% 10);
			B[i][j]= (rand()% 10);
		}
	}

	cout<< "\n Matrix A: \n ";
	for(int i= 0; i< N; i++)
	{
		for(int j= 0; j< N; j++)
		{
			cout<< A[i][j]<< "\t";
		}
		cout<< endl;
	}
	
	cout<< "\n Matrix B: \n ";
	for(int i= 0; i< N; i++)
	{
		for(int j= 0; j< N; j++)
		{
			cout<< B[i][j]<< "\t";
		}
		cout<< endl;
	}

	do
	{
		cout<< "\n ---------------------------------------------\n";
		cout<< "\t\t MATRIX MAULTIPLICATION";
		cout<< "\n ---------------------------------------------\n";
		cout<< "Enter choice: \n 1. Multiply matrices parallelly\n 2. Multiply matrices sequentially \n 0. Exit: \t";
		cin>> ch;
		
		switch(ch)
		{
			case 0: 
				exit(0);
				break;
				
			case 1: 
			{
				cout<< "\n Matrix multiplication:\n";
				printf("Max number of threads: %i \n", omp_get_max_threads());
				#pragma omp parallel
				#pragma omp single
				{
					printf("Number of threads: %i \n", omp_get_num_threads());
				}
				auto startp= high_resolution_clock:: now();
				int j, k;
				#pragma omp parallel for private(k, j)
				for(int i= 0; i< N; i++)
				{
					for(int j= 0; j< N; j++)
					{
						c[i][j]= 0;
						for(int k= 0; k< N; k++)
						{
							c[i][j]+= A[i][k]* B[k][j];
						}
					}
				}
				auto stopp= high_resolution_clock:: now();
				auto durationp= duration_cast<nanoseconds>(stopp- startp);
				
			//	cout<< "\n Matrix A: \n ";
				for(int i= 0; i< N; i++)
				{
					for(int j= 0; j< N; j++)
					{
						cout<< c[i][j]<< "\t";
					}
					cout<< endl;
				}
				cout<< "\n Time taken to multiply matrices parallely is "<< durationp. count()<< " ns";
				break;
			}
				
			case 2: 
			{
				cout<< "\n Matrix multiplication:\n";
				auto start= high_resolution_clock:: now();
				for(int i= 0; i< N; i++)
				{
					for(int j= 0; j< N; j++)
					{
						c[i][j]= 0;
						for(int k= 0; k< N; k++)
						{
							c[i][j]+= A[i][k]* B[k][j];
						}
					}
				}
				auto stop= high_resolution_clock:: now();
				auto duration= duration_cast<nanoseconds>(stop- start);
			//	cout<< "\n Matrix A: \n ";
				for(int i= 0; i< N; i++)
				{
					for(int j= 0; j< N; j++)
					{
						cout<< c[i][j]<< "\t";
					}
					cout<< endl;
				}
				cout<< "\n Time taken for sequential execution is "<< duration.count()<< " ns";
				break;
			}
		}
	}while(ch!= 0);

	

}
