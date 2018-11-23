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

int n, p, q;
string s;

int main()
{
	cin >> n >> q >> p;
	cin >> s;

	for(int i = 0; i <= n / q; i++)
	{
		if((n - i * q) % p == 0)
		{
			cout << i + (n-i*q)/p << endl;
			for(int j = 0; j < i; j++)
			{
				for(int k = 0; k < q; k++)
					cout << s[j * q + k];
				cout << endl;
			}
			for(int j = 0; j < (n - i * q) / p; j++)
			{
				for(int k = 0; k < p; k++)
					cout << s[i * q + j * p + k];
				cout  << endl;
			}
			return 0;
		}
	}
	cout << -1 << endl;
}
