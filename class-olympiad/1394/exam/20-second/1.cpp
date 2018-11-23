#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000 * 1000;
vector <int> good_numbers;
double sum_devis[maxn];


bool compare(int a, int b)
{
	if(b * sum_devis[a] < sum_devis[b] * a)
		return true;
	return false;
}


int summagh(int n)
{
	int sum = 0;
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			if(i != n / i)
			{
				sum += i;
				sum += (n / i);
			}
			else
				sum += i;
		}
	}
	return sum - n;
}

int main()
{
	int n = 2;
	int magh;
	while(n < maxn)
	{
		magh = summagh(n);
		if(magh >= n)
		{
			good_numbers.push_back(n);
			sum_devis[n] = magh;
		}
		n++;
	}
	sort(good_numbers.begin(), good_numbers.end(), compare);
	cout << good_numbers[good_numbers.size() - 13] << endl;
}