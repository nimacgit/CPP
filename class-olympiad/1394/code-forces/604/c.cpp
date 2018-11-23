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
int n;


int main()
{
	cin >> n;
	cin >> s;
	char c = s[0];
	int sum = 1;
	bool d1 = false, d2 = false;
	for(int i = 1; i < n; i++)
		if(s[i] != c)
		{
			sum++;
			c = s[i];
		}
		else
		{
			if(d1)
			{
				if(!d2)
				{
				d2 = true;
				sum++;
				}
			}
			else
			{
					d1 = true;
					sum++;
			}
		}
		
	cout << sum << endl;
}
