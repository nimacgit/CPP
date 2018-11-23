#include <iostream>
#include <time.h>

using namespace std;

const int maxn = 1000;
bool koooole[maxn][maxn];
int a[maxn];

bool kool(int n, int w)
{
	koooole[0][0] = true;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= w; j++)
		{	
			if(j >= a[i])
				koooole[i][j] = (koooole[i - 1][j] || koooole[i - 1][j - a[i]]);
			else
				koooole[i][j] = koooole[i - 1][j];
		}
	}
}

int main()
{
	int n,w;
	cin >> n >> w;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	kool(n, w);
	if(koooole[n][w])
		cout << "YES  " << t2 - t1 << endl; 
	else
		cout << "NO   " << t2 - t1 << endl;


}