#include <iostream>

using namespace std;

const int maxn = 100 + 3;
int t[maxn];
int l[maxn];

int main()
{
	int n;
	cin >> n;
	int maxt;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 0; i < n; i++)
		cin >> l[i];
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n - 1; j++)
			if(l[j + 1] > l[j])
			{
				swap(l[j + 1], l[j]);
				swap(t[j + 1], t[j]);
			}
	}
	//for(int i = 0; i < n ; i++)
		//cout << l[i] << "  " << t[i] << endl;
	int sum = 0;
	maxt = t[0] + l[0];
	sum = t[0];
	for(int i = 1; i < n; i++)
	{
		if(sum + t[i] + l[i] > maxt)
			maxt = sum + t[i] + l[i];
		sum += t[i];
	}
	cout << maxt << endl;
		
}