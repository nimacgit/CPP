#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;



int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;	
	long long a, b;
	cin >> a >> b;
	for(int i = 1; i < n; i++)
	{
		long long temp1, temp2;
		cin >> temp1 >> temp2;
		a = max(a, temp1);
		b = min(b, temp2);
	}
	if(a <= b)
		cout <<"YES" << endl << a << endl;
	else
		cout <<"NO" << endl;
}
