#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

typedef pair<int, int> pii;
#define mp make_pair 

const int maxn = 1000;
int change = 0, pos = -1, get = 0, dir = 1;
int a[maxn + 100];
bool use[maxn + 100];
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
	{
		bool flag = false;
		int j = pos + dir;
		for(;j >= 0 &&  j < n && (a[j] > get || use[j]) ;)
		{
			j += dir;
		}
		if(j != n && j != -1)
		{
			flag = true;
			use[j] = true;
			pos = j;
			get++;
		}
		if(!flag)
		{
			//cerr << " ho " << i << endl;
			change++;
			dir *= -1;
			for(j = pos; (a[j] > get || use[j]) && j >= 0 && j < n; )
			{
				j += dir;
			}
			use[j] = true;
			pos = j;
			get++;
		}
	}
	cout << change << endl;
}