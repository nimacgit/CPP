#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

vector <int> myvector;
const int maxn = 1000 + 1;
int a[maxn];
int val[maxn];
bool choozea[maxn];
int sizn,sizw;
long long sum = 0;
int maxnum = -1;
 
bool kool(int n, int w)
{
	if(w == 0)
	{
		sum = 0;
		for(int i = 1; i <= sizn; i++)
		{
			if(choozea[i] == 1)
				sum += val[i];
		}
		if(maxnum == -1)
			maxnum = sum;
		else
			if(maxnum < sum)
				maxnum = sum;
		return true;
	}
	if(w < 0)
		return  false;
	if(n < 1)
		return  false;
	bool flag1 = false, flag2 = false;
	choozea[n] = 1;
	flag2 = kool(n - 1, w - a[n]);
	choozea[n] = 0;
	flag1 = kool(n - 1, w);
	return (flag1 || flag2);
}


int main()
{
	cin >> sizw >> sizn;
	for(int i = 1; i <= sizn; i++)
		cin >> a[i];
	for(int i = 1; i <= sizn; i++)
		cin >> val[i];
	kool(sizn, sizw);
	cout << maxnum << endl;
/*	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= w; j++)
			cout << koooole[i][j] << "  ";
		cout << endl;
	}*/
}