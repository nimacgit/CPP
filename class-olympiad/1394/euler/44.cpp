#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 * 100;
bool mark[10 * maxn];
vector <int> v;

void find()
{
	int sum = 1, temp = 4;
	while(sum < maxn)
	{
		sum += temp;
		mark[sum] = true;
		v.push_back(sum);
		temp += 3;
	}
	while(sum < 2 * maxn)
	{
		sum += temp;
		mark[sum] = true;
		temp += 3;
	}
}

int main()
{
	find();
	int diff = 99999999;
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = i + 1; j < v.size(); j++)
		{
			if(mark[v[j] - v[i]] && mark[v[j] + v[i]])
			{
				cout << " be " << endl;
				if(v[j] - v[i] < diff)
					diff = v[j] - v[i];
			}
		}
	}
	cout << diff << endl;
}