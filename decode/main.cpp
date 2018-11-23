#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
    int n,m;
    int p=1,q=1;
    string s;
    while(p!=0 && q!=0)
    {
        cin>>m>>n;
        cin>>s;
        cin>>p>>q;
        for(int i=0; i<s.length(); i++)
            s[i]-=7;
        int a[m][n];
        for(int i=0,k=0; i<m; i++)
            for(int j=0; j<n; j++,k++)
            {
                a[i][j]=s[k];
            }

        string st=s;
        for(int i=0,k=0; i<(n/2)+1; i++)
        {
            if(k<s.length())
            {
                for(int j=i; j<n-i; j++,k++)
                {
                    st[k]=char(a[i][j]);
                }
            }
            if(k<s.length())
            {
                for(int j=i+1; j<m-i; j++,k++)
                {
                    st[k]=char(a[j][n-i-1]);
                }
            }
            if(k<s.length())
            {
                for(int j=i+1; j<n-i; j++,k++)
                {
                    st[k]=char(a[m-i-1][n-j-1]);
                }
            }
            if(k<s.length())
            {
                for(int j=i+1; j<m-i-1; j++,k++)
                {
                    st[k]=char(a[m-j-1][i]);
                }
            }

        }
        cout<<st;
    }
    return 0;
}
