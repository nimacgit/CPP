#include <vector>
#include <iostream>
#include <cmath>
using namespace std;



int main()
{
    long long int n,m;
    cin>>n>>m;
    long long int ai[n-1],bi[n-1],a,b;
    int sa=0,sb=0,fa=0,fb=0;
    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b;
        sa=0,sb=0,fa=0,fb=0;
        if(i==0)
        {
            ai[0]=a;
            bi[0]=b;
            if(a==b)
            {
                sb++;
                fb++;
                sa++;
                fa++;
            }
        }
        for(int j=0; j<i; j++)
        {
            if(ai[j]==a )
            {
                sa++;
                ai[i]=a;
                bi[i]=b;
            }
            else if(bi[j]==b)
            {
                sb++;
                bi[i]=b;
                ai[i]=a;
            }
            else
            {
                if(ai[j]==b)
                {
                    fa++;
                    ai[i]=b;
                    bi[i]=a;
                }
                else if (bi[j]==a)
                {
                    fb++;
                    bi[i]=a;
                    ai[i]=b;
                }
            }
            if((fa>0 || fb>0) && (sb>0 || sa>0) )
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if((fa>0 || fb>0) && (sb>0 || sa>0) )
            {
                cout<<"NO"<<endl;
                return 0;
            }
    }
    cout<<"YES"<<endl;
}
