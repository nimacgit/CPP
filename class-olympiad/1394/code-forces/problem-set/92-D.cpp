#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;

int n;
const int maxn = 1000 * 100;
int a[maxn + 100];
int d[maxn + 100];
int par[maxn + 100];
struct node
{
	node *son1 , *son2;
	int val, pos;
	node(const int &value,const int &posi)
	{
		son1 = son2 = NULL;
		val = value;
		pos = posi;
	}

};

struct bst
{
	node *head;
	bst()
	{
		head = NULL;
	}
	void add(int value,int posi)
	{
		d[posi] = -1;
		par[posi] = -1;
		if(head == NULL)
		{
			head = new node(value, posi);
			return;
		}
		node *temp = head;
		while(true)
		{
			if(value < temp->val)
			{
				d[temp->pos] = posi - temp->pos - 1;
				if(temp->son1 == NULL)
				{
					temp->son1 = new node(value, posi);
					return;
				}
				else
					temp = temp->son1;
			}
			else
			{
				par[posi] = temp->pos;
				if(temp->son2 == NULL)
				{
					temp->son2 = new node(value, posi);
					return;
				}
				else
					temp = temp->son2;
			}
		}
	}
};


int main()
{
	cin >> n;
	long long sum = 0;
	bst nima;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		nima.add(a[i], i);
	}
	for(int i = 0; i < n; i++)
	{
		if(par[i] != -1)
			printf("%d ", d[i] = max(d[i], (d[par[i]] - i + par[i])));
		else 
			printf("%d ", d[i]);
	}
	printf("\n");
}
