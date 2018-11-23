#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

string s, t, num;
int pos = -1, b, lzero = 0;
bool flag = false, lz = true;

void makeb()
{
	b = 0;
	for(int i = 0; i < num.length(); i++)
		b = b * 10 + num[i] - '0';
}


int main()
{
	cin >> s;
	for(int i = 2; i < s.length(); i++)
	{
		if(flag)
			num += s[i];
		if(s[i] == 'e')
			flag = true;
		else if(!flag)
		{
			if(s[i] != '0')
				lz = false;
			if(lz)
				lzero++;
			t += s[i];	
		}
	}
	makeb();
	if(lzero == t.size())
	{
		cout << s[0];
		if(s[0] != 0)
			for(int i = 0; i < b; i++)
				cout << 0;
		cout << endl;
		return 0;
	}
	if(s[0] == '0')
		cout << "0." << t;
	else
	{
		cout << s[0];
		if(t.length() >= b)
		{
			for(int i = 0; i < b; i++)
				cout << t[i];
			if(t.length() != b)
				cout << '.';
			for(int i = b; i < t.length(); i++)
				cout << t[i];
		}
		else
		{
			cout << t;
			for(int i = t.length(); i < b; i++)
				cout << 0;
		}
	}
	cout  << endl;
}
