#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 1000 * 100 + 10;
vector <int> d[maxn + 100];
int n;
vector <int> que;
int fin[maxn + 100];
int a[maxn + 100];

int main()
{
	for(int i = 0; i < maxn; i++)
		fin[i] = -1;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		d[temp].push_back(i + 1);
	}
	for(int i = 0; i < maxn; i++)
	{
		if(i < n)
		{
			if(d[i + 1].size() == 0)
			{
				if(!que.empty())
				{
					fin[i + 1] = que.back();
					a[que.back()] = i + 1;
					que.pop_back();
				}
			}
			else
			{
				fin[i + 1] = d[i + 1].back();
				a[d[i + 1].back()] = i + 1;
				d[i + 1].pop_back();
				while(!d[i + 1].empty())
				{
					que.push_back(d[i + 1].back());
					d[i + 1].pop_back();
				}
			}
		}
		else
			while(!d[i + 1].empty())
				{
					que.push_back(d[i + 1].back());
					d[i + 1].pop_back();
				}
	}
	//cerr << "be" << endl;
	for(int i = 0; i < n; i++)
		if(fin[i + 1] == -1)
		{
			fin[i + 1] = que.back();
			a[que.back()] = i + 1;
			que.pop_back();
		}
	for(int i = 0; i < n; i++)
		printf("%d ", a[i + 1]);
	cout << endl;
}