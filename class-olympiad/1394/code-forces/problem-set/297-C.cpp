#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 1000 * 100 + 3;
int s[maxn];
pair <int, int> sorted[maxn];
int n;
int one[maxn];



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
		sorted[i] = make_pair(s[i], i);
	}
	sort(sorted, sorted + n);
	for(int i = (n + 2) / 3; i < 2 * ((n + 2) / 3) && i < n; i++)
		one[sorted[i].second] = i - (n + 2) / 3  + (n + 2) / 3;
	for(int i = 2 * ((n + 2) / 3); i < n; i++)
		one[sorted[i].second] = n - i;
	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
		printf("%d ", one[i]);
	cout << endl;
	for(int i = 0; i < n; i++)
		printf("%d ", s[i] - one[i]);
	cout << endl;
}