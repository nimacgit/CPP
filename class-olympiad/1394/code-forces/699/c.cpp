#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1e4;
int a[maxn];
int n;

int check(int s, int e)
{
	while(s <= e && a[s] == 3)
		s++;
	if(s > e)
		return 0;
	if(a[s] == 0)
		return check(s + 1, e) + 1;
	int flag = a[s];
	s++;
	while(s <= e)
	{
		if(a[s] == 0)
			return check(s + 1, e) + 1;
		else if(a[s] == 3)
			flag = 3 - flag;
		else if(a[s] == flag)
			return check(s+1, e) + 1;
		else
			flag = 3 - flag;

		s++;
	}
	return 0;


}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << check(0, n - 1) << endl;
}
