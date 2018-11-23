#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, pair<int,int> > pie;
const int maxn =  500;
int n;
int a[maxn + 100];
vector<pie> pals;

bool ispal(int i, int j)
{
	while(i < j)
	{
		if(a[i] != a[j])
			return false;
		i++;j--;
	}
	return true;
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
	{
		int l = i;
		int j = i + 1;
		while(j < n)
		{
			if(ispal(i, j))
				l = j;
			j++;
		}
		pals.push_back(mp(i,l));
		i = l;
	}
	int com = 0;
	for(int i = 0; i < pals.size() - com; i++)
	{
		int maxpal = i;
		for(int j = i + 1; j < pals.size(); j++)
		{
			
		}
	}
}
