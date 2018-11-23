#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long two[30];
string s;

int main()
{
	cin >> s;
	two[0] = 1;
	for(int i = 1; i < 25; i++)
		two[i] = two[i - 1] * 2;
	int co = 0;
	for(int i = 0; i < s.length(); i++)
		if(s[i] == 'F' || s[i] == 'L' || s[i] == 'T' || s[i] == 'D')
			co++;
	cout << two[co] << endl;

}
