#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

bool l, r, u, d;
int n;
string s;

int main()
{
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '2')
			u = true;
		else if(s[i] == '1')
			u = l = true;
		else if(s[i] == '3')
			u = r = true;
		else if(s[i] == '4')
			l = true;
		else if(s[i] == '6')
			r = true;
		else if(s[i] == '7')
			l = d = true;
		else if(s[i] == '9')
			d = r = true;
		else if(s[i] == '0')
			l = r = d = true;
	}
	if(!r || !d || !l || !u)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

}
