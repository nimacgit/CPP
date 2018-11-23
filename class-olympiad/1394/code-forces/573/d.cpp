#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

const int maxn = 100000;
int d1[maxn + 100], d2[maxn + 100];
int n;
int h[maxn + 100];


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> h[i];
	d1[0] = 1;
	for(int i = 1; i < n; i++)
	{
		if(h[i] > d1[i - 1])
			d1[i] = d1[i - 1] + 1;
		else if(h[i] == d1[i - 1])
			d1[i] = h[i];
		else
			d1[i] = h[i];
	}
	d2[n - 1] = 1;
	for(int i = n - 2; i >= 0; i--)
	{
		if(h[i] > d2[i + 1])
			d2[i] = d2[i + 1] + 1;
		else if(h[i] == d2[i + 1])
			d2[i] = h[i];
		else
			d2[i] = h[i];

	}
	int maxim = 0;
	for(int i = 0; i < n; i++)
	{
		if(min(d1[i], d2[i]) > maxim)
			maxim = min(d1[i], d2[i]);
	}
	cout << maxim << endl;
}