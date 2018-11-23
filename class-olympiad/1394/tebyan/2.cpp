#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++)
		cin >> b[i] >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - i - 1; j++)
			if(a[j] < a[j + 1])
			{
				swap(a[j], a[j + 1]);
				swap(b[j], b[j + 1]);
			}
	for(int i = 0; i < n; i++)
		cout << b[i] << endl;
	
}