#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



using namespace std;




class Node
{
public:
	int value;
	Node *next;
	Node *prev;
};

class linked_list
{
public:
	Node *head;
	Node *end;
	Node *pos;
	int size;
	linked_list()
	{
		pos = NULL;
		head = new Node;
		end = new Node;
		size = 0;
		head->next = end;
		end->prev = head;
		end->next = NULL;
		head->prev = NULL;
	}
	linked_list(int num)
	{
		pos = NULL;
		head = new Node;
		end = new Node;
		size = 0;
		head->next = end;
		end->prev = head;
		end->next = NULL;
		head->prev = NULL;
		if(num == 0)
		{
			Node *n = new Node();
			n->value = num % 10;
			end->prev->next = n;
			n->prev = end->prev;
			end->prev = n;
			n->next = end;
			num /= 10;
			size++;
		}
		while(num)
		{
			Node *n = new Node();
			n->value = num % 10;
			end->prev->next = n;
			n->prev = end->prev;
			end->prev = n;
			n->next = end;
			num /= 10;
			size++;
		}
	}
	void add_head(int num)
	{
		Node *n = new Node();
		n->value = num;
		head->next->prev = n;
		n->next = head->next;
		head->next = n;
		n->prev = head;
		size++;
	}
	void add_back(int num)
	{
		Node *n = new Node();
		n->value = num;
		end->prev->next = n;
		n->prev = end->prev;
		end->prev = n;
		n->next = end;
		size++;
	}
};


long long n, h, num;
linked_list Nima;



int main()
{
	cin >> n >> h;
	h++;
	num = h * h;
	int C = h;
	Nima.add_back(num);
	num += C;
	while(num <= n)
	{
		Nima.add_head(num);
		num += C;
		if(num <= n)
			Nima.add_back(num);
		C++;
		num += C;
	}
	Nima.pos = Nima.head;
	Nima.pos = Nima.pos->next;
	while(Nima.pos != Nima.end)
	{
		cout << Nima.pos->value << " ";
		Nima.pos = Nima.pos->next;
	}
	cout << endl;
	
}