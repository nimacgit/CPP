#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n, pos, t, ty;
string s;
bool seen[100];
int co[100];

int num(char c)
{
	if(int(c) > 64 && int(c) < 91)
		return int(c) - 65;
	else
		return 30 + int(c) - 97;
}

int main()
{
	cin >> n;
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
			if(!seen[num(s[i])])
			{
				seen[num(s[i])] = true;
				ty++;
			}
	}
	int mini = 1e8;
	for(int i = 0; i < s.length(); i++)
	{
		while(t != ty && pos < s.length())
		{
			if(co[num(s[pos])] == 0)			
				t++;
			co[num(s[pos])]++;
			pos++;
		}
		if(t == ty)
			mini = min(mini, pos - i);
		if(co[num(s[i])] == 1)
			t--;
		co[num(s[i])]--;
	}
	cout << mini << endl;
}
