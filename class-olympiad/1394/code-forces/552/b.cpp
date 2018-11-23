#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>



using namespace std;

int main()
{
	int n;
	cin >> n;
	long long zarib = 1;
	long long tedad = 9;
	long long sum = 0;
	while(n >= tedad)
	{
		sum += tedad * zarib;
		n -= tedad;
		zarib++;
		tedad *= 10;
	}
	if(n > 0)
		sum += n * zarib;
	cout << sum << endl;


}