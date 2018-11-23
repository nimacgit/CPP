#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 + 100;
vector <int> sons[maxn];
int n, w[maxn], d[maxn];




int findmax(int u)
{
	int sum = w[u];
	for(int i = 0; i < sons[u].size(); i++)
		sum += max(findmax(sons[u][i]), 0);
	return d[u] = sum;
}


int main()
{
	cin >> n;
	for(int i = 1, temp; i < n; i++)
	{
		scanf("%d", &temp);
		temp--;
		sons[temp].push_back(i);
	}
	for(int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	findmax(0);
	int maxim = d[0];
	for(int i = 1; i < n; i++)
		if(d[i] > maxim)
			maxim = d[i];
	//cerr << d[6] << endl;
	cout << maxim << endl;
		
}