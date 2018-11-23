/*
ID: michael247
PROG: ride
LANG: C++
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef pair<int, int> pie;


string s;

int main()
{
	int a = 1, b = 1;
	fstream in("ride.in", ios::in);
	fstream o("ride.out", ios::out);
	in >> s;
	for(int i = 0; i < s.length(); i++)
		a = (a *(s[i] - 'A' + 1)) % 47;
	in >> s;
	for(int i = 0; i < s.length(); i++)
		b = (b*(s[i] - 'A' + 1)) % 47;
	cerr << a << " " << b << endl;
	if(a == b)
		o << "GO" << endl;
	else
		o << "STAY" << endl;
	return 0;
		

}
