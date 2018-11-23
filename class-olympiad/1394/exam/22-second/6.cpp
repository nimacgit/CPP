#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <map>

using namespace std;

const long long maxn = 16;
string num[maxn];
map <string, bool> mark;
string number;

long long made()
{
	long long sum = 0;
	for(long long i = 0; i < number.length(); i++)
		sum = sum * 2 + (number[i] - '0') % 2;
	return sum;

}

void make(int i)
{
	int temp = i;
	while(temp > 0)
	{
		num[i - 1] += (temp % 2) + '0';
		temp /= 2;
	}
	reverse(num[i - 1].begin(), num[i - 1].end());
	mark[num[i - 1]] = false;
}

int find(int pos)
{
	//cout << pos << endl;
	long long sum = 0;
	string thisstr;
	if(pos == number.length())
		return 1;
	for(int i = 0; i < 6 && pos + i < number.length(); i++)
	{
		thisstr = number.substr(pos, i + 1);
		if(mark.find(thisstr) != mark.end() && !mark[thisstr])
		{
			mark[thisstr] = true;
			sum += find(pos + i + 1);
			mark[thisstr] = false;			
		}
	}
	return sum;
}

int main()
{
	for(long long i = 0; i < maxn; i++)
		make(i + 1);
	cerr << "check " << endl;
	number = "100001000100100110101010110111100110110111101111111111";
	/*for(long long i = 0; i < maxn; i++)	
		cout << num[i] << endl;
	cout << number.length() << endl;
	cout << made() << endl;
	cout << number << endl;
	*/cout << find(0) << endl;

}