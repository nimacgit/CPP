#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n < 9)
	{
		cout << "0" << endl;
		return 0;
	}
	if(n == 9)
	{
		cout << "8" << endl;
		return 0;
	}
	for(int i = 10; i <= n; i++)
	{
		if(i == 10)
			cout << "72" ;
		else
			cout << "0";
	}
	cout << endl;
}