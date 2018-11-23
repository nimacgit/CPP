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
string a, b;
const int maxn = 17171;
const int delta = 648481;

int main()
{
	a = "0";
	b = "1";
	while(b.size() < maxn)
	{
		string c;
		int bagi = 0;
		for(int i = 0; i < a.size(); i++)
		{
			c += ((b[i]-'0') + (a[i]-'0') + bagi) % 10 + '0';
			bagi = ((b[i]-'0') + (a[i]-'0') + bagi) / 10;
		}
		for(int i = a.size(); i < b.size(); i++)
		{
			c += (bagi + (b[i]-'0')) % 10 + '0';
			bagi = (bagi + (b[i]-'0'))/10;
		}
		if(bagi != 0)
			c+= bagi + '0';
		a = b;
		b = c;
	}
	cerr << " kow " << endl;
	long long sum = 0;
	long long mult = 1;
	for(int i = 0; i < a.size(); i++)
	{
		sum =(sum + (a[i] - '0')) % delta;
		mult = (mult * (a[i] - '0')) % delta;
	}
	cout << (mult - sum + delta) << " " << (mult - sum) % delta << endl;
}
