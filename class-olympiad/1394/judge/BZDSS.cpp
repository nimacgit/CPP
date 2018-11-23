#include <iostream>

using namespace std;

const int maxn = 1000000 + 3;
int d[maxn];
int a[maxn];
int maxvalue;
int maxindex;
int par[maxn];

void zir(int n)
{
	for(int i = 2; i <= n; i++)
	{
		int maximumj = -1;
		int maxm = -1;
		for(int j = i -1; j > 0; j--)
		{
			if(a[j] <= a[i])
			{
				if(maxm == -1)
				{
					maxm = d[j];
					maximumj = j;
				}
				else if(d[j] > maxm)
				{
					maxm = d[j];
					maximumj = j;
				}
			}
		}
		if(maxm == -1)
			maxm = 0;
		d[i] = maxm + 1;
		par[i] = maximumj;
		if(d[i] > maxvalue)
		{
			maxvalue = d[i];
			maxindex = i;
		}
	}
}

void print(int i)
{
	if( i == 0)
		return;
	print(par[i]);
	cout << a[i] << " ";

}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	d[1] = 1;
	maxvalue = 1;
	maxindex = 1;
	zir(n);
	cout << maxvalue << endl;
	print(maxindex);
	cout << endl;
	/*for(int i = 0; i <= n; i++)
		cout << d[i] << " ";
	cout << endl;
	*/

}