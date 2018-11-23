#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 100;
int t[maxn + 10];
const int delta = 12781;
vector <int> num;
const int inf = 1 << 29;

void find()
{
	int sum = 0;
	for(int i = 1; sum <= maxn; i++)
	{
		sum += i * (i + 1) / 2;
		num.push_back(sum);
	}
}

void dyn()
{
	for(int i = 1; i <= maxn; i++)
		t[i] = inf;
	for(int i = 0; i < num.size(); i++)
		t[num[i]] = 1;
	for(int i = 1; i <= maxn; i++)
	{
		if(t[i] == inf)
			for(int j = 0; j <= 100 && j <= i; j++)
			{
				if(t[i] > t[i - j] + t[j])
					t[i] = t[i - j] + t[j];
			}
	}
}

int main()
{
	find();
	cout << num.size() << endl;
	dyn();
	long long sum = 0;
	for(int i = 30; i <= maxn; i++)
		cout << i <<  " " << t[i] << endl;
	for(int i = 30; i <= maxn; i++)
	{
		long long tavan = t[i];
		for(int j = 1; j < i; j++)
			tavan = ((tavan * t[i]) % delta);
		sum = (tavan + sum) % delta;
	}
	cout << sum << endl;
}