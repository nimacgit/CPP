#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <set>



using namespace std;

const int maxn = 2000;
set <int> myset[maxn];
vector <pair<int, int> > myvec;
int n, x1, y1;

int main()
{
	long long sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x1 >> y1;
		myvec.push_back(make_pair(x1, y1));
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(myvec[j].second == myvec[i].second)
				myset[i].insert(300);
			else
				myset[i].insert((myvec[j].first - myvec[i].first) / (myvec[j].second - myvec[i].second));
		}
		sum += (myset[i].size() * (myset[i].size() - 1) / 2);
	}
	cout << sum << endl;

}