#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#include <deque>

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000 * 100;
vector<int> a[2],b;
int use[maxn + 100];
int n;

int main()
{
	ifstream inp("cardgame.in", ios::in);
	inp >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		inp >> temp;
		if(i < n/2)
			a[0].push_back(temp);
		else
			a[1].push_back(temp);
		use[temp] = true;
	}
	for(int i = 1; i <= 2*n; i++)
		if(!use[i])
			b.push_back(i);
	sort(a[0].begin(), a[0].end());
	sort(a[1].begin(), a[1].end());
	int firs = 0, las = n - 1;
	int co = 0;
	for(int i = n / 2 - 1; i >= 0; i--)
		if(a[0][i] < b[las])
		{
			co++;
			las--;
		}
	for(int i = 0; i < n / 2; i++)
	{
		if(a[1][i] > b[firs])
		{
			co++;
			firs++;
		}
	}
	ofstream out("cardgame.out", ios::out);
	out << co << endl;
	return 0;
}
