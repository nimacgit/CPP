#include <iostream>
#include <vector>
using namespace std;

int check(int a,long long int * b,int & j,int n)
{
    j=-1;
    for(int i=0; i<n; i++)
        if(a>b[i] )
        {
            if(j>-1)
            {
                if(b[i]>b[j])
                    j=i;
            }
            else
                j=i;
        }
    if(j==-1)
        return 0;
    else
        return 1;
}
int main()
{
    int n;
    cin >> n;
    long long int a[n],b[n];
    long long int x;
    for (int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i<n; i++)
    {
        cin>>b[i];
    }
    int s = 0;
    int j;
    for(int i=0; i<n; i++)
    {
        if( check(b[i],a,j,n))
        {
            swap(a[j],a[n]);
            swap(b[i],b[n]);
            n--;
            s++;
            i--;
        }
    }
    cout << s;

}
