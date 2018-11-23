#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;

const int maxn = 1000 * 1000;
long long d[maxn + 10];
vector<long long> divis[maxn + 10];

void find()
{
	for(long long i = 1; i <= maxn; i++)
		for(long long j = 2; j * i <= maxn; j++)
			divis[i * j].push_back(i);
}

long long divsum(long long a)
{
	long long sum = 0;
	for(long long i = 0; i < divis[a].size(); i++)
		sum += divis[a][i];
	return sum;
}

int findroot(int a)
{
	if(d[a] == -1)
		return -1;
	set<int> myset;
	myset.insert(d[a]);
	int sum = 1, temp = d[d[a]];
	while(temp != -1 && myset.find(temp) == myset.end())
	{
		//cout << temp << endl;
		myset.insert(temp);
		sum++;
		temp = d[temp];
		if(temp == a)
			return sum;
	}
	return -1;
}

int main()
{
	find();
	cout << divsum(95) << endl;
	cout << divsum(284) << endl;
	for(long long i = 1; i <= maxn; i++)
	{
		long long temp = divsum(i);
		if(temp < maxn && temp != i)
			d[i] = temp;
		else
			d[i] = -1;
	}
	d[1] = -1;
	int maxim = 0;
	int index = 1000000;
	//cout << findroot(14316) << endl << endl;
	
	for(int i = 1; i <= maxn; i++)
	{
		int temp = findroot(i);
		if(temp > maxim)
		{
			maxim = temp;
			index = i;
			cout << index << endl;
		}
	}
	cout << index << endl;

}