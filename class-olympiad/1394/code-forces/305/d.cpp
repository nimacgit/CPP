#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>



using namespace std;


const int maxn = 2 * 1000 * 100;

int ai[2][maxn], d[2][maxn];
int n;
int order[maxn];



bool compare(int a, int b)
{
	if(ai[0][a] < ai[0][b])
		return true;
	return false;
}


int abs(int a)
{
	if(a < 0)
		return -1 * a;
	return a;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		ai[1][i] = i;
	for(int i = 0; i < n; i++)
		scanf("%d", &ai[0][i]) ;
	sort(ai[1], ai[1] + n, compare);
	for(int i = 0; i < n; i++)
		cerr << ai[1][i] << " ";
	int lastuse = 0, toi;
	for(int i = 0; i < n; i++)
	{
		if(ai[1][i] >= n / 2)
			toi = abs(n - ai[1][i]);
		else
			toi = ai[1][i];
		int k = 0; 
		for(int j = toi - lastuse; j >= 0; j--)
		{
			cerr << ai[0][ai[1][i]] << " be " << toi << endl;
			order[lastuse] = ai[0][ai[1][i]];
			lastuse++;
		}
	}
	for(int i = n - 1; i >= 0; i--)
		cout << order[i] << " ";
	cout << endl;

}