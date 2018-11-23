#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
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




ostream & operator << (ostream & out, linked_list &a){
	a.pos = a.end->prev;
	for(int i = 0; i < a.size; i++)
	{
		out << a.pos->value;
		a.pos = a.pos->prev;
	}
	return out;
}





linked_list operator +(linked_list  &first,linked_list &second)
{
	linked_list sum;
	int baghi = 0;
	first.pos = first.head->next;
	second.pos = second.head->next;
	int i = 0;
	for(; i < min(first.size, second.size); i++)
	{
		baghi += first.pos->value;
		baghi += second.pos->value;
		first.pos = first.pos->next;
		second.pos = second.pos->next;
		sum.add_back(baghi % 10);
		baghi /= 10;
	}
	for(int j = i; j < first.size; j++)
	{
		baghi += first.pos->value;
		first.pos = first.pos->next;
		sum.add_back(baghi % 10);
		baghi /= 10;
	}
	for(int j = i; j < second.size; j++)
	{
		baghi += second.pos->value;
		second.pos = second.pos->next;
		sum.add_back(baghi % 10);
		baghi /= 10;
	}
	while(baghi > 0)
	{
		sum.add_back(baghi % 10);
		baghi /= 10;		
	}
	//cerr << " test +  " <<  first << "  " << second << " sum =   " << sum << endl;
	return sum;
}



linked_list operator *(linked_list &first, int num)
{
	linked_list sum;
	int baghi = 0;
	first.pos = first.head->next;
	int i = 0;
	for(; i < first.size; i++)
	{
		baghi += first.pos->value * num;
		first.pos = first.pos->next;
		sum.add_back(baghi % 10);
		baghi /= 10;
	}
	while(baghi > 0)
	{
		sum.add_back(baghi % 10);
		baghi /= 10;	
	}
	//cerr << " test *  " <<  first << "  " << num << "  sum =  " << sum << endl;
	return sum;
}



void operator +=(linked_list &first, linked_list second)
{
	first = first + second;
}


void print(linked_list &num)
{
	num.pos = num.end->prev;
	for(int i = 0; i < num.size; i++)
	{
		printf("%d", num.pos->value);
		num.pos = num.pos->prev;
	}
}



int main()
{

}