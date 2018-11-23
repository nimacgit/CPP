#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 1000 * 1000;
bool mark[maxn + 10];
vector<long long> numprime[maxn + 10];

void find()
{
	for(long long i = 2; i <= maxn; i++)
	{
		if(!mark[i])
		{
			for(long long j = 1; j * i <= maxn; j++)
			{
				mark[i * j] = true;
				numprime[i * j].push_back(i);
			}
		}
	}
}

double findphi(long long i)
{
	long long fnum = i, fdenum = 1, num, denum;
	for(long long j = 0; j < numprime[i].size(); j++)
	{
		denum = numprime[i][j];
		num = denum - 1;
		fnum *= num;
		fdenum *= denum;
	}
	return fnum/fdenum;

}


int main()
{
	find();
	double maximum = 0;
	long long maxim = 0;
	for(double i = 2; i <= maxn; i++)
	{
		double temp = findphi(i);
		if(i / temp >= maximum)
		{
			maximum = i / temp;
			maxim = i;
		}
	}
	cout << maxim  << "  " << maximum << endl;	

}