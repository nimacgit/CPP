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

const int maxn = 250;
int n, k;
int a[maxn + 100];
linked_list d[maxn + 100][maxn + 100];






void dynamic()
{
	unsigned long long sum = 1;
	d[0][0] = 1;
	d[0][1] = a[0];
	for(int i = 2; i <= k; i++)
		d[0][i] = 0;
	for(int i = 1; i < n; i++)
	{
		d[i][0] = 1;
		for(int j = max(1, i - (n - k - 1)); j <= k; j++)
		{
			d[i][j] = d[i - 1][j];
			//cerr << " test +=  " <<  i << "  " << j << " d =  " << d[i][j] << endl;
			if(a[i] >= j)
				d[i][j] += (d[i - 1][j - 1] * (a[i] - j + 1));
			//cerr << " countinu  " << d[i][j] << endl;
		}
	}
}


int main()
{
	scanf("%d %d", &n, &k);
	for(unsigned long long i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	dynamic();
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= k; j++)
			cerr << d[i][j] << " ";
		cerr << endl;
	}
	*/
	if(d[n - 1][k].size == 0)
		cout << 0 << endl;
	else
		print(d[n - 1][k]);

	
}