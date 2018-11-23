#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <bits/stdc++.h>
#define mp make_pair


using namespace std;


typedef pair<int, int> pii;
const int maxn = 50 * 1000;
string s;
int cost[2][maxn + 100];
int m = 0, o = 0, c = 0, ao, ac, n;
vector<int> pos;
bool used[maxn + 100];
set <pii> d;
deque <pii> keeper;



int abs(int a)
{
	if(a < 0)
		return -1 * a;
	return a;
}
int main()
{
	cin >> s;
	n = s.length();
	for(int i = 0; i < n; i++)
		if(s[i] == '?')
			m++;
		else
		{
			pos.push_back(i);
			if(s[i] == '(')
				o++;
			else
				c++;
		}
	for(int i = 0; i < m; i++)
	{	
		int x, y;
		scanf("%d %d", &x, &y);
		keeper.push_back(mp(x,y));
	}
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '?')	
		{
			cost[0][i] = keeper.front().first;	
			cost[1][i] = keeper.front().second;
			keeper.pop_front();
			d.insert(mp(cost[1][i] - cost[0][i],i));
		}
	}
	if(abs(o - c) > m)
	{
		cout << -1 << endl;
		return 0;
	}
	ao = n / 2 - o;
	ac = n / 2 - c;
	int sum = 0, pos;
	for(int i = 0; i < s.length(); i++)
	{
		if(!used[i])
		{
			if(s[i] == '?')
			{
				if(ao == 0)
				{
					s[i] = ')';
					sum += cost[1][i];
					ac--;
				}
				else
				{
					sum += cost[0][i];
					s[i] = '(';
					ao--;
					if(ac > 0)
					{
						pii temp = *d.begin();
						while(used[temp.second] || temp.second <= i)
						{					
	                                                d.erase(d.begin());
							temp = *d.begin();
						}
						d.erase(d.begin());
						sum += cost[1][temp.second];
						s[temp.second] = ')';
						used[temp.second] = true;
					ac--;
					}							
				}
				
			}
			else
			{
				if(s[i] == '(')
				{
					if(ac > 0)
                                        {       
                                                pii temp = *d.begin();
						while(used[temp.second] || temp.second < i)
						{					
	                                                d.erase(d.begin());
							temp = *d.begin();
						}
                                                d.erase(d.begin());
                                                sum += cost[1][temp.second];
						used[temp.second] = true;
						s[temp.second] = ')';
                                                ac--;
                                        }
				}
			}

		}
	}
	cout << sum << endl;
	cout << s << endl;
}
