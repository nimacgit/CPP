/*
ID: michael247
PROG: gift1
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


vector<string> names;
vector<int> mon;
vector<int>get;
int n;
string s;

int find(string name)
{
	for(int i = 0;i < names.size(); i++)
		if(names[i] == name)
			return i;
}


int main()
{
	fstream in("gift1.in", ios::in);
	in >> n;
	for(int i = 0; i < n; i++)
	{
		in >> s;
		names.push_back(s);
		mon.push_back(0);
		get.push_back(0);
	}
	for(int i = 0; i < n; i++)
	{

		int temp, num;
		in >> s;
		in >> temp >> num;
		mon[find(s)] = temp;
		if(num == 0)
			get[find(s)] += temp;
		else
			get[find(s)] += temp % num;
		for(int j = 0; j < num; j++)
		{
			in >> s;
			get[find(s)] += (temp / num);
		}
	}
	fstream o("gift1.out", ios::out);
	for(int i = 0; i < n; i++)
		o << names[i] << " " << get[i] - mon[i] << endl;
	return 0;
}
