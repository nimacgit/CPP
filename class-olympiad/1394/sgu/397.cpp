#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string s;

class Node
{
public:
	char value;
	Node *next;
	Node *prev;
};

class linked_list
{
public:
	Node *head;
	Node *end;
	Node *pointer;
	int size;
	linked_list()
	{
		head = new Node;
		end = new Node;
		pointer = new Node;
		pointer->next = end;
		pointer->prev = head;
		size = 0;
		head->next = end;
		end->prev = head;
		end->next = NULL;
		head->prev = NULL;
	}
	void add(char val)
	{
		Node *n = new Node;
		if(size == 0)
		{
			head->next = n;
			end->prev = n;
			n->prev = head;
			n->next = end; 
			n->value = val;
			pointer->next = n;
		}
		else
		{
			n->prev = pointer->prev;
			n->next = pointer->next;
			pointer->prev->next = n;
			pointer->next->prev = n;
			pointer->next = n;
			n->value = val;
		}
		size++;
	}
	void read(int pos)
	{
		if(pos < size + 1)
		{
			for(int i = 0; i < pos ; i++)
			{
				printf("%c", pointer->next->value) ;
				pointer->next = pointer->next->next;
			}
		}
	}

};


int main()
{
	cin >> s;
	linked_list v;
	int pos = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == 'L')
		{
			if(pos > 0)
			{
				v.pointer->next = v.pointer->prev;
				v.pointer->prev = v.pointer->prev->prev;
				pos--;
			}
		}
		else
		{
			if(s[i] == 'R')
			{
				if(pos  < v.size)
				{
					pos++;
					v.pointer->prev = v.pointer->next;
					v.pointer->next = v.pointer->next->next;
				}
			}
			else
			{
				v.add(s[i]);
				v.pointer->prev = v.pointer->next;
				v.pointer->next = v.pointer->next->next;
				pos++;
			}
		}
	}
	v.pointer->next = v.head->next;
	v.read(v.size);
	cout << endl;
	
}