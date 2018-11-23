#include <iostream>

using namespace std;

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int startw[12] = {1,4,4,7,2,5,7,3,6,1,4,6};

int main()
{
	int d,m;
	cin >> d >> m;
	if(m > 12 || d > days[m - 1])
	{
		cout << "Impossible" << endl;
		return 0;
	}
	if((startw[m - 1] + d -1) % 7 == 0)
		cout << "7" << endl;
	else
		cout << (startw[m - 1] + d -1) % 7 << endl;
}