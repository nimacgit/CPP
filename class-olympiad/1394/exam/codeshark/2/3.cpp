#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 222222;
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
		if(sum <= maxn)
			num.push_back(sum);
	}
}

void dyn()
{
	for(int i = 1; i <= maxn; i++)
		t[i] = inf;
	cout << " co " << endl;
	for(int i = 0; i < num.size(); i++)
		t[num[i]] = 1;
	for(int i = 1; i <= maxn; i++)
	{
		if(t[i] == inf)
			for(int j = 0; j <= num.size() && num[j] <= i; j++)
			{
				if(t[i] > t[i - num[j]] + 1)
					t[i] = t[i - num[j]] + 1;
			}
	}
}

int main()
{
	find();
	cout << num.size() << endl;
	dyn();
	cout << "Be " << endl;
	long long sum = 0;
	for(int i = 111111 ; i <= maxn; i++)
	{
		long long tavan = 1;
		long long help = 1;
		int helpi = i;
		int helphez = 1;
		for(int j = 0; j < helpi % 1000; j++)
			help = (t[i] * help) % delta;
		for(int j = 0; j < 1000; j++)
			helphez = (helphez * t[i]) % delta;
		helpi /= 1000;
		tavan = 1;
		for(int j = 0; j < helpi; j++)
			tavan = ((tavan * helphez) % delta);
		tavan = (tavan * help) % delta;
		sum = (tavan + sum) % delta;
	}
	cout << sum << endl;
}