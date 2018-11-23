#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

long long sum = 0, count = 0, maxim=0, maxindex=0;
string a,b;



void findmil()
{
	int h1,h2,m1,m2,s1,s2,ms1,ms2;
	//cout << " a= " << a << " b= " << b << endl;
	h1 = atoi(a.substr(0,2).c_str());
	h2 = atoi(b.substr(0,2).c_str());
	m1 = atoi(a.substr(3,2).c_str());
	m2 = atoi(b.substr(3,2).c_str());
	s1 = atoi(a.substr(6,2).c_str());
	s2 = atoi(b.substr(6,2).c_str());
	ms1 = atoi(a.substr(9,3).c_str());
	ms2 = atoi(b.substr(9,3).c_str());
	//cerr << " h1= " << h1 << " h2= " << h2 << " m1= " << m1 << " m2= " << m2 << " s1= " << s1 << " s2= " << s2 << " ms1= " << ms1 << " ms2= " << ms2 << endl;
	h1 = h2 - h1;
	m1 = m2 - m1;
	s1 = s2 - s1;
	ms1 = ms2 - ms1;
	h1 *= 3600 * 1000;
	m1 *= 60 * 1000;
	s1 *= 1000;
	sum += ms1 + s1 + h1 + m1 + 1;
	/*if(ms1 + s1 + h1 + m1 + 1 > maxim)
	{
		maxim = ms1 + s1 + h1 + m1 + 1;
		maxindex = count + 1;
	}
	if(maxim == 1433352631)
	{
	s	cout << " a " << a << " b " << b << endl;
		cout << " h1= " << h1 << " h2= " << h2 << " m1= " << m1 << " m2= " << m2 << " s1= " << s1 << " s2= " << s2 << " ms1= " << ms1 << " ms2= " << ms2 << endl;
	}
	count++;
	cout << " count= " <<  count << " " << "sum = " << ms1 + s1 + h1 + m1 + 1 << endl;
	*/
}

bool issame(int num, string s)
{
	int temp = 0;
	while(num > 0)
	{
		temp = temp * 10 + num % 10;
		num /= 10;
	}
	int k = 0;
	while(temp > 0)
	{
		if(temp % 10 != (int)s[k] - 48)
			return false;
		else
		{
			temp /= 10;
			k++;
		}
	}
	return true;
}



int main()
{
	cin >> a;
	cin >> a;
	cin >> b;
	cin >> b;
	findmil();
	cin >> b;
	for(int i = 2; i <= 1076; i++)
	{
		while(!issame(i, b))
		{
			cin >> b;
		}
		cin >> a;
		cin >> b;
		cin >> b;
		findmil();
		cin >> b;
	}
	cout << sum << endl;
}