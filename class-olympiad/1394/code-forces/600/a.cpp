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

const int maxn = 20;

string s;
string a, b, c;
bool isa = true;
bool isnum(char myc)
{
	if(myc <= '9' && myc >= '0')
		return true;
	return false;
}

int main()
{
	cin >> s;
	s+=';';
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ';' || s[i] == ',')
		{
			if(isa && c.length() != 0)
			{
				if(a.size() == 0)
				{
					a += '"';
					a += c;
				}
				else
				{
					a += ',';
					a += c;
				}
			}
			else
			{
				if(b.size() == 0)
				{
					b += '"';
					b += c;
				}
				else
				{
					b += ',';
					b += c;
				}
			}
			c.clear();
			isa = true;
		}
		else
		{
			if(s[i] == '.')
			{
				isa = false;
				c+=s[i];
			}
			else
			{
				c += s[i];
				if(!isnum(s[i]) || (c.length() == 1 && s[i] == '0' && (s[i + 1] != ';' && s[i + 1] != ',')))
					isa = false;
			}
		}
	}
	if(a.length() > 0)
		cout << a << '"' << endl;
	else
		cout << '-' << endl;
	if(b.length() > 0)
		cout << b << '"' << endl;
	else
		cout << '-' << endl;
}
