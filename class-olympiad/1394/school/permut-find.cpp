#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;


const int maxn = 1000 * 100;
int inp[maxn + 100], tree[maxn + 100];
int n;



void update(int i, int val)
{
	for(; i <= n; i += i & (-i))
		tree[i] += val;
}




int findsum(int x)
{
	int sum = 0;
	for(; x > 0; x -= x & (-x))
		sum += tree[x];
	return sum;
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &inp[i]);
		tree[i + 1] = 0;
		update(i + 2, 1);
	}
	tree[1] = 0;
	for(int i = 0; i < n; i++)
	{
		int use = inp[n - i - 1];
		cout << findsum(n - use + 1) << endl;
		update(n - use + 2, 1);
		update(1, -1);
	}

	

}