#include <iostream>

using namespace std;

int main()
{
	int a,b,c,d,c1,c2,d1,d2,p,q;
	cin >> a >> b >> c >> d;
	if(a*b > c*d)
	{
		if((double(a) / c) > (double(b) / d))
		{
			c1 = b * c;
			c2 = d;
			d1 = b * d;
			d2 = d;
		}
		else
		{
			c1 = a * c;
			c2 = c;
			d1 = a * d;
			d2 = c;
		}
	}
	else
	{
		if((double(a) / c) > (double(b) / d))
		{
			c1 = b * c;
			c2 = d;
			d1 = b * d;
			d2 = d;
		}
		else
		{
			c1 = a * c;
			c2 = c;
			d1 = a * d;
			d2 = c;
		}
	}
	p = a*b*d2*c2 - c1*d1;
	q = b * a * d2 * c2;
	if(p == 0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	int a1 = q,b1 = p,c3 = q % p;
	//cout << p << "  " << q << endl;
	for(; c3 != 0 ; c3 = a1% b1)
	{
		a1 = b1;
		b1 = c3;
		c3 = a1 % b1;
		//cout << c3 << endl;
	}
	//cout << b1 << endl;
	p /= b1;
	q /= b1;
	cout<<p<<"/"<<q<<endl;
	
}