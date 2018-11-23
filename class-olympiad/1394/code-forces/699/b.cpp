#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1100;
int ib[maxn], jb[maxn];
int n, m, ico = 0, jco = 0;
string s;
vector<pie> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		for(int j = 0; j < m; j++)
		{
			if(s[j] == '*')
			{
				ib[i]++;
				jb[j]++;
				p.push_back(mp(i, j));
			}
		}
	}
	bool flagi = false, flagj = false;
	int posi = 0, posj = 0;
	for(int i = 0; i < n; i++)
	{
		if(ib[i] >= 2)
		{
			if(!flagi)
			{
				flagi = true;
				posi = i;
			}
			else
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	for(int j = 0; j < m; j++)
	{
	
		if(jb[j] >= 2)
		{
			if(!flagj)
			{
				posj = j;
				flagj = true;
			}
			else
			{
				cout << "NO" << endl;
				return 0;
			}

		}
	}
	if(flagi && flagj)
	{
		for(auto x : p)
		{
			if((x.F != posi) && (x.S != posj))
			{
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;
		cout << posi + 1 << " " << posj + 1 << endl;
	}
	else if(flagi)
	{
		int co = 0;
		for(auto x : p)
		{
			if(x.F != posi)
			{
				co++;
				if(co >= 2)
				{
					cout << "NO" << endl;
					return 0;
				}
				posj = x.S;
			}
		}	
		cout << "YES" << endl;
		cout << posi + 1 << " " << posj + 1 << endl;
	}
	else if(flagj)
	{
		int co = 0;
		for(auto x : p)
		{
			if(x.S != posj)
			{
				co++;
				if(co >= 2)
				{
					cout << "NO" << endl;
					return 0;
				}
				posi = x.F;
			}
		}	
		cout << "YES" << endl;
		cout << posi + 1 << " " << posj + 1 << endl;
	}
	else
	{
		if(p.size() == 1)
			cout << "YES" << endl << p[0].F + 1 << " " << p[0].S + 1 << endl;
		else
		{
			if(p.size() == 2)
				cout << "YES" << endl << p[0].F + 1 << " " << p[1].S + 1 << endl;
			else
				if(p.size() == 0)
					cout << "YES" << endl << "1 1" << endl;
				else
					cout << "NO" << endl;
		}
	}
}
