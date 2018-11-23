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


int main()
{
	cin >> s;
	t = s;
	reverse(s.begin(), s.end());
	t += s;
	cout << t << endl;
}
