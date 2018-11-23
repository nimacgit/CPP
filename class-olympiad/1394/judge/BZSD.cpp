#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 * 1000 + 3;
int d[maxn], n, a[maxn], parent[maxn], maxi, di[maxn];

/*int find(int start, int end, int num)
{
	//cerr << " start " << start << " end " << end << " number " << num << endl;
	if( end == start)
		return end;
	if(d[(end + start) / 2] > num)
		find(start, (end + start) / 2, num);
	else 
		find((end + start) / 2 + 1, end, num);
}
*/
void lis()
{
	for(int i = 1; i <= n; i++)
		d[i] = -1;
	d[1] = a[0];
	di[1] = 0;
	di[0] = -1;
	parent[0] = -1;
	maxi = 1;
	for(int i = 1; i < n; i++)
	{
		int found = upper_bound(d + 1, d + maxi + 1, a[i]) - d;
		//cout << found << " i= " << i << " maxi " << maxi << endl;
		d[found] = a[i];
		if(found > maxi)
			maxi++;
		di[found] = i;
		parent[i] = di[found - 1];
		//cout <<  " 1parenti " << parent[i] << endl;
		//parent[found + 1] = i;
	}
}

void print(int i)
{
	if(i != -1 )
	{
		//cout << i << " " << parent[i] << endl;
		print(parent[i]);
		printf("%d ", a[i]);	
	}

}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	//	printf("%d ", a[i]);
	}
	//cout << endl;
	lis();
	cout << maxi << endl;
	print(di[maxi]);
	cout << endl;
}