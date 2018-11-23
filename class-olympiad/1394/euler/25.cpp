#include <iostream>

using namespace std;

const int maxn = 1000;
bool pos[maxn];

int findl(int a)
{
	for(int i = 0; i < maxn; i++)
		pos[i] = false;
	int mod = 1;
	int i = 0;
	while(!pos[mod])
	{
		i++;
		pos[mod] = true;
		mod = (mod * 10) % a;
	}
	return i + 1;
}

int main()
{
	int maxind = 0;
	int maxim = 0;
	for(int i = 2; i < 1000; i++)
	{
		int temp = findl(i);
		cout << i << "  " << temp << endl;
		if(temp > maxim)
		{
			maxim = temp;
			maxind = i;
		}
	}
	cout << maxind << endl;
}