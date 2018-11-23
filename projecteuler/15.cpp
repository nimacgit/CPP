#include <iostream>

using namespace std;

int main()
{
	int a=1;
	for(int i=40,k=20;i>20 && k>0;i--,k--)
		a*=(i/k);
	cout<<a<<endl;
}