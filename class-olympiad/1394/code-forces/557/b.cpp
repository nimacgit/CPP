#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 1000 * 100;
int peo[2 * maxn + 10];
long long n;
double w;

long long minimum(long long a, long long b)
{
	if(2 * a <= b)
		return 2 * a;
	return b;
}

int main()
{
	cin >> n >> w;
	for(int i = 0; i < 2 * n; i++)
		scanf("%d", &peo[i]);
	sort(peo, peo + 2 * n);
	long long minim = minimum(peo[0], peo[n]);
	if(minim * n * 3 <= 2 * w)
	{
		if((minim * n * 3) % 2 == 1)
			cout << (minim * n * 3) / 2 << ".5" << endl;
		else
			cout << (minim * n * 3) / 2 << endl;
	}
	else
		cout << w << endl;
}