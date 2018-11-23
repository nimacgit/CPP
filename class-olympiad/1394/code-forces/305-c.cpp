#include <iostream>
#include <set>
using namespace std;

const long long maxn = 1000 * 100;
long long n;
set <long long> myset;

int main()
{
	cin >> n;
	int temp;
	int maximum = 0;
	int co = 0;
	for(long long i = 0; i < n; i++)
	{
		cin >> temp;
		if(temp > maximum)
			maximum = temp;
		if(myset.find(temp) != myset.end())
		{
			int i = temp;
			while(myset.find(i) != myset.end())
			{
				myset.erase(i);
				i++;
			}
			myset.insert(i);
			if(i > maximum)
				maximum = i;
		}
		else
			myset.insert(temp);
	}
	cout << maximum - myset.size() + 1 << endl;
}