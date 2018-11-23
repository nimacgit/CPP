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



const long long maxn= 1000 + 100;
long long sum, k, n, a[maxn];


long long fn(long long m)
{
	long long b = 0;
	while(m)
	{
		b += m % 10;
		m /= 10;
	}
	if(b > 9)
		return fn(b);
	return b;

}


int main()
{
	cin >> k;
	for(long long i = 0; i < k; i++)	
	{
		cin >> n;
		sum = 1;
		for(long long j = 0; j < n; j++)
			cin >> a[n - j - 1];
		for(long long j = 0; j < n; j++)
		{
			sum = sum * a[j] + 1;
			if(j == n - 1)
				sum--;
			if(sum > 9)
				sum = fn(sum);
		}
		cout << sum << endl;
	}
}