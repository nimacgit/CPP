#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int maxn  = 100;
int n;
string s;
int finds[26][26];
vector <int> use;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		use.clear();
		for(int j = 0; j < s.length() && use.size() < 3; j++)
		{

			bool flag = false;
			for(int k = 0; k < use.size(); k++)
				if(use[k] == s[j] - 'a')
					flag = true;
			if(!flag)
				use.push_back(s[j] - 'a');
		}
		if(use.size() < 3)
		{
			if(use.size() == 2)
			{
				finds[use[0]][use[1]] += s.size();
				finds[use[1]][use[0]] += s.size();
			}
			else
			{
				for(int j = 0; j < 26; j++)
				{
					finds[use[0]][j] += s.size();
					finds[j][use[0]] += s.size();
				}
				finds[use[0]][use[0]] -= s.size();

			}
		}
	}
	int maxim = 0;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(finds[i][j] > maxim)
				maxim = finds[i][j];
		}
	}
	cout << maxim << endl;
}
