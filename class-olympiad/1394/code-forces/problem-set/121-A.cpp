#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000 * 1000 * 1000;
const int maxnum = 2 * 1000;
vector<long long> nums;
long long l, r;
long long sum = 0;

void make()
{
	nums.push_back(4);
	nums.push_back(7);
	int start = 0, end = 1;
	for(int i = 0; i < 9; i++)
	{
		int j = start;
		while(j <= end)
		{
			nums.push_back(nums[j] *(long long)10 +(long long)4);
			nums.push_back(nums[j] *(long long)10 +(long long)7);
			j++;
		}
		start = end+1;
		end = nums.size() - 1;
	}
}



int main()
{
	make();
	cin >> l >> r;
	int spos = lower_bound(nums.begin(), nums.end() , l) - nums.begin();
	int lpos = upper_bound(nums.begin(), nums.end() , r) - nums.begin() - 1;
	if(lpos < spos)
	{
		cout << (long long)(r - l + 1) * nums[spos] << endl;
		return 0;
	}
	for(int i = spos; i < lpos; i++)
		sum += (nums[i + 1] - nums[i]) * nums[i + 1];
	sum += (long long)(nums[spos] - l + (long long)1) * nums[spos];
	sum += (long long)(r - nums[lpos]) * nums[lpos + 1];
	cout << sum << endl;
}
