#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    int a[n+1];
    string name;
    int va=0;
    for(int i=1;i<=n;i++)
    {
        cin>>name;
        for(int i=0;i<name.length();i++)
            if(name[i]=='a' || name[i]=='u' || name[i]=='e' || name[i]=='i' || name[i]=='o')
        va++;
        if(va%2==0)
            a[i]=0;
        else
            a[i]=1;
        va=0;
    }
    ofstream o;
    o.open("197.out",ios::out);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
            o<<"DOKHTAR";
        if(a[i]==1)
            o<<"PESAR";
        o<<endl;
    }


}

