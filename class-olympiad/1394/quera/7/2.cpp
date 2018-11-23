#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long n, m;

int main()
{
	cin >> m >> n;
	while(n > 1 || m > 1)
	{
		if(n > 1)
			n = n % 2 + n / 2;
		else
		{
			n += m / 2;
			m %= 2;
		}
	}
	if(n == 1 && m == 1)
		cout << "black" << endl;
	else
		cout << "white" << endl;
}
