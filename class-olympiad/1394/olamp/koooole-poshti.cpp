#include <iostream>

using namespace std;

const int maxn = 1000;
bool koooole[maxn][maxn];
bool use[maxn][maxn];
int a[maxn];

bool kool(int n, int w)
{
	if(w == 0)
		return koooole[n][w] = use[n][w] = true;
	if(w < 0)
		return koooole[n][w] = false;
	if(n < 1)
	{
		use[n][w] = true;
		return koooole[n][w] = false;
	}
	if(!use[n - 1][w])
		kool(n - 1, w);
	if(!use[n - 1][w - a[n]])
		kool(n - 1, w - a[n]);
	use[n][w] = true;
	if(w - a[n] < 0)
		return koooole[n][w] = koooole[n - 1][w];
	else
		return koooole[n][w] = (koooole[n - 1][w] || koooole[n - 1][w - a[n]]);
}

int main()
{
	int n,w;
	cin >> n >> w;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	kool(n, w);
	if(kool(n, w))
		cout << "YES  " << endl; 
	else
		cout << "NO   " << endl;


}