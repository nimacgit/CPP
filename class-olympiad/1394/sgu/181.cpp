#include <iostream>

using namespace std;

long long x,a,b,g,m,k,A;


int main()
{
	cin >> A >> a >> b >> g >> m >> k;
	x = A;
	if(k == 0)
	{
		cout << x << endl;
		return 0;
	}
	long long arr[1000 + 20];
	x = arr[0] = (((a * (x * x)) + (b * x) + g) % m);
//	cout << " WE " << endl;
	long long rep = -1;
	for(long long i = 2; i <= k; i++)
	{
//		cout << " E " << endl;
		x = (((a * (x * x)) + (b * x) + g) % m);
		arr[i - 1] = x;
		for(long long j = 0; j < i - 1; j++)
		{
			if(x == arr[j])
			{
				rep = j;
			}

		}
		if(rep != -1)
		{
/*			for(int j = 0; j < i; j++)
			{
				cout << j << " " << arr[j] << endl;
			}
			cout << rep  << "i = " << i << " k " << k << endl;
*/			k -= (rep + 1);
			cout << arr[(k % (i - rep - 1)) + rep] << endl;
			return 0;
		}
	}
	cout << x << endl;

}