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
vector<int> a,b;
int use[maxn + 100];
int n;

int main()
{
	ifstream inp("highcard.in", ios::in);
	inp >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		inp >> temp;
		use[temp] = true;
	}
	for(int i = 1; i <= 2*n; i++)
		if(!use[i])
			b.push_back(i);
		else
			a.push_back(i);
	int firs = 0, las = n - 1;
	int co = 0;
	for(int i = n - 1; i >= 0; i--)
		if(a[i] > b[las])
			firs++;
		else
		{
			co++;
			las--;
		}
	ofstream out("highcard.out", ios::out);
	out << co << endl;
	return 0;
}
