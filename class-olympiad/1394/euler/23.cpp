#include <iostream>
#include <vector>

using namespace std;

const int maxn = 28123;
vector<int> isnotubuntu;
bool mark[maxn + 100];

bool find(int n)
{
	int sum = 0;
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			if(i != n/i)
				sum += i + n/i;
			else
				sum += i;
		}
	}
	if(sum - n > n)
		return true;
	else
		return false;
}


int main()
{
	for(int i = 2; i <= maxn; i++)
	{
		if(find(i))
		{
			isnotubuntu.push_back(i);
			for(int j = 0; j < isnotubuntu.size(); j++)
			{
				if(i + isnotubuntu[j] <= maxn + 10)
					mark[i + isnotubuntu[j]] = true;
			}
			mark[i] = true;
		}
	}
	
	long long sum = 0;
	for(int i = 1; i < maxn; i++)
		if(!mark[i])
			sum += i;
	cout << sum << endl;
}