#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;


bool a[30];
string s;
int co;
int main()
{
	getline(cin, s);
	for(int i = 1; i < s.length() - 1; i+= 3)
		a[s[i] - 'a'] = true;
	for(int i = 0; i < 30; i++)
		if(a[i])
			co++;
	cout << co  << endl;
}
