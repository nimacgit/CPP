#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
string s;
int ans, k, n;

bool f(int i, int mid)
{
	int temp = mid;
	while(mid < s.length() && i < temp)
	{
		if(s[mid] != s[i])
			return false;
		mid++;
		i++;
	}
	return true;
}



int main()
{
	cin >> s;
	n = s.length();
	cin >> k;
	ans = min(2 * k, ((n + k)/2)*2);
	for(int i = 0; i < n; i++)
		for(int j = i; j >= 0 && 2*i - j + 1 < n + k; j--)
		{
			if(f(j, i + 1))
				ans = max(ans, 2*(i - j + 1));
		}
	cout << ans << endl;

}
