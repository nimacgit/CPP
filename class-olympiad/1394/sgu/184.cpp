#include <iostream>

using namespace std;

int p,m,c,k,r,v;
int min1,min2,min3,min4;

int main()
{
	cin >> p >> m >> c >> k >> r >> v;
	min1 = p / k;
	min2 = m / r;
	min3 = c / v;
	min4 = min(min1, min2);
	cout << min(min4, min3) << endl;

	
}