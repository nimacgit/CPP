#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1000 * 100 + 1000;
int a[maxn], b[maxn];
int n, k;
long long ten[11] = {1, 10, 100, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10};
long long ans;
long long mo = 1e9 + 7;

long long calc(int pos)
{
	long long temp = ten[k + 1] / a[pos];
	long long m = ten[k] % a[pos];
	long long ne = (ten[k] * b[pos]) % a[pos];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n/k; i++) cin >> a[i];
	for(int i = 0; i < n/k; i++) cin >> b[i];
	ans = 1;
	for(int i = 0; i < n/k; i++) ans = (ans * calc(i)) % mo;
	cout << ans << endl;

}
