#include <iostream>

using namespace std;

long long int n;
const int delta = 90907;
const int maxn = 7801389;
int yek()
{
	return n % 10;
}
int dah()
{
	return (n / 10) % 10;
}
int sad()
{
	return (n / 100) % 10;
}
int hez()
{
	return (n / 1000) % 10;
}
int dahhez()
{
	return (n / 10000) % 10;
}
int sadhez()
{
	return (n / 100000) % 10;
}
int mil()
{
	return (n / 1000000) % 10;
}



bool isrond()
{
	if(yek() == dah() && yek() == sad() && hez() == dahhez() && hez() == sadhez())
		return true;
	if(yek() == dah() && yek() == sad() && sadhez() == dahhez() && mil() == sadhez())
		return true;
	if(sad() == dah() && hez() == sad() && mil() == dahhez() && dahhez() == sadhez())
		return true;
	if(yek() == dah() && yek() == sad() && hez() == dahhez() && mil() == sadhez())
		return true;
	if(yek() == dah() && hez() == sad() && hez() == dahhez() && mil() == sadhez())
		return true;
	if(yek() == dah() && hez() == sad() && mil() == dahhez() && dahhez() == sadhez())
		return true;
	if(yek() == sad() && yek() == dahhez() && yek() == mil() && dah() == hez() && dah() == sadhez())
		return true;
	return false;

}

int main()
{
	int sum = 0;
	for(n = 1000000; n < maxn; n++)
		if(isrond())
		{
			//cout << n << endl;
			sum++;
		}
	cout << (sum * sum ) % delta << endl;

}