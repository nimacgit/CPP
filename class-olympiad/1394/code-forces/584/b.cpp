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
int n;

const long long maxn = 1000 * 1000 * 1000 + 7;
const int maxim = 1000 * 100 + 100;
long long finda[maxim];
bool use[maxim];

long long A(int a)
{
	if(a == 0)
		return 1;
	if(!use[a])
	{
		use[a] = true;
		return finda[a] = (27 * A(a - 1)) % maxn;
	}
	else
		return finda[a];
}

long long g(int a)
{
	if(a == 0)
		return 0;
	return ((7 * g(a - 1) % maxn) + (20 * A(a - 1) % maxn)) % maxn;
}

int main()
{
	cin >> n;
	cout << g(n) << endl;

	
}