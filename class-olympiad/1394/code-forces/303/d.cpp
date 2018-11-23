#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int maxn = 1000 * 100 + 4;
vector <int> v;
int a[maxn];
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] >= sum)
		{
			v.push_back(i);
			sum += a[i];
		}
	}
	cout << v.size() << endl;
}