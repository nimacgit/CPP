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

string s;
int o = 0, p = 0;

int main()
{
	cin >> s;
	int co = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '(')
			o++;
		else
			
	}
	cout << 2*min(o, p) << endl;
}
