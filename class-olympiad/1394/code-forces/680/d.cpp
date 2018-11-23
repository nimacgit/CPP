#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<long long, int> pie;

const int maxn = 1e6;
vector<long long> t;
long long m;
int pw2[4] = {1, 2, 4, 8};
int pw3[4] = {1, 3, 9, 27};


int main()
{
	for(int i = 1; i <= 1e5; i++)
		t.push_back((long long)i * i * i);
	cin >> m;
	long long ans = 0;
	if(m <= 7)
	{
		cout << m << " " << m << endl;
	}
	else
	{
		if(m >= 23)
		{
			if(m >= 50)
			{
				ans = 50;
				int co = 3;
				long long ne = t[co];
				while(ans + ne <= m)
				{
					ans += ne;
					co++;
					ne = t[co];
				}
				cout << 7 + co << " " << ans << endl;
			}
			else
			{
				cout << 9 << " ";
				if(m >= 42)
				{
					cout << 42 << endl;
				}
				else
				{
					cout << 23 << endl;
				}
			}
		}
		else
		{
			if(m >= 15)	
			{
				cout << "8 15" << endl;
			}
			else
			{
				cout << "7 7" << endl;
			}

		}
	}
}
