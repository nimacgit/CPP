#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int maxn  = 50;
pair<int, int> a[maxn * maxn + 100];
int n;
bool h[maxn + 10], v[maxn + 10];
set <int> myset;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n * n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);
	for(int i = 0; i < n * n; i++)
	{
		int f = a[i].first, s = a[i].second;
		if((!h[f]) && (!v[s]))
		{
			h[f] = v[s] = true;
			myset.insert(i + 1);
		}
	}
	while(!myset.empty())
	{
		printf("%d ", *myset.begin());
		myset.erase(myset.begin());
	}
	cout << endl;
}