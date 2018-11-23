#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

string s;
const int maxn = 1390;
const int delta = 28813;
bool mark[maxn + 4];
vector <int> v[maxn];

int main()
{
	int k = 0;
	for(int i = 1; i <= 1390; i++)
	{
		if(!mark[i])
		{
			v[k].push_back(i);
			for(int j = 2; j * i <= 1390; j *= 2)
			{
				mark[i * j] = true;
				v[k].push_back(i * j);
			}
			k++;
		}
	}
	long long sum = 1;
	for(int i = 0; i < k; i++)
		sum = (sum * v[i].size()) % delta;
	cout << sum << endl;

}