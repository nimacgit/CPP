#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

const int maxn = 4000;
int n;
int v[maxn + 100];
int p[maxn + 100];
int d[maxn + 100];
set <int> saf;

int main()
{
	cin >> n;
	for(int i = 0 ; i < n; i++)
		scanf("%d %d %d", &v[i], &d[i], &p[i]);
	for(int i = 0; i < n; i++)
	{
		if(p[i] >= 0)
		{
			saf.insert(i);
			int tempv = v[i];
			for(int j = i + 1; j < n && tempv > 0; j++, tempv--)
			{
				p[j] -= tempv;
			}
		}
		else
		{
			for(int k = i + 1; k < n; k++)
				p[k] -= d[i];
		}
	}
	cout << saf.size() << endl;
	while(!saf.empty())
	{
		printf("%d ", *saf.begin() + 1);
		saf.erase(saf.begin());
	}
	cout << endl;
}