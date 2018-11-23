#include <bits/stdc++.h>


using namespace std;

const int maxn  = 1000 * 100;
const int maxl = 20;
int n, q;
int a[maxn + 100];
int t[maxn + 100][maxl];
long long pw[maxl], lg[maxn + 100];

#define err(X) cerr<<#X << ":" <<X<<"\n";

void pre()
{
	pw[0] = 1;
	for(int i = 1; i < maxl; i++)
		pw[i] = pw[i - 1] * 2;
	lg[1] = 0;
	for(int i = 2; i < maxn; i++)
		lg[i] = lg[i / 2] + 1;
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j < lg[n] + 1; j++)
		{
			if(j == 0)
				t[i][j] = a[i];
			else
				t[i][j] = min(t[i][j - 1], t[i + pw[j - 1]][j - 1]);
		}
	}
}

int st(int l, int r)
{
	int pwtwo = lg[r - l + 1];
	return min(t[l][pwtwo], t[r - pw[pwtwo] + 1][pwtwo]);

}



int main()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		scanf("%d" , &a[i]);
	pre();
	for(int i = 0; i < q; i++)
	{
		int templ, tempr;
		scanf("%d %d", &templ, &tempr);
		cout  << st(templ-1, tempr-1) << endl;
	}
	return 0;

}
