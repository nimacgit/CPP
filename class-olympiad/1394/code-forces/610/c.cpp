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
const int maxn = 1024;
vector<string> nima;
int n;
long long two = 1;

string f(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '*')
			s[i] = '+';
		else
			s[i] = '*';
	}
	return s;
}

int main()
{
	cin >> n;
	nima.push_back("+");
	for(int i = 0; i < n; i++)
		two *= 2;
	long long co = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < co; j++)
		{
			nima.push_back(nima[j] + f(nima[j]));
			nima[j] += nima[j];
		}
		co *= 2;
	}
	for(int i = 0; i < two; i++)
		cout << nima[i] << endl;
		

	
}

