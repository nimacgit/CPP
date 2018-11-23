#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

string s, t;
bool ba = false;
bool flag = false;
int b = 0, pos = -1;

int main()
{
	cin >> s;
	for(int i = 0; i < s.length(); i++)
		if(s[i] != '0' || flag)
		{
			if(s[i] == '.')
			{
				if(t.length() == 0)
				{
					ba = true;
					b = -1;
				}
				else
				{
					pos = t.length() - 1;
					flag = true;
				}
			}
			else
			{
				flag = true;
				t += s[i];
			}
		}
		else
		{
			if(ba)
			{
				b--;
			}
		}
	for(int i = t.length() - 1; i >= 0; i--)
	{
		if(t[i] != '0')
			i = -1;
		else
		{
			if(!ba && (i <= pos || pos == -1))
			{
				pos = max(-1, pos - 1);
				b++;
			}
			t.erase(t.begin() + i);
		}
	}
	if(t.length() == 0)
		cout << 0 << endl;
	else
	{
		if(!ba)
		{
			if(pos == -1)
				pos = t.size() - 1;
			b += pos;
		}
		if(b == 0)
		{
			if(t.size() == 1)
				cout << t << endl;
			else
			{
				cout << t[0];
				t[0] = '.';
				cout << t << endl;
			}
		}
		else
		{
			if(t.size() == 1)
				cout << t << "E" << b << endl;
			else
			{
				cout << t[0];
				t[0] = '.';
				cout << t << 'E' << b << endl;
			}
		}
	}
	;;;;
}
