#include <iostream>
using namespace std;
long long rev(long long a)
{
	long long b = 0;
	for(;a > 0; a /= 10)
		b = b * 10 + a % 10;
	return b;
}
bool isly(long long a)
{
	for(int i = 1; i <= 50; i++)
		if(a + rev(a) == rev(a + rev(a)))
			return false;
		else
			a = a + rev(a);
	return true;
}
int main()
{
	int sum = 0;
	for(long long a = 0; a <= 10000; a++)
		if(isly(a))
			sum++;
	cout << sum << endl;
}