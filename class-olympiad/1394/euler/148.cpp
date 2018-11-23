#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const long long maxn = 1e9;
vector<int> myvec;
long long row = 3;
long long co = 3;


int main()
{

	myvec.push_back(2);
	while(row <= maxn)
	{
		/*		int temp = myvec[0];
				int n = 0;
				for(int i = 1; i < myvec.size(); i++)
				{
				int temp2 = myvec[i];
				myvec[i] = (temp + myvec[i]) % 7;
				if(myvec[i] != 0)
				n++;
				temp = temp2;
				}
				n+=2;
				myvec.push_back(1);
				co+=n;
				cout << " row " << row << endl;
				cout << "         " <<  n << "   " << co << endl;
		 */
		long long temp = 1;
		for(int i = 0; i < myvec.size(); i++)
			temp *= (myvec[i] + 1);
		if(maxn - row > 7 && myvec[0] == 0)
		{
			row+=6;
			co += (long long)28*temp;
			if(myvec.size() == 1)
				myvec.push_back(0);
			myvec[1]++;
		}
		else
		{
			co += temp;
			myvec[0]++;
			if(myvec[0] > 6)
			{
				myvec[0] = 0;
				if(myvec.size() == 1)
					myvec.push_back(0);
				myvec[1]++;
			}
		}
		for(int i = 1; i < myvec.size() - 1 && myvec[i] > 6; i++)
		{
			myvec[i] = 0;
			myvec[i + 1]++;
		}
		if(myvec[myvec.size() - 1] > 6)
		{
			myvec[myvec.size() - 1] = 0;
			myvec.push_back(1);
		}
		row++;
	}
	cout << co << endl;
}
