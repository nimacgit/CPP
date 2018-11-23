#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>


using namespace std;

const int maxn = 100 * 1000;
int a[maxn + 100], b[maxn + 100];
long long poss[maxn + 100];
long long n, k;
long long ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000 * 1000, 1000 * 1000 * 10, 1000 * 1000 * 100, 1000 * 1000 * 1000};
const long long mo = 1000 * 1000 * 1000 + 7;

long long find(int x)
{
	long long y = 0;
	y = (ten[k] - 1) / a[x] + 1;	
	long long c = (a[x] - ten[k - 1] * b[x] % a[x]) % a[x];
	if(c <= ten[k - 1])
		y -= (ten[k - 1] - 1 - c) / a[x] + 1; 
	return y;
}


int main()
{
	cin >> n >> k;
	for(int i = 0; i < n / k; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n / k; i++)
		scanf("%d", &b[i]);
	for(int i = 0; i < n / k; i++)
		poss[i] = find(i);
	long long sum = poss[0];
	for(int i = 1; i < n / k; i++)
	{
		sum = (sum * poss[i]) % mo;
	}
	cout << sum << endl;
}
