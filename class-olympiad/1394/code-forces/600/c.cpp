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

const int maxn = 26;
int ch[maxn + 10];
string s;


int main()
{
	cin >> s;
	for(int i = 0; i < s.length(); i++)
		ch[s[i] - 'a']++;
	bool notuse = false;
	int npos = -1;
	if(s.length() % 2 == 1)
		notuse = true;
	int k = 0;
	for(int i = 26; i >= 0; i--)
	{
		if(ch[i] % 2 == 1)
		{
			while(ch[k] % 2 == 0 && k < i)
				k++;
			if(i != k)
			{
				ch[k]++;
				ch[i]--;
			}
			if(notuse && ch[i] % 2 == 1)
				npos = i;
		}
	}
	if(notuse)
		ch[npos]--;
	s.clear();
	for(int i = 0; i <= 26; i++)
	{
		int k = 0;
		while(k < ch[i]/ 2)
		{
			s += 'a' + i;
			k++;
		}
	}
	if(notuse)
		s += 'a' + npos;
	for(int i = 26; i >= 0; i--)
	{
		int k = 0;
		while(k < ch[i]/2)
		{
			s += 'a' + i;
			k++;
		}
	}
	cout << s << endl;



}
