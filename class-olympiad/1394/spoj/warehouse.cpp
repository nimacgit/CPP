#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

typedef  pair<int,int> pii;
#define mp(x, y) make_pair(x, y)

const int maxn = 250 * 1000 + 100;
int ai[maxn], bi[maxn];
int n;
set <pii> myset;
set <pii>::iterator it;
bool use[maxn];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &ai[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &bi[i]);
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += ai[i];
		if(bi[i] <= sum)
		{
			sum -= bi[i];
			myset.insert(mp(bi[i], i));
			use[i] = true;
		}
		else
		{
			if(myset.size() > 0)
			{
				it = myset.end();
				it--;
				if((*it).first > bi[i])
				{
					use[(*it).second] = false;
					sum += (*it).first - bi[i];
					myset.erase(it);
					myset.insert(mp(bi[i], i));
					use[i] = true;
				}
			}
		}
	}
	cout << myset.size() << endl;
	for(int i = 0; i < n; i++)
		if(use[i])
			cout << i + 1 << " ";
	cout << endl;
	return 0;

}