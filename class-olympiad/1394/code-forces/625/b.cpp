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
string s, t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	int co = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == t[0])
		{
			bool flag = true;
			for(int j = 0; j < t.length() && flag; j++)
				if(s[i + j] != t[j])
					flag = false;
			if(flag)
			{
				co++;
				i+=t.length() - 1;
			}
		}
	}
	cout << co << endl;
}	
