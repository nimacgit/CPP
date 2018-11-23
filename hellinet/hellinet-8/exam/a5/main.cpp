#include <iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    int sum=0;
    for(;a>0;a/=10)
        sum+=a%10;
    for(int i=1; i<=9; i++)
        if((sum+i)%9==0)
        {
            cout << i << endl;
            return 0;
        }
    return 0;
}
