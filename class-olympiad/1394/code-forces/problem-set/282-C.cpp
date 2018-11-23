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
string s1, s2;
bool allz[2];
int main()
{
	cin >> s1 >> s2;
	if(s1.size() != s2.size())
		cout << "NO" << endl;
	else
	{
		for(int i = 0; i < s1.size(); i++)
		{
			if(s1[i] == '1')
				allz[0] = true;
			if(s2[i] == '1')
				allz[1] =true;
		}
		if(allz[1] != allz[0])
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	
}
