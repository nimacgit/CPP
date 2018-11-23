#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 100;
vector <int> factors[maxn + 10];
bool notprime[maxn + 10];
vector < pair <int, int> > nums;
void find()
{
	factors[1].push_back(1);
	for(int i = 2; i <= maxn; i++)
		if(!notprime[i])
			for(int j = 1; j * i <= maxn; j++)
			{
				notprime[i * j] = true;
				factors[i * j].push_back(i);
			}
}

int findmul(int a)
{
	int sum = 1;
	for(int i = 0; i < factors[a].size(); i++)
		sum *= factors[a][i];
	return sum;
}

bool comp(pair <int, int> a, pair <int, int> b)
{
	return a.second < b.second;
}


int main()
{
	find();
	for(int i = 1; i <= maxn; i++)
	{
		int temp = findmul(i);
		nums.push_back(make_pair(i, temp));
	}
	sort(nums.begin(), nums.end(), comp);
	for(int i = 9998; i <= 10003; i++)
		cout << nums[i].first << endl;
}