#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, pair<int,int> > pie;
const int maxn =  1000 * 1000;
int seg[4 * maxn + 100], all[4*maxn + 100];
int n, k;
vector<pie> p;
vector<int> q;

int find_sum(int start, int end,int s,int e, int segnum){
	if (end < s || e < start) 
		return 0;
	if (s <= start  &&  end <= e)
		return seg[segnum];
	int eshterak = min(end, e) - max(start, s) + 1;
	int mid = (start + end)/2;
	return  find_sum(start, mid , s, e, 2 * segnum) 
		+ find_sum(mid + 1, end, s, e, 2 * segnum + 1) + all[segnum] * eshterak;

}

void add(int start, int end, int s, int e, int segnum){

	if (start < s || e < end)  
		return;
	if ( s <= start &&  end <= e)
		all[segnum]++;
	else {
		int mid = (start + end)/2;
		add(start, mid, s, e, 2 * segnum);

		add(mid + 1, end, s, e, 2 * segnum + 1);
	}

	seg[segnum] = seg[2*segnum] + seg[2*segnum+1] + all[segnum]*(end - start + 1);
}






int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		p.push_back(mp(l, r));
		q.push_back(l);
		q.push_back(r);
	}
	sort(q.begin(), q.end());




}
