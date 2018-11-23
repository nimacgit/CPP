#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[4];
	int b[4];
	int c[4];
	int d[3];
	cin >> a [1] >> a [2] >> a [3];
	cin >> b [1] >> b [2] >> b [3];
	cin >> c [1] >> c [2] >> c [3];
	sort(b + 1,b + 4);
	sort(c + 1,c + 4);
	sort(a + 1,a + 4);
	d[0] = a[2];
	d[1] = b[2];
	d[2] = c[2];
	sort(d, d + 3);
	cout << d[1] << endl;


	
}