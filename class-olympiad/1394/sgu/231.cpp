#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

bool isprime(int a)
{
	for(int i = 2; i * i <= a; i++)
	{
		if(a % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 2; i < n - 1; i++)
	{
		if(isprime(i))
			if(isprime(i + 2))
			{
				v.push_back(2);
				v.push_back(i);
			}

	}
	cout << v.size() / 2 ;
	for(int i = 0; i < v.size(); i++)
		if(i % 2 == 0)
			cout << endl << v[i];
		else
			cout << " " << v[i];
	cout << endl;

	
}