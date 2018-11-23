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

const int maxn = 1000 * 1000;
char s[maxn + 100], t[maxn + 100];

int main()
{
	scanf("%s", s);
	scanf("%s", t);
	int ss = strlen(s);
	int ts = strlen(t);
	int i = 0;
	while(s[i] == '0' && i < ss)
		i++;
	int j = 0;
	while(t[j] == '0' && j < ts)
		j++;
	if(ss - i != ts - j)
	{
		if(ss - i > ts - j)
			cout << '>' << endl;
		else
			cout << '<' << endl;
		return 0;
	}
	while(i < ss && j < ts)
	{
		if(s[i] != t[j])
		{
			if(s[i] > t[j])
				cout << '>' << endl;
			else
				cout << '<' << endl;
			return 0;
		}
		i++;
		j++;
	}
	cout << '=' << endl;


}
