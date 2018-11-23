#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>



using namespace std;

string s;
vector<int> mul, num;

int main()
{
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '*')
			mul.push_back(i);
		else
			if(s[i] != '+')
				num.push_back(s[i] - '0');
	}
	long long sum = 0;
	int k = 0;
	for(int i = 0; i < num.size(); i++)
	{
		if(k > mul.size() || (mul[k] - 1) / 2 != i)
			sum += num[i];
		else
		{
			k++;
			sum += num[i] * num[i + 1];
			i++;
		}
	}
	for(int )
	cout << sum << endl;



}