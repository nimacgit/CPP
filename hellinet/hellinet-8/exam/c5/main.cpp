#include <iostream>

using namespace std;

long long int mab(long long int n)
{
    int bin=0, scale=1;
    while(n>0)
    {
        bin += (n%2)*scale;
        scale *= 10;
        n /= 2;
    }
    return bin;
}
long long int mab2(long long int bin)
{
    int n=0, scale=1;
    while(bin>0)
    {
        n += (bin%10)*scale;
        scale *= 2;
        bin /= 10;
    }
    return n;
}

long long int tedad(long long int n)
{
    int t=1;
    while(n>10)
    {
        n/=10;
        t++;
    }
    return t;
}

void shift (long long int a[],long long int n , int s)
{
    for (int i = n-1; i>=0; i--)
    {
        for (int j = 0; j<s; j++)
            swap(a[i+j],a[i+j+1]);
    }
}

int main()
{
    long long int a,b;
    cin >> a >> b;
    long long int a_m = mab(a);
    long long int b_m = mab(b);
    long long int res = 0;
    long long int aa[1000]= {0},bb[1000]= {0},cc[10000] = {0};
    for(int i = tedad(a_m)-1; i>=0; i--)
    {
        aa[i] = a_m %10;
        a_m /= 10;
    }
    for(int i = tedad(b_m)-1; i>=0; i--)
    {
        bb[i] = b_m %10;
        b_m /= 10;
    }
    a_m = mab(a);
    b_m = mab(b);
    shift(aa,tedad(a_m),tedad(b_m)-tedad(a_m));
    for(int i = tedad(b_m)-1; i>=0; i--)
    {
        if(aa[i] == bb[i])
            cc[i] = aa[i];
        else
            cc[i] = 1;
    }
    for(int i = 0; i<tedad(b_m); i++)
    {
        res *= 10;
        res += cc[i];
    }
    res = mab2(res);
    return 0;
    }
