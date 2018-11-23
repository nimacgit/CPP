#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;



int main()
{
    int n;
    cin>>n;
    long long int s [n];
    long long int h[n];
    long long int v;
    int maxh,maxs;
    for(int i=0; i<n; i++)
    {
        cin>>h[i]>>s[i];
        if(i==0)
        {
            maxs=s[i];
            maxh=h[i];
            v=maxs*maxh;
        }
        if(s[i]>maxs && h[i]>maxh)
        {
            t1 = s[i] - maxs;
            t2 = h[i] - maxh;
            v+= t1 * t2;
            maxs=s[i];
            maxh =h[i];

        }
        else if(s[i]>maxs && h[i]<maxh)
        {
            t1 = s[i] - maxs;
            v+= t1 * t2;
            maxs=s[i];
            maxh =h[i];

        }


    }
}

