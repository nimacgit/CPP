#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n, m;
char c;

int main()
{
	cin >> n >> m;
	bool flag = false;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> c;
			if(c == 'Y' || c == 'M' || c == 'C')
				flag = true;
		}
	if(flag)
		cout << "#Color" << endl;
	else
		cout << "#Black&White" << endl;
}
