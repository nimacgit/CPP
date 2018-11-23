#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long ans=1e9, n, temp1, temp2;
string s;

int main()
{
	cin >> n;
	cin >> s;
	cin >> temp1;
	for(int i = 1; i < s.length(); i++)
	{
		cin >> temp2;
		if(s[i - 1] == 'R' && s[i] == 'L')
			ans = min(ans, (temp2 - temp1) / 2);
		temp1 = temp2;
	}
	if(ans == 1e9)
		cout << -1 << endl;
	else
		cout << ans << endl;
}
