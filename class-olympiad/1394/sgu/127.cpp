#include <iostream>

using namespace std;

int a[9];
int b[9];

int main()
{
	int n, k;
	cin >> k >> n;
	if(n == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	int page = 2;
	for(int i = 0, temp; i < n; i++)
	{
		cin >> temp;
		temp = temp - (temp % 1000);
		temp /= 1000;
		a[temp]++;
		//cout << "  " << temp  << endl;
		if(a[temp] == k)
		{
			a[temp] = 0;
			page++;
		}
	}
	for(int i = 0; i < 9; i++)
	{
		if(a[i + 1] != 0)
			page++;
	}
	cout << page << endl;
}