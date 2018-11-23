#include <iostream>
#include <string>

using namespace std;

const int maxn = 1400 + 2;

int d[2][maxn];
int a[maxn][maxn];
string temp;
int n, m;
int maxmor = -2;

void bigsq()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(i == 1 || j == 1)
			{
				if(a[i][j] == 1)
					d[i % 2][j] = 1;
			}
			else
			{
				if(a[i][j] == 0)
					d[i % 2][j] = 0;
				else
				{
					d[i % 2][j] = min(d[(i - 1) % 2][j], d[i % 2][j - 1]);
					//cout <<" so " << d[i % 2][j] << " ";
					if(d[(i - 1) % 2][j - 1] >= d[i % 2][j])
					{
					//	cout << "be " ;
						d[i % 2][j]++;
					}
					if(d[i % 2][j] == 0)
						d[i % 2][j] = 1;
				}
			}
			if(maxmor == -2)
				maxmor = d[i % 2][j];
			else
				if(d[i % 2][j] > maxmor)
					maxmor = d[i % 2][j];
			//cout << d[i % 2][j] << " ";
		}
		//cout << endl;
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> temp;
		for(int j = 1; j <= m; j++)
			a[i][j] = temp[j - 1] - 48;
	}
	bigsq();
	cout << maxmor << endl;

}