#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n;
string s;
bool a[30];
int t= 0;

int main()
{
	cin >> n;
	cin >> s;
	if(s.length() > 26)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < s.length(); i++)
	{
		if(a[s[i] - 'a'])
		{
			t++;
		}
		else
			a[s[i] - 'a'] = true;
	}
	cout << t << endl;
		
}
