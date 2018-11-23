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
	linked_list a;
	int n;
	cin >> n;
	for(int i = 1,temp; i <= n; i++)
	{
		cin >> temp;
		a.add(i,temp);
	}
	a.remove(1);
	for(int i = 1; i <= n; i++)
		cout << a.read(i) << endl;

}

