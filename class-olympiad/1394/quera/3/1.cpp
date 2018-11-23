#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

string s1, s2;
char c;

int main()
{
	cin >> s1 >> c >> s2;
	if(c == '*')
	{
		cout << 1;
		for(int i = 2; i < s1.length() + s2.length(); i++)
			cout << 0;
		cout << endl;
		return 0;
	}
	if(s1.length() > s2.length())
	{
		s1[s1.length() - s2.length()]++;
		cout << s1 << endl;
		return 0;
	}
	else
	{
		s2[s2.length() - s1.length()]++;
		cout << s2 << endl;
		return 0;
	}

}
