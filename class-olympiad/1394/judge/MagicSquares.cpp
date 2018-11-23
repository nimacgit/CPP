#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int a[40320];
int b[8] = {1,2,3,4,5,6,7,8};

void make()
{
	a[0] = 12345678;
	for(int i = 1; i < 40320; i++)
	{
		a[i] = 0;
		next_permutation(b, b + 8);
		for(int j = 0 ; j < 8; j++)
			a[i] = a[i] * 10 + b[j];
		//cerr << a[i] << endl;
	}
}

















const int maxn = 40320;
vector<int> myque;
bool mark[maxn];
int n = 12345678;
int h[maxn];
int parent[maxn][2];
int newn;

int yek()
{
	return n % 10;
}
int dah()
{
	return (n / 10) % 10;
}
int sad()
{
	return (n / 100) % 10;
}
int hez()
{
	return (n / 1000) % 10;
}
int dahhez()
{
	return (n / 10000) % 10;
}
int sadhez()
{
	return (n / 100000) % 10;
}
int mil()
{
	return (n / 1000000) % 10;
}
int dahmil()
{
	return (n / 10000000) % 10;
}





int change(int a)
{
	if(a == 1)
	{
		int temp = n;
		newn = 0;
		while(temp > 0)
		{
			newn = newn * 10 + temp % 10;
			temp /= 10;
		}
		return newn;
	}
	else
	{
		if(a == 2)
		{
			return hez() + 10 * yek() + 100 * dah() + 1000 * sad() + 10000 * sadhez() + 100000 * mil() + 1000000 * dahmil() + 10000000 * dahhez();
		}
		else
		{
			return yek() + 10 * sad() + 100 * sadhez() + 1000 * hez() + 10000 * dahhez() + 100000 * mil() + 1000000 * dah() + 10000000 * dahmil();
		}

	}
}


void print(int i, int k)
{
 	if(i != -1)
 	{
 		print(parent[i][0], parent[i][1]);
 		if(k == 1)
 		{
 			cout << "A";
 		}
 		else
 		{
 			if(k == 2)
 				cout << "B";
 			else
 				cout << "C";
 		}
 	}
}


int main()
{
	make();
	for(int i = 0; i < maxn; i++)
		h[i] = -1;
	int num = 0;
	for(int i = 1000 * 1000 * 10, temp; i > 0; i /= 10)
	{
		cin >> temp;
		num += i * temp;
	}
	if(num == 12345678)
	{
		cout << 0 << endl;
		return 0;
	}
	myque.push_back(n);
	h[0] = 0;
	mark[0] = true;
	parent[0][0] = -1;
	parent[0][1] = -1;
	for(int i = 0; i < (int)myque.size(); i++)
	{
		n = myque[i];
		int posv = lower_bound(a, a + 40320, n) - a;
		for(int j = 1; j < 4; j++)
		{
			int u = change(j);
			//cerr << u << endl;
			int pos = lower_bound(a, a + 40320, u) - a;
			//cerr << posv << endl;
			if(!mark[pos])
			{
				myque.push_back(u);
				parent[pos][0] = posv;
				parent[pos][1] = j;
				mark[pos] = true;
				h[pos] = h[posv] + 1;
				if(num == u)
				{
					cout << h[pos] << endl;
					print(parent[pos][0], parent[pos][1]);
					cout << endl;
					return 0;
				}
			}
		}
	}

}




