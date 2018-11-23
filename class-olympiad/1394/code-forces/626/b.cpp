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
const int maxn = 500;
int n;
char a[maxn];
int r = 0, g = 0, b = 0;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] == 'R')
			r++;
		else if(a[i] == 'B')
			b++;
		else
			g++;
	}
	if(r == 0)
	{
		if(b == 0)
		{
			cout << 'G' << endl;
		}
		else if(g == 0)
		{
			cout << 'B' << endl;
		}
		else
		{
			if(g == 1)
			{
				if(b == 1)
					cout << 'R' << endl;
				else
					cout << "GR" << endl;
			}
			else if(b == 1)
			{
				cout << "BR" << endl;
			}
			else
			{
				cout << "BGR" << endl;
			}
		}

	}
	else if(b == 0)
	{
		if(g == 0)
		{
			cout << 'R' << endl;
			return 0;
		}	
		else
		{
			if(g == 1)
			{
				if(r == 1)
				{
					cout << 'B' << endl;
				}
				else
					cout << "BG" << endl;

			}
			else if(r == 1)
			{
				cout << "BR" << endl;
			}
			else
			{
				cout << "BGR" << endl;
			}
		}

	}
	else if(g == 0)
	{
		if(r == 1)
		{
			if(b == 1)
			{
				cout << "G" << endl;
			}
			else
				cout << "GR" << endl;

		}
		else if(b == 1)
		{
			cout << "BG" << endl;
		}
		else
			cout << "BGR" << endl;
	}
	else
	{
		cout << "BGR" << endl;
	}

}	
