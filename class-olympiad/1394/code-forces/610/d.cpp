#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;

typedef pair<int,int > pie;
const int maxn =  1000 * 100;
vector <pair<pie, pie> > h, v, myh, myv;
int n;
long long sum = 0;

bool comp(pair<pie, pie> a, pair<pie, pie> b)
{
	if(a.f.f == b.f.f)
		return a.f.s < b.f.s;
	return a.f.f < b.f.f;
}

pair<pie, pie> rev(pair<pie, pie> t)
{
	swap(t.f.f, t.f.s);
	swap(t.s.f, t.s.s);
	return t;
}


void addh(pair<pie, pie> myp)
{
	if(h.size() == 0)
	{
		sum += myp.s.f - myp.f.f + 1;
		h.push_back(myp);
	}
	else
	{
		if(h[h.size() - 1].f.s != myp.f.s)
		{
			h.push_back(myp);
			sum += myp.s.f - myp.f.f + 1;
		}
		else
		{
			if(h[h.size() - 1].s.f < myp.f.f)
			{
				sum += myp.s.f - myp.f.f + 1;
				h.push_back(myp);
			}
			else
			{
				sum -= h[h.size() - 1].s.f - h[h.size() - 1].f.f + 1;
				pair<pie, pie> t = mp(mp(h[h.size() - 1].f.f, myp.f.s), mp(max(h[h.size() - 1].s.f, myp.s.f), myp.s.s));
				h.pop_back();
				h.push_back(t);
				sum += t.s.f - t.f.f + 1;
			}

		}	
	}
}

void addv(pair<pie, pie> myp)
{
	if(v.size() == 0)
	{
		sum += myp.s.f - myp.f.f + 1;
		v.push_back(myp);
	}
	else
	{
		if(v[v.size() - 1].f.s != myp.f.s)
		{
			sum += myp.s.f - myp.f.f + 1;
			v.push_back(myp);
		}
		else
		{
			if(v[v.size() - 1].s.f < myp.f.f)
				v.push_back(myp);
			else
			{
				sum -= v[v.size() - 1].s.f - v[v.size() - 1].f.f + 1;
				pair<pie, pie> t = mp(mp(v[v.size() - 1].f.f, myp.f.s), mp(max(v[v.size() - 1].s.f, myp.s.f), myp.s.s));
				v.pop_back();
				v.push_back(t);
				sum += t.s.f - t.f.f + 1;
			}

		}	
	}
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp1, temp2, temp3, temp4;
		scanf("%d %d %d %d", &temp1, &temp2, &temp3, &temp4);
		if(temp1 == temp3)
			myv.push_back(mp(mp(min(temp2,temp4), temp1), mp(max(temp2,temp4), temp3)));
		else
			myh.push_back(mp(mp(min(temp3, temp1), temp2), mp(max(temp1, temp3), temp4)));
	}
	sort(myh.begin(), myh.end(), comp);
	sort(myv.begin(), myv.end(), comp);
	for(int i = 0; i < myh.size(); i++)
		addh(myh[i]);
	for(int i = 0; i < myv.size(); i++)
		addv(myv[i]);
	cerr << " hsize " << h.size() << endl;
	for(int i = 0; i < h.size(); i++)
		cerr << " i =" << i << "  | " << h[i].f.f << " " << h[i].f.s << " " << h[i].s.f << " " << h[i].s.s << endl;
	cerr << " vsize " << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
		cerr << " i =" << i << "  | " << v[i].f.f << " " << v[i].f.s << " " << v[i].s.f << " " << v[i].s.s << endl;
	cerr << sum << endl;

	for(int i = 0; i < h.size(); i++)
	{
		int pos = lower_bound(v.begin(), v.end(), rev(h[i])) - v.begin();
		int l = pos;
		cerr << " pos " << pos << " i:" << i << " h: " << h[i].f.f << " " << h[i].f.s << " " << h[i].s.f << " " << h[i].s.s << endl;
		while(v[l].f.f <= h[i].f.s && v[l].s.f >= h[i].f.s && l < v.size())
		{
			sum--;
			l++;
		}
		if(pos < v.size() - 1)
			l = pos + 1;
		while(v[l].f.f <= h[i].f.s && v[l].s.f >= h[i].f.s && l < v.size())
		{
			sum--;
			l++;
		}
		if(pos > 0)
			l = pos - 1;
		while(v[l].f.f <= h[i].f.s && v[l].s.f >= h[i].f.s && l < v.size())
		{
			sum--;
			l++;
		}

	}
	cout << sum << endl;






}
