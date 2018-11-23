#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    string b;
    cin>>a;
    cin>>b;

    if(a.length() == b.length() )
    {
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='e' || a[i]=='a' || a[i]=='u' || a[i]=='i' || a[i]=='o')
            {
                if(b[i]=='e' || b[i]=='a' || b[i]=='u' || b[i]=='i' || b[i]=='o');
                else
                {
                   cout<<"NO"<<endl;
                   return 0;
                }
            }
        }
        for(int i=0;i<b.length();i++)
        {
            if(b[i]=='e' || b[i]=='a' || b[i]=='u' || b[i]=='i' || b[i]=='o')
            {
                if(a[i]=='e' || a[i]=='a' || a[i]=='u' || a[i]=='i' || a[i]=='o');
                else
                {
                   cout<<"NO"<<endl;
                   return 0;
                }
            }
        }
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
        return 0;
    }
    return 0;
}


