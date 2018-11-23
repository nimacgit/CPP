#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n][2];
	for(int i = 0; i < n;i++)
	{
		a[i][1] = 100;
		a[i][2] = 0;
	}
	int shot1,hit1;
	for(int i = 0; i < m; i++)	
	{
		cin >> shot1 >> hit1;
		if(a[shot1 - 1][1] > 0)
		{
			if(a[hit1 - 1][1] > 0)
			{
				a[shot1 - 1][2] += 3;
			}
			a[hit1 - 1][1] -= 8;
		}
	}
	for(int i = 0; i < n; i++)	
	{
		if(a[i][1] > 0)
			a[i][2] += (a[i][1] / 2);
	}
	for(int i = 0; i < n; i++)	
	{
		cout << a[i][1] << " " << a[i][2] << endl;
	}
}