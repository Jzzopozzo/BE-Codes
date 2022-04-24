#include<bits/stdc++.h>
using namespace std;

struct Record{
	int val;
	double height, weight;
	double distance;
};

bool compare(Record a, Record b)
{
	return (a.distance< b.distance);
}

int classification(Record a[], int n, int k, Record p)
{
	for(int i= 0; i< n; i++)
	{
		a[i]. distance= sqrt((a[i]. height- p. height)* (a[i]. height- p. height) + (a[i]. weight- p. weight)* (a[i]. weight- p. weight));

	}
	
	sort(a, a+ n, compare);	
	
	int cnt1= 0;
	int cnt2= 0;
	
	for(int i= 0; i< k; i++)
	{
		if(a[i].val== 0)
			cnt1++;
		else if(a[i].val== 1)
			cnt2++;
	}
	return (cnt1> cnt2? 0: 1);
}

int main()
{
	int n= 8;
	Record b[n];
	
	b[0]. height= 165;
	b[0]. weight= 120;
	b[0]. val= 1;
	
	b[1]. height= 165;
	b[1]. weight= 40;
	b[1]. val= 1;
	
	b[2]. height= 169;
	b[2]. weight= 60;
	b[2]. val= 0;

	b[3]. height= 190;
	b[3]. weight= 65;
	b[3]. val= 0;

	b[4]. height= 155;
	b[4]. weight= 42;
	b[4]. val= 0;

	b[5]. height= 180;
	b[5]. weight= 80;
	b[5]. val= 1;

	b[6]. height= 160;
	b[6]. weight= 55;
	b[6]. val= 1;

	b[7]. height= 152;
	b[7]. weight= 50;
	b[7]. val= 1;
	
	Record r;
	cout<< "\nEnter height:\t";
	cin>> r.height;
	
	cout<< "\nEnter weight:\t";
	cin>> r.weight;
		
	int k= 3;
	cout<< "\n Value belongs to is "<< classification(b, n, k, r);
	return 0;	
	
	//0: Normal 1: Abnormal
}
