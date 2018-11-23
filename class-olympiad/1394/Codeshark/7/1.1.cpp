#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;


const int maxl = 24;
long long two[maxl];
const int n = 9;
int mo = 32441;
bitset<n> mb;

int main()
{
	mb.set(0);
	two[0] = 1;
	for(int i = 1; i < maxl; i++)
		two[i] = two[i - 1] * 2;
	long long co = 0;
	for(int i = 0; i < two[n]; i++)
	{
		bool flag = true;
		mb.reset();
		mb |= i;
		if(mb[0] == !mb[n - 1] && (mb[1]!= mb[0] || mb[n - 1] != mb[n - 2]))
			flag = false;
		for(int j = 1; j < n - 1; j++)
			if(mb[j - 1] != mb[j] && mb[j] != mb[j + 1])
				flag = false;
		if(flag)
		{
			co++;
		}
	}
	cout << co<< endl;

}
