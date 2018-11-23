#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



using namespace std;

int n, k;
vector <pair<int,int> > points;
bool row[20];
int notuse = 0;
int sum = 0;


void make(int i)
{
	if(i == n)
	{
		sum++;
		return;
	}
	for(int j = 0; j < n && points.size() < k; j++)
	{
		if(!row[j])
		{
			bool flag = true;
			for(int l = 0; l < points.size() && flag; l++)
			{
				if((points[l].first - i)  ==  (points[l].second - j) || (points[l].first - i) == -1 * (points[l].second - j))
					flag = false;
			}
			if(flag)
			{
				row[j] = true;
				points.push_back(make_pair(i, j));
				make(i + 1);
				points.pop_back();
				row[j] = false;
			}
		}
	}
	if(n - k - notuse > 0)
	{
		notuse++;
		make(i + 1);
		notuse--;
	}
}




int main()
{
	cin >> n >> k;
	if(k > n)
	{
		cout << 0 << endl;
		return 0;
	}
	if(k == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	if(k == 1)
	{
		cout << n * n << endl;
		return 0;
	}
	make(0);
	cout << sum << endl;
	
}