#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#include <fstream>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
int n, m;
const int maxn = 100;
int lim[maxn + 100];


int main()
{
	ifstream inp;
	inp.open("speeding.in", ios::in);
	int lpos = 0;
	inp >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int temp, temp1;
		inp >> temp >> temp1;
		for(int i = 0; i < temp; i++, lpos++)
			lim[lpos] = temp1;
	}
	lpos = 0;
	int maxi = 0;
	for(int i = 0; i < m; i++)
	{
		int temp, temp1;
		inp >> temp >> temp1;
		for(int i = 0; i < temp; i++, lpos++)
			maxi = max(maxi,temp1 - lim[lpos]);
	}	
	inp.close();
	ofstream out;
	out.open("speeding.out", ios::out);
	out << maxi << endl;
	out.close();
	return 0;



}
