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


struct node
{
	node *son1 , *son2;
	int val, pos;
	node(int value,int posi)
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
	int add(const int &value, const int &posi)
	{
		int sum = -1;
		bool iset = false;
		if(head == NULL)
		{
			head = new node(value, posi);
			return sum;
		}
		node *temp = head;
		while(2)
		{
			if(value <= temp->val)
			{
				if(temp->son1 == NULL)
				{
					temp->son1 = new node(value, posi);
					return sum;
				}
				else
					temp = temp->son1;
			}
			else
			{
				if(!iset)
				{
					sum =  posi-1 - temp->pos;
					iset = true;
				}
				if(temp->son2 == NULL)
				{
					temp->son2 = new node(value, posi);
					return sum;
				}
				else
					temp = temp->son2;
			}
		}
	}

};

int n;
const int maxn = 1000 * 100;
int a[maxn + 100];


int main()
{
	cin >> n;
	long long sum = 0;
	bst nima;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		a[n-i-1] = nima.add(a[n - i - 1], i);
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
