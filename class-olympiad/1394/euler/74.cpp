#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

const long long maxn = 1000 * 1000;
long long factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
long long d[maxn * 10];

long long findsum(long long a)
{
	long long sum = 0;
	while(a)
	{
		sum += factorial[a % 10];
		a /= 10;
	}
	return sum;
}

long long findsize(long long a)
{
	set <long long> mylist;
	int flag = true;
	while(flag)
	{
		int temp = mylist.size();
		mylist.insert(a);
		a = findsum(a);
		if(mylist.size() == temp)
			flag = false;
	}
	return mylist.size();
}

int main()
{
	long long co = 0;
	for(long long i = 1; i <= maxn; i++)
	{
		//cout << i << endl;
		//cout << "d[999] = " << d[999] << endl;
		//cout << findsize(i) << "  " << i  << endl;
		if(findsize(i) == 60)
		{
			//cout << i << endl;
			co++;
		}
	}
	cout << co << endl;
}