// Joesephous.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;


class node
{
	int data;
	node *next;
public:
	node(int x, node *n)
	{
		next = n;
		data = x;
	}
	friend class CircularLinkList;
};

class CircularLinkList
{
public:
	/*CircularLinkList()
	{
		Head = new node(1, NULL);
	}*/

	/*void Delete(node *p),int position)
	{
		node *n = Head;
		if (n != NULL)
			do
			{
				if (n->next->data != position)
				{
					node *temp = p->next;
					p->next = p->next->next;
					delete temp;
				} 
				n = n->next;
			} while (n->next != Head && n != Head);
	}*/

	/*int GetSafePosition(int n, int k = 2)
		int GetSafePosition(node *Head, int n)
	{
		if (n == 1)
			return 1;
		else
			return ((GetSafePosition(n - 1, k) + k - 1) % n) + 1;
	}*/

	node *Position(node *Head)
	{
		node *p = Head;
		while (p->next != p)
		{
			node *temp = p->next;
			p->next = p->next->next;
			delete temp;	
			if (p->next == Head)
			{
				cout << endl << "----------------------------------------------------The Remaining Ring---------------------------------------------------" << endl << endl;
				Print(p->next);		
			}
			p = p->next;
		}
		return p;
	}

	void SetData(node *Head, int n)
	{
		node *H = Head;
		for (int i = 1; i < n; i++)
		{
			node *n = new node(i + 1, Head);
			H->next = n;
			H = H->next;
		}
	}

	void Print(node *Head)//چاپ لیست
	{
		node *n = Head;
		int i = 1;
		if (n != NULL)
			do{
				cout << n->data << " ";
				n = n->next;
				if (i % 30 == 0)
					cout << endl << endl;
				i++;
			} while (n != Head);
		else
			cout << "Not found item! ):";
	}
};


void main()
{
	CircularLinkList CLL;
	node *n = new node(1, NULL);
	int NumOfList;
	cout << "Please enter numbers of circular link list: ";
	cin >> NumOfList;
	CLL.SetData(n, NumOfList);
	cout << endl << "-----------------------------------------------This is circular linked list----------------------------------------------" << endl << endl;
	CLL.Print(n);
	//cout << endl << "-----------------------------------------------------------End-----------------------------------------------------------" << endl << endl;
	n = CLL.Position(n);
	cout << endl << "-----------------------------------------------------------End-----------------------------------------------------------" << endl << endl;
	cout << "The ";
	CLL.Print(n);
	cout << "person survives.";
	_getch();
}