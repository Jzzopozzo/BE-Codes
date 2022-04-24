#include<stdio.h>
#include<iostream>

using namespace std;

class Node
{
	public: 
	Node *L, *R;
	int data;
};

Node *root= NULL;

class BTree
{
	public:
	Node *root= new Node;
	BTree()
	{
		root-> L= NULL;
		root-> R= NULL;
		root-> data= 0;
	}
	Node *createNode(int val);
	void insertNode(int val);
	void inOrder(Node* node);
};

class Queue *createQueue()
{
	
};

Node* createNode(int val)
{
	Node *newNode= new Node;
	newNode-> data= val;
	newNode-> L= NULL;
	newNode-> R= NULL;
	cout<< "Node has been inserted.";
	return newNode;
}

void enQueue()

void insertNode(int val)
{
	Node* newNode= createNode(val);
	if(root== 0)
	{
			root= newNode;
			cout<<"\nRoot has been inserted";
			return;
	}
	else
	{
		if(val< root-> data)
		{
			root-> L= newNode;
			cout<<"\n Inserted on left of Root";
		}
		else
		{
			root-> R= newNode;
			cout<<"\n Inserted on right of Root";
		}
	}
}

void inOrder(Node *node)
{
	if(root== NULL)
	{
		cout<<"\nTree is empty";
		return;
	}
	else
	{
		if(node-> L!= NULL)
		{
			inOrder(node-> L);
		}
		if(node-> R!= NULL)
		{
			inOrder(node-> R);
		}
	}
}

int main()
{
	int val, n;
	cout<< "Enter number of nodes:";
	cin>> n;
	for(int i= 0; i< n; i++)
	{
		cout<< "\n\nEnter value of node:\t"	;
		cin>> val;	
		insertNode(val);
	}
	inOrder(root);
}
