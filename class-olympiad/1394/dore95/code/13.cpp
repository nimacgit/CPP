#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;
const int maxn = 1e5 + 100;
int a[3*maxn];
int n;
int dl[maxn], dr[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		dl[i] = i - 1;
		dr[i] = i + 1;
		cin >> a[i];
	}
	for(int i = n - 1; i >= 0; i--)
		if(a[i] > a[0])
		{
			dl[0] = i;
			i = -1;
		}
	for(int i = 0; i < n; i++)
		if(a[i] > a[n - 1])
		{
			dr[n - 1] = i;
			i = 2 * n;
		}
	for(int i = 1; i < n - 1; i++)
	{
		while(a[i] > a[dl[i]])
			dl[i] = dl[dl[i]];
		while(a[i] > a[dr[i]])
			dr[i] = dr[dr[i]];
	}
	long long ans = 0;
	while(a[0] > a[dr[0]])
		dr[0] = dr[dr[0]];
	while(a[n - 1] > a[dl[n - 1]])
		dl[n - 1] = dl[dl[n - 1]];
	for(int i = 0; i < n; i++)
	{
		if(dl[i] != dr[i])
		{
			if(dl[i] < i)
				ans += i - dl[i] - 1;
			else
				ans += n - dl[i] - 1 + i;
			if(dr[i] > i)
				ans += dr[i] - i - 1;
			else
				ans += n - i - 1 + dr[i];
		}
		else
		{
			ans += n - 1;
			if(dl[i] != i)
				ans--;
		}
	}
	cout << ans << endl;


}
