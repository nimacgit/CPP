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


long long n, a, b;
long long inf = (long long)1e18;
long long start = 1;

int main()
{
	cin >> a >> b;
	long long co = 0;
	while(start <= b)
	{
		n = start;
		n = (n << 1);
		while(n <= b)
		{
			if(n >= a && n <= b)
				co++;
			n = (n << 1) + 1;
		}
		start = (start << 1) + 1;

	}
	cout << co << endl;
}	
