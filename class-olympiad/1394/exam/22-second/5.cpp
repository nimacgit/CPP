#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;

const int maxn = 10;
string num[maxn];
int d[maxn];
string number;

long long made()
{
	long long sum = 0;
	for(int i = 0; i < number.length(); i++)
		sum = sum * 2 + (number[i] - '0') % 2;
	return sum;

}

void make(int i)
{
	int temp = i;
	while(temp > 0)
	{
		num[i - 1] += (temp % 2) + '0';
		if((temp % 2) == 0)
			d[i - 1]++;
		temp /= 2;
	}
	reverse(num[i - 1].begin(), num[i - 1].end());
}

int main()
{
	for(int i = 1; i <= maxn; i++)
		make(i);
	set <int> myset;
	for(int i = 0; i < maxn; i++)
		number += num[i];
	myset.insert(made());
	while(next_permutation(num,num + maxn))
	{
		number.clear();
		for(int i = 0; i < maxn; i++)
			number += num[i];
		myset.insert(made());
	}
	cout << myset.size() << endl;
}