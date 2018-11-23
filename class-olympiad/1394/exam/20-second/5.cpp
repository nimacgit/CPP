#include <iostream>
#include <string>

using namespace std;
string n;
string sum;
const int maxn = 5000;
bool mark[maxn];

void plusnum()
{
	n[0]++;
	for(int i = 0; n[i] == '2'; i++)
	{
		if(i == n.length() - 1)
		{	
			n[i] = '0';
			n += '1';
		}
		else
		{
			n[i] = '0';
			n[i + 1]++;
		}
	}
}

int main()
{
	n = "0";
	for(int i = 1; i < 1389; i++)
	{
		plusnum();
	}
	for(int i = 1389; i <= 2010; i++)
	{
		plusnum();
		sum += n;
	}
	int pos = 1;
	mark[1] = true;
	int l = 0, N = 0;
	for(int i = 0; i < sum.length(); i++)
	{
		int npos;
		if(sum[i] == '0')
			npos = 2 * pos;
		else
			npos = 2 * pos + 1;
		if(mark[npos])
			pos = npos;
		else
		{
			pos = 1;
			N++;
			mark[npos] = true;
			if(npos % 2 == 0)
			{
				//cerr << " be " << endl;
				if(mark[npos + 1])
					l++;
			}
			else
			{
				//cerr << " ce " << mark[npos - 1] << endl;

				if(mark[npos - 1])
					l++;
			}
		}
	}
	cout << l << " " << N << endl;
	/*
	for(int i = 1, temp = 1; i <= 6842; i++)
	{
		if(i == temp)
		{
			cout << endl;
			temp *= 2;
		}
		cout << mark[i];
		if(i % 2 == 1)
			cout << " ";
	}
	*/

}