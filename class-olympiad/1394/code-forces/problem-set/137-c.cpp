#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>


using namespace std;

const long long maxn = 1000 * 100;
long long n;
vector <pair<int, int> > v;

int main()
{
	cin >> n;
	int co = 0;
	for(int i = 0; i < n; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		v.push_back(make_pair(temp1, temp2));
	}
	sort(v.begin(), v.end());
	int maxim = -1;
	for(int i = 0; i < n; i++)
	{
		if(v[i].second > maxim)
			maxim = v[i].second;
		else
			co++;
	}
	cout << co << endl;
}