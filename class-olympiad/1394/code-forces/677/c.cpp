#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
int two[7] = {1, 3, 9, 27, 81, 243, 3*243};
string s;
long long mo = 1000000007;
int d[128];

int main()
{
	d[0] = 6;
	for(int i = 1; i < 64; i++)
	{
		if(i % 2 == 0)
			d[i] = d[i / 2];
		else
			d[i] = d[i / 2] - 1;
	}
	cin >> s;
	long long sum = 1;
	for(int i = 0; i < s.length(); i++)
	{
		int co;
		if((int)'0' <= (int)s[i] && (int)s[i] <= (int)'9')
		{
			co = s[i] - '0';
		}
		else if((int)'A'  <= (int)s[i] && (int)s[i] <= (int)'Z')
		{
			co = s[i] - 'A' + 10;
		}
		else if( (int)'a' <= (int)s[i] && (int)s[i] <= (int)'z')
		{
			co = s[i] - 'a' + 36;
		}
		else if(s[i] == '_')
		{
			co = 63;
		}
		else
		{
			co = 62;
		}
		sum = (sum * (long long)(two[d[co]])) % mo;
	}
	cout << sum % mo << endl;
}
