#include <iostream>

using namespace std;

int sum = 0;

void f(int a)
{
	int alfa = 0;
	int temp = 4 * a + 1;
	while(temp >= 1)
	{
		temp /= 5;
		alfa ++;
	}
	//cout << a << endl;
	int five = 1;
	for(int i = 1; i < alfa; i++)
		five *= 5;
	sum += five;
	a -= (five - 1) / 4;
	//cout << five << "  " << sum << endl;
	if(a > 0)
		f(a);

}


int main()
{
	long long q;
	cin >> q;
	f(q);
	int temp = 0;
	for(int i = 5; sum / i > 0; i *= 5)
		temp += sum / i;
//	cout << sum << "  " << temp << endl;
	if(temp == q)
		cout << sum << endl;
	else
		cout << "No solution" << endl;




	
}