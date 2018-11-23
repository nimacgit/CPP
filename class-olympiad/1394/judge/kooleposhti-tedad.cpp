#include <iostream>
#include <algorithm>
using namespace std;


int dynamic[1000 + 2][10000 + 2];
int a[1000 + 2];



void ways(int n,int w)
{
	for(int j = 1; j <= w; j++)
		dynamic[0][j] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= w; j++)
		{
			if(j - a[i] >= 0)
				dynamic[i][j] = (dynamic[i - 1][j] + dynamic[i - 1][j - a[i]]) % 100000000;
			else
				dynamic[i][j] = dynamic[i - 1][j] % 100000000;
		}
	}

}

int main()
{
	int w,n;
	cin >> w >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dynamic[0][0] = 1;
	ways(n, w);
	cout << (dynamic[n][w]) % (100000000) << endl;
	/*for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= w; j++)
			cout << dynamic[i][j] << "  ";
		cout << endl;
	}*/




}