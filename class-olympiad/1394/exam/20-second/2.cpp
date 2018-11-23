#include <iostream>

using namespace std;

int x[4], y[4];
int nx[4], ny[4];
bool stop[4]

int abs(int a)
{
	if(a < 0)
		return -1 * a;
	return a;
}


bool near(int a, int b)
{
	if(abs(x[b] - x[a]) <= 1 && abs(y[b] - y[a]) <= 1)
		return true;
	return false;
}



bool change(int a, int b)
{
	bool ch = false;
	if(!near(a,b) && !stop[a])
	{
		ch = true;
		nx[a] = x[a] + (x[b] - x[a]) / abs(x[b] - x[a]);
		ny[a] = y[a] + (y[b] - y[a]) / abs(y[b] - y[a]);
	}
	else
		stop[a] = true;
	return ch;
}

int main()
{
	nx[0] = x[0] = 1024;
	ny[0] = y[0] = 2010;
	nx[1] = x[1] = -1381;
	ny[1] = y[1] = 138;
	nx[2] = x[2] = 1;
	ny[2] = y[2] = 2010;

	long long s = 0;
	bool flag = true;
	while(flag)
	{
		flag = false;
		bool f1 = change(0, 1);
		bool f2 = change(1, 2);
		bool f3 = change(2, 0);
		flag = (f1 || f2 || f3);
		//cout << s << " 1= " ;
		for(int i = 0; i < 3; i++)
		{
			x[i] = nx[i];
			y[i] = ny[i];
		//	cout << x[i] << " " << y[i] << " " << i + 1 << "= ";
		}
		//cout << endl;
		s++;
	}
	cout << s << endl;


}