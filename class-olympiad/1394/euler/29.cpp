#include <iostream>

using namespace std;

int pow(int i, int b)
{
	int temp = i;
	for(; b > 1; b--)
		temp *= i;
	return temp;
}
int main()
{
	long long ted = 0;
	for(int i = 0; i < 355000; i++)
	{
		long long sum = 0;
		for(int temp = i; temp > 0; temp /= 10)
			sum += pow(temp % 10, 5);
		if(sum == i)
		{
			cout << i << endl;
			ted += i;
		}
	}
	cout << ted << endl;
}