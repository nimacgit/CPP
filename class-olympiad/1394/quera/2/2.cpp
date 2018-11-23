#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#include<string>


using namespace std;

typedef pair<int, int> pie;

int n, q;
string s[1000], inf[1000];
bool can[1000];
int co = 0;
int dif = 0;


int f(int a)
{
	for(int i = 0; i < n; i++)
		if(s[i] == inf[a])
			return i;
}

int main()
{
	cin >> n;
	getline(cin, s[0]);
	for(int i = 0; i < n; i++)
		getline(cin, s[i]);
	cin >> q;
	getline(cin, inf[0]);
	for(int i = 0; i < q; i++)
		getline(cin, inf[i]);
	memset(can, 0, sizeof can);
	for(int i = 0; i < q; i++)
	{
		int c = f(i);
		if(!can[c])
		{
			if(dif == n - 1)
			{
				dif = 1;
				memset(can, 0, sizeof can);
				can[c] = true;
				co++;
			}
			else
			{
				dif++;
				can[c] = true;
			}
		}
	}
	cout << co << endl;
}
