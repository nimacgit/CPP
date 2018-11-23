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

const int maxn = 1000 * 1000;
long long a,b,c,n;

int main()
{
	cin >> n >> a >> b >> c;
	if(n < b)
	{
		cout << (long long)n / a << endl;
		return 0;
	}
	long long sum = 0;
	if(b - c < a)
	{
		n -= c;
		sum += n/(long long)(b - c);
		n = n % (long long)(b-c);
		n += c;
		if(b > a)
			sum += n / a;
		else
			sum += n / b;
		cout << sum << endl;

	}
	else
		cout << (long long)n / a << endl;


}
