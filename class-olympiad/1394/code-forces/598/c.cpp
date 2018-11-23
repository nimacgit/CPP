#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>
#define mp make_pair
#define f first
#define s second
using namespace std;

typedef pair<int, int> pii;
const int maxn = 100 * 1000;
int n;
vector< pair<pii, int> > pos, neg;


int main()
{
	cin >> n;
	for(int i = 0; i < n ; i++)
	{
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if(t1>=0)
			pos.push_back(mp(mp(t2, t1), i));
		else
			neg.push_back(mp(mp(t2,t1), i));
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());
	cout.precision(20);
	cout << fixed;
	int posf, poss, negf, negs;
	double nex , mpos = 22, temp;
	if(pos.size() > 1)
	{
		next = atan((double)pos[1].f.f/ (double)pos[1].f.s);
		posf = pos[0].s; 
		poss = pos[1].s;
		mpos = atan((double)pos[0].f.f/ (double)pos[1].f.s) - next;
	}
	for(int i = 2; i < pos.size(); i++)
	{
		temp = atan((double)pos[i].f/ (double)pos[i].s);
		if(next - temp < mpos)
		{
			mpos = next - temp;
			posf = pos[i -1].s;
			poss = pos[i].s;
		}
		next = temp;
	}
	if(neg.size() > 1)
	{
		next = atan((double)neg[1].f/ (double)neg[1].s);
		posf = neg[0].s; 
		poss = neg[1].s;
		mpos = atan((double)neg[0].f/ (double)neg[1].s) - next;
	}
	for(int i = 2; i < neg.size(); i++)
	{
		temp = atan((double)neg[i].f/ (double)neg[i].s);
		if(next - temp < mpos)
		{
			mpos = next - temp;
			posf = neg[i - 1].s;
			poss = neg[i].s;
		}
		next = temp;
	}
	if(neg.size() > 0 && pos.size() > 0)
	{
		if(pos[0].f >= 0 && neg[0].f >= 0 && !(pos[0].f == 0 && neg[0].f == 0) &&  atan((double)pos[0].f/ (double)pos[0].s) - atan((double)neg[0].f/ (double)neg[0].s) < mpos)
		{
			mpos = atan((double)pos[i].f/ (double)pos[i].s) - atan((double)neg[0].f/ (double)neg[0].s);
			posf = pos[0].s;
			poss = neg[0].s;
		}
		if(atan((double)pos[i].f/ (double)pos[i].s) - atan((double)neg[0].f/ (double)neg[0].s) < mpos)
		{
			mpos = atan((double)pos[i].f/ (double)pos[i].s) - atan((double)neg[0].f/ (double)neg[0].s);
			posf = pos[0].s;
			poss = neg[0].s;
		}

	}




}
