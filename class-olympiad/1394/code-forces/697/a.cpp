#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long t, x, s;
long long pos = 0;
int main()
{
	cin >> t >> s >> x;
	pos = t;
	if(x < t)
	{
		cout << "NO" << endl;
		return 0;
	}
	if(x == t)
	{
		cout << "YES" << endl;
		return 0;
	}
	while(pos <= x)
	{
		pos += s;
		if(pos == x || (pos + 1) == x)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	;;
}
