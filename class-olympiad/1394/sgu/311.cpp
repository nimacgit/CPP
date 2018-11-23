/*
 * =====================================================================================
 *
 *       Filename:  311.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۱۳ ۱۵:۵۶:۰۰
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>


using namespace std;






const int maxn = 1000 * 1000;
long long price[maxn + 100];
long long seg[4 * maxn + 1000];
long long q, n , c;
set <int> myset;
string s;

void add(const int &start, const int &end, const int &ind, const int &val, const int &segnum)
{
	if(start <= ind && ind <= end)
	{
		seg[segnum] += val;
		if(start != end)
		{
			int mid = (start + end) / 2;
			add(start, mid, ind, val, 2*segnum);
			add(mid + 1, end, ind, val, 2 * segnum + 1);
		}
	}
}

long long getsum(const int &start, const int &end, const int &s, const int &e, const int &segnum)
{
	if(start > e || end < s)
		return 0;
	if(start >= s && end <= e)
		return seg[segnum];
	int mid = (start + end)/2;
	return getsum(start, mid, s, e, 2*segnum) + getsum(mid + 1, end, s, e, 2 * segnum + 1);
}


int main()
{
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> s;
		if(s[0] == 'A')
		{
			scanf("%d %d", &n, &c);
			price[c] += n;
			myset.push_back(c);
		}
		else
		{
			scanf("%d %d", &n, &c);
			int flag = true;
			while(!myset.empty() && flag)
			{
				
			}
			
		}
	}
}

