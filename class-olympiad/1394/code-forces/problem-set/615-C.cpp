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
string s, t, s2;
bool flag = true;
int co = 0;
vector <pie> poss;

int main()
{
	cin >> s >> t;
	s2 = s;
	reverse(s2.begin(), s2.end());
	for(int i = 0; i < t.length() && flag;)
	{
		int x, y;
		flag = false;
		int sz = 0;
		for(int j = 0; j < s.length(); j++)
		{
			if(t[i] == s[j])
			{
				flag = true;
				int k = 0;
				for(; k < min(s.length() - j, t.length() - i) && t[i + k] == s[j + k]; k++);
				if(k > sz)
				{
					x = j + 1;
					y = j + k;
					sz = k ;
				}
			}
		}
		int siz = s2.length() + 1;
		for(int j = 0; j < s2.length(); j++)
		{
			if(t[i] == s2[j])
			{
				flag = true;
				int k = 0;
				for(; k < min(s2.length() - j, t.length() - i) && t[i + k] == s2[j + k]; k++);
				if(k > sz)
				{
					x = siz - j - 1;
					y = siz - j - k;
					sz = k ;
				}
			}
		}
		co++;
		poss.push_back(mp(x, y));
		i += sz;
	}
	if(!flag)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		cout << co << endl;
		for(int i = 0; i < poss.size(); i++)
		{
			cout << poss[i].first << " " << poss[i].second << endl;
		}
	}


}
