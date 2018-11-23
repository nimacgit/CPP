#include <iostream>

using namespace std;

const int maxn = 1000 * 10 + 2;

int a[maxn];

int main()
{
	int n;
	cin >> n;
	a[1] = 1;
	int maxcol = 1;
	int maxt;
	for(int i = 2 ; i <= n; i++)
	{
		maxt = 0;
		for(int j = 1; j <= i / 2; j++)
		{
			if(i % j == 0 )
				if(maxt == 0)
					maxt = a[j];
				else
					if(maxt < a[j])
						maxt = a[j];
		}
		a[i] = maxt + 1;
		if(maxt + 1 > maxcol)
			maxcol = maxt + 1;
	}
	cout << maxcol << endl;
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
}