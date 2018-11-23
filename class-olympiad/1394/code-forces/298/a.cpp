#include <iostream>

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
	int size;
	linked_list()
	{
		head = new Node;
		end = new Node;
		size = 0;
		head->next = end;
		end->prev = head;
		end->next = NULL;
		head->prev = NULL;
	}
	void add(int pos, int val)
	{
		Node *n = new Node;
		if(size == 0)
		{
			head->next = n;
			end->prev = n;
			n->prev = head;
			n->next = end; 
			n->value = val;
		}
		else
		{
			n->next = head;
			for(int i = 1; i < pos && i < size + 2; i++)
			{
				n->next = (n->next)->next;
			}
			n->prev = n->next;
			n->value = val;
			n->next = n->next->next;
			n->prev->next = n;
			n->next->prev = n;
		}
		size++;
	}
	int remove(int pos)
	{
		if(pos < size + 1)
		{
			Node *n = new Node;
			n->next = head;
			for(int i = 1; i < pos && size > 0; i++)
			{
				n->next = (n->next)->next;
			}
			n->prev = n->next;
			n->next = n->next->next->next;
			n->prev->next = n->next;
			n->next->prev = n->prev;
			size--;
		}
		else
			return -1;
	}
	int read(int pos)
	{
		if(pos < size + 1)
		{
			Node *n = new Node;
			n->next = head;
			for(int i = 0; i < pos ; i++)
			{
				n->next = (n->next)->next;
			}
			return n->next->value;
		}
		else
			return -1;
	}

};



int main()
{
	int n;
	cin >> n;
	linked_list a;
	a.add(1,1);
	if(n > 2)
		a.add(2,n);
	int r = 3,l = 2;
	bool sign = true;
	if(n == 4)
	{
		cout << "4" << endl;
		cout << "3 1 4 2" << endl;
	}
	else
	{
	if(n > 4)
		for(int i = n - 1; i > 1; i--)
		{
			if(sign)
			{
				a.add(l,i);
				sign = false;
				l++;
				r++;
			}
			else
			{
				a.add(r,i);
				sign = true;
			}
		}
	cout << a.size << endl;
	for(int i = 1; i <= a.size; i++)
		cout << a.read(i) << " " ;
	cout << endl;
}
}