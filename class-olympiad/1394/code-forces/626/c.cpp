#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000;
int n, m;

int main()
{
	cin >> n >> m;
	int fm = 0, lm = 0, ln = 0;
	fm = 6;
	lm = 3 * m;
	for(int i = 0; i < n; i++)
	{
		ln += 2;
		if(ln % 3 == 0 && ln <= lm)
			n++;
	}
	int maxi = max(lm, ln);
	while(fm <= lm && fm <= ln)
	{
		ln -= 2;
		lm += 3;
		if(lm % 2 == 0 && lm <= ln)
			ln += 2;
		maxi = min(max(ln, lm), maxi);
		fm += 6;
	}
	cout << maxi << endl;

}
