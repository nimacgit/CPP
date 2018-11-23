#include <iostream>

using namespace std;

int i = 0;

int pos(int x, int y, int x2, int y2)
{
	int b;
	if(x == x2)
	{
		b = (y + y2) /2;
	}
	else
	{
		if(x != 0)
		{
			b = (((double)y * (double)x2 / (double)x) - y2) / (((double)x2 / (double)x) - 1);
			cout << " b= " << b << endl;
		}
		else
		{
			if(x2 != 0)
			{
				b = (((double)y2 * (double)x / (double)x2) - y) / (((double)x / (double)x2) - 1);
				cout << " b= " << b << endl;
			}
			else
				return 0;
		}
	}
	if(b > 0)
	{
		if((y > 0 && y2 < 0) || (y < 0 && y2 > 0))
		{
			cout << " 1 " << b << " " << x << " " << x2 << endl;
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if((y > 0 && y2 <= 0) || (y < 0 && y2 > 0))
		{
			cout << " 2 " << b << " " << x << " " << x2 << endl;
			return 2;
		}
		else
			return 0;
	}
}


int main()
{
	int x1, x2, x3, y1, y2, y3;
	int sum = 0;
	for(; i < 1000; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		bool flagR = false, flagl = false;
		if(pos(x1, y1, x2, y2) == 1 || pos(x2, y2, x3, y3) == 1 || pos(x3, y3, x1, y1) == 1)
			flagR = true;
		if(pos(x1, y1, x2, y2) == 2 || pos(x2, y2, x3, y3) == 2 || pos(x3, y3, x1, y1) == 2)
			flagl = true;
		if(flagl && flagR)
		{
			cout << i << endl;
			sum++;
		}
		/*
		if(x1 * y2 > y1 * x2 && x2 * y3 > x3 * y2 && x3 * y1 > x1 * y3)
		{
			sum++;
			cout << i << endl;
		}
		else
			if(!(x1 * y2 > y1 * x2) && !(x2 * y3 > x3 * y2) && !(x3 * y1 > x1 * y3))
			{
				cout << i << endl;
				sum++;
			}
		*/
	}
	cout << sum << endl;
}