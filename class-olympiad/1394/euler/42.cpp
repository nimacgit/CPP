#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 10000;
bool mark[maxn * maxn];

int main()
{
	int sum = 0;
	for(int i = 1; i < maxn; i++)
	{
		sum += i;
		mark[sum] = true;
	}
	string s;
	int count = 0;
	cin >> s;
	while(s != "2")
	{
		sum = 0;
		for(int i = 0; i < s.length(); i++)
			sum += s[i] - 'A' + 1;
		if(mark[sum])
			count++;
		cin >> s;
	}
	cout << count << endl;
}