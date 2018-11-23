#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int a[n+1];
    long long int rev=0;
    long long int num;
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        for(;num!=0;num/=10)
            rev=rev*10+num%10;
        a[i]=rev;
        rev=0;
    }
    ofstream o;
    o.open("17.out",ios::out);
    for(int i=1;i<=n;i++)
    {
        o<<a[i];
        o<<endl;
    }


}
