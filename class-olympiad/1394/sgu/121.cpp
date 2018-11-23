#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 100 + 2;
int d[maxn][maxn];
bool connect[maxn][maxn];
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int temp = 10; temp != 0;)
		{
			scanf("%d", &temp);
			if(temp != 0)
			{
				connect[i][temp] = true;
				connect[temp][i] = true;
			}
		}
	}
	

	
}