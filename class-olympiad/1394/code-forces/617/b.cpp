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
const int maxn = 109;
int n;
int a[maxn];
long long sum = 1;
bool flag = false;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == 1)
			flag = true;
	}
	if(!flag)
	{
		cout << 0 << endl;
		return 0;
	}
	int fpos = 0, lpos = n - 1;
	for(int i = 0; i < n && a[i] != 1; i++)
		fpos++;
	for(int i = n - 1; i >= 0 && a[i] != 1; i--)
		lpos--;
	int co = 0;
	for(int i = fpos; i <= lpos; i++)
	{
		co++;
		if(a[i] == 1)
		{
			sum *= co;
			co = 0;
		}
	}
	cout << sum << endl;



}	
