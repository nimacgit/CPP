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
const int maxn = 3000;
int n;
string s;
int m, h;
int a;

int main()
{
	cin >> s;
	cin >> a;
	int h = (s[0] - '0') * 10 + s[1] - '0';
	int m = (s[3] - '0') * 10 + s[4] - '0';
	m += a;
	h += m / 60;
	m %= 60;
	h %= 24;
	if(h<10)
		cout << 0;
	cout << h << ":";
	if(m < 10)
		cout << 0;
	cout << m << endl;


	

}	
