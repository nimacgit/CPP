#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>


using namespace std;

const int maxn = 1000 * 100 + 3;

vector<int> v[maxn];
int t[maxn];

int main()
{
	int n, l;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	int maxl = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &l);
		if(l > maxl)
			maxl = l;
		v[l].push_back(t[i]);
	}
	long long sum = 0, maxt = 0;
	for(int i = maxl; i >= 0; i--)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			sum += v[i][j];
			//cout << v[i][j] << " l " << l << " j " << j << endl;
			if(sum + i > maxt)
				maxt = sum + i;
		}
	}
	cout << maxt << endl;
		
}