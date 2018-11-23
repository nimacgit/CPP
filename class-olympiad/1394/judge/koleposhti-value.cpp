#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 1000 + 1;
//dyn[n][w] show that if we can fill bag with n first w with W weight or not;
int dyn[maxn][maxn * 10];
// a keeps ai(weight)
int a[maxn];
// val kees the values
int val[maxn];

void kool(int n, int w)
{
	for(int i = 1; i <= n; i++)	
	{
		for(int j = 1; j <= w; j++)
		{
			if(j >= a[i])
			{
				if(dyn[i - 1][j] > dyn[i - 1][j - a[i]] + val[i])
					dyn[i][j] = dyn[i - 1][j];
				else
					dyn[i][j] = dyn[i - 1][j - a[i]] + val[i];
			}
			else
				dyn[i][j] = dyn[i - 1][j];
		}
	}
}


int main()
{
	int sizw, sizn;
	scanf("%d", &sizw);
	scanf("%d", &sizn);
	for(int i = 1; i <= sizn; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= sizn; i++)
		scanf("%d", &val[i]);
	int maximum = 0;
	kool(sizn, sizw);
	for(int i = sizw; i >= 1; i--)
	{
		if(dyn[sizn][i] > maximum)
			maximum = dyn[sizn][i];
	}
	if(maximum == 0)
		cout << -1 << endl;
	else
		cout << maximum << endl;


	//if(!kool(sizn, sizw))
	//	cout << -1 << endl;
	/*
	for(int i = 0; i <= sizn; i++)
	{
		for(int j = 0; j <= sizw; j++)
			cout << dyn[i][j] << "  ";
		cout << endl;
	}	
	*/
}