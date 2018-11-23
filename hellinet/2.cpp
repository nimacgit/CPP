#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;



int main()
{
    string s;
    cin>>s;
    int l=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='L')
            l++;
    }
    l/=2;
    int m=s.length()+1;
    if(m-1>m-l)
        cout<<m-l<<endl;
    else
        cout<<m-1<<endl;
}

