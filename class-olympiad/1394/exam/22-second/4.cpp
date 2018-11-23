#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

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
	for(int i = 0; i < maxn; i++)
		for(int j = 1; j < maxn - i; j++)
			if(d[j] > d[j - 1])
			{
				swap(num[j], num[j - 1]);
				swap(d[j], d[j - 1]);
			}
	for(int i = 0; i < maxn; i++)
		cout << num[i] << endl;
	cout << endl;
	for(int i = 0; i < maxn; i++)
		number += num[i];
	cout << made() << endl;
	number.clear();
	for(int i = maxn - 1; i >= 0; i--)
		number += num[i];
	cout << made() << endl;
}