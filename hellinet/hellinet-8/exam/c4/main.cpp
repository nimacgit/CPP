#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string a;
    cin>>a;
    vector<char> b;
    int n=3;
    int z=0;
    int s=0;
    int sign=1;
    for(int i=0; i<a.length() && n!=0; i++)
    {
        if(a[i]=='/')
            n--;
        if(n==1 && sign==1)
        {
            s=i;
            sign=0;
        }
        z++;
    }
    n=0;
    for(int i=0; i<z; i++)
    {
        if(a[i]=='.')
            n++;
    }
    if(s!=0)
        s++;
    for(int i=s; i<a.length(); i++)
    {
        if(a[i]=='.')
            n--;
        if((n==1 || n== 0) && a[i]=='/')
            n=-1;
        if((n==1 && a[i]!='.') || n== 0)
        {
           b.push_back(a[i]);
        }

    }
    for(int i=0;i<b.size();i++)
        cout<<b[i];
    return 0;
}
