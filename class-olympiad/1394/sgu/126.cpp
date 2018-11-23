#include <iostream>
#include <cmath>

using namespace std;

int a,b;
int f, g, h;
int move = 0;
void gcd()
{
	f = a;
	g = b;
	h = a % b;
	while(h)
	{
		f = g;
		g = h;
		h = f % g;
	}
}

int main()
{
	cin >> a >> b;
	if(a == 0 || b == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if(a < b)
	{
		swap(a,b);
	}
	gcd();
	a /= g;
	b /= g;
	if((a + b) % 2 != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	if((a + b) % b == 0)
	{
		if(log2(a + b) == int(log2(((a + b) / b))))
		{
			cout << log2((a + b) / b) + move << endl;
			return 0;
		}
	}
	while(a % 2 == 1 && b % 2 == 1)
	{
		if(a < b)
		{
			swap(a,b);
		}
		a -= b;
		b *= 2;
		move++;
		gcd();
		a /= g;
		b /= g;
		if((a + b) % 2 != 0)
		{
			cout << -1 << endl;
			return 0;
		}
		if((a + b) % b == 0)
		{
			if(log2(a + b) == int(log2(((a + b) / b))))
			{
				cout << log2((a + b) / b) + move << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}