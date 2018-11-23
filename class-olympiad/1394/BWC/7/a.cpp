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

int delta = 648481;
long long n, m, t;
string s;

int main()
{
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		m = 1;
		long long co = 0;
		while(m < n || m < 26)
		{
			m*=26;
			co++;
		}
		long long sec = m % n;
		s.clear();
		if(sec == 0)
			s+='a';
		cerr << sec << endl;
		while(sec)
		{
			s += 'a' + sec % 26;
			sec /= 26;
		}
		cout << 'b';
		for(int i = 0; i < co; i++)
			cout << 'a';
		cout  << " ";
		for(int i = s.length() - 1; i >= 0; i--)
			cout << s[i];
		cout << endl;
	}
}

