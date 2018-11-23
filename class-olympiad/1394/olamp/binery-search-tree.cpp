#include <iostream>

using namespace std;

class Node
{
public:
	Node *son1, *son2, *parent;
	int sum1, sum2;
	int value;
	Node(Node *s1, Node *s2, Node *p, int val)
	{
		son1 = s1;
		son2 = s2;
		parent = p;
		value = val;
		sum1 = 0;
		sum2 = 0;
	}
	Node()
	{
		son1 = NULL;
		son2 = NULL;
		parent = NULL;
		sum1 = 0;
		sum2 = 0;
	}
	void cp(Node *p)
	{
		parent = p;
	}
	void cs1(Node *s1)
	{
		son1 = s1;
	}
	void cs2(Node *s2)
	{
		son2 = s2;
	}
	void setv(int val)
	{
		value = val;
	}

};

class bst
{
public:
	Node *head;
	int size;
	Node *irt;
	bst(){
		head = NULL;
		size = 0;
	};



	void add(int val){
		bool flag = true;
		size++;
		Node *temp;
		if(head == NULL)
		{
			head = new Node(NULL,NULL,NULL,val);
		}
		else
		{
			temp = head;
			while(flag){
				if(val < temp->value)
				{
					if(temp->son1 == NULL)
						flag = false;
					else
					{
						temp->sum1++;
						temp = temp->son1;
					}
				}
				else
				{
					if(temp->son2 == NULL)
						flag =false;
					else
					{
						temp->sum2++;
						temp = temp->son2;
					}
				}
			}
			if(val < temp->value)
			{
				temp->sum1++;
				temp->son1 = new Node(NULL, NULL, temp, val);
			}
			else
			{	
				temp->sum2++;
				temp->son2 = new Node(NULL, NULL, temp, val);
			}
		}
	}



	void remove(int a)
	{
		size--;
		Node *pos = search(a);
		Node *temp = pos;
		while(temp->parent != NULL)
		{
			if(temp-> value > temp->parent->value)
				temp->parent->sum2--;
			else
				temp->parent->sum1--;
			temp = temp->parent;
		}
		if(size == 0)
		{
			head->son1 = NULL;
			head->son2 = NULL;
			head = NULL;
			return;
		}
		if((pos->son1 == NULL) && (pos->son2 == NULL))
		{
				if(pos->value > pos->parent->value)
					pos->parent->son2 = NULL;
				else
					pos->parent->son1 = NULL;
				return;
		}
		Node *npos;
		if(pos->son2 != NULL)
		{
			pos->sum2--;
			npos = pos->son2;
			while(npos->son1 != NULL)
			{
				npos = npos->son1;
			}
			if(npos->son2 != NULL)
			{
				if(npos->value > npos->parent->value)
				{	
					npos->parent->son2 = npos->son2;
					npos->son2->parent = npos->parent;
				}
				else
				{
					npos->parent->son1 = NULL;
				}
			}
			else
			{
				if(npos->value > npos->parent->value)
					npos->parent->son2 = NULL;
				else
					npos->parent->son1 = NULL;
			}
			pos->value = npos->value;
		}
		else
		{
			pos->sum1--;
			npos = pos->son1;
			while(npos->son2 != NULL)
			{
				npos = npos->son2;
			}
			if(npos->son1 != NULL)
			{
				if(npos->value > npos->parent->value)
				{	
					npos->parent->son2 = npos->son2;
					npos->son2->parent = npos->parent;
				}
				else
					npos->parent->son1 = NULL;
			}
			else
			{
				if(npos->value > npos->parent->value)
					npos->parent->son2 = NULL;
				else
					npos->parent->son1 = NULL;
			}
			pos->value = npos->value;
		}
	}



	Node* search(int a)
	{
		Node* pos;
		pos = head;
		while(pos != NULL)
		{
			if(a == pos->value)
				return pos;
			if(a < pos->value)
				pos = pos->son1;
			else
				pos = pos->son2;
		}
		return NULL;
	}



	int get_min()
	{
		Node *pos =new Node;
		pos = head;
		while(pos != NULL)
		{
			pos = pos->son1;
		}
		pos->parent->value;
	}



	int fetch(int a)
	{
		Node *temp = head;
		int sum = temp->sum1;
		if(a > size)
		{
			return -1;
		}
		while(2)
		{
			if(sum + 1 == a)
				return temp->value;
			if(sum < a)
			{
				sum += temp->son2->sum1 + 1;
				temp = temp->son2;
			}
			else
			{
				sum -= (1 + temp->son1->sum2);
				temp = temp->son1;
			}
		}
	}

	int next(Node *a)
	{
		if(a->son2 == NULL)
		{
			if(a == head)
				return head->value;
			return next(a->parent);
		}
		else
		{
			a = a->son2;
			while(a->son1 != NULL)
				a = a->son1;
			return a->value;
		}
	}


	void read(Node *a)
	{
		if(a != NULL)
		{
			cout << a->value << endl;
			if(a->son1 != NULL)
				read(a->son1);
			if(a->son2 != NULL)
				read(a->son2);
		}
	}
	
};



int main()
{
	int n;
	cin >> n;
	bst a;
	for(int i = 0, temp; i < n; i++)
	{
		cin >> temp;
		a.add(temp);
	}
	cout << a.next(a.head->son2->son1) << endl;

}