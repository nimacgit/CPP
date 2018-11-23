#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e5 + 100;
vector<int> o, z;
int n, k, p;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k >> p;
	for(int i = 0, temp; i < n; i++)
	{
		cin >> temp;
		if(temp % 2)
			o.push_back(temp);
		else
			z.push_back(temp);
	}
	if((o.size() - k + p) % 2 == 0 && (o.size() - k + p) / 2 + z.size() >= p && o.size() >= k - p)
	{
		if(p == 0)
		{
			if(o.size() % 2 == k % 2)
			{
				cout << "YES" << endl;
				for(int i = 0; i < k - 1; i++)
					cout << 1 << " " << o[i] << endl;
				cout << o.size() - k + 1 + z.size() << " ";
				for(int i = k - 1; i < o.size() ; i++)
					cout << o[i] << " ";
				for(int i = 0; i < z.size(); i++)
					cout << z[i] << " ";
				cout << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
			return 0;
		}
		cout << "YES" << endl;
		for(int i = 0; i < k - p; i++)
			cout << 1 << " " << o[i] << endl;
		for(int i = k - p; i < o.size(); i++)
			z.push_back(o[i]);
		int i = 0;
		for(int co = 0; co < p - 1; co++, i++)
		{
			if(z[i] % 2 == 0)
				cout << 1 << " " << z[i] << endl;
			else
			{
				cout << 2 << " " << z[i] << " " << z[i + 1] << endl;
				i++;
			}
		}
		cout << z.size() - i << " ";
		while(i < z.size())
		{
			cout << z[i] << " ";
			i++;
		}
		cout << endl;
			
	}
	else
	{
		cout << "NO" << endl;
	}

}
