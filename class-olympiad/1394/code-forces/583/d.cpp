#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

const int maxn = 100;
int rep[3 * maxn + 100];
int nums[maxn + 100];
int first[3 * maxn + 100];
int last[3 * maxn + 100];
set <int> unnum;
int n, t;
int d[maxn + 100];

void dynamic()
{
	d[0] = 1;
	for(int i = 1; i < 2 * n; i++)
	{
		int maxi = 1;
		for(int j = i - 1; j >= 0; j--)
			if(nums[j] <= nums[i])
				maxi = max(maxi, d[j] + 1);
		d[i] = maxi;
	}
}


int main()
{
	scanf("%d %d", &n, &t);
	for(int i = 0; i < 3 * n + 10; i++)
		rep[i] = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
		unnum.insert(nums[i]);
		if(rep[nums[i]] == 0)
			first[nums[i]] = i;
		last[nums[i]] = i;
		rep[nums[i]]++;
	}
	dynamic();
	for(int i = 0; i < n; i++)
		cerr << d[i] << " ";
	int maximum = 0;
	while(!unnum.empty())
	{
		int nima = *unnum.begin();
		int sum = 0;
		sum += d[first[nima]] - 1 + rep[nima] * t;
		cerr << " nima  " << nima << "  " << sum << " " << rep[nima] << "  " << first[nima] << endl;
		maximum = max(maximum, sum);
		unnum.erase(unnum.begin());
	}
	cout << maximum << endl;

}