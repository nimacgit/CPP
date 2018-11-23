#include <vector>
#include <iostream>
#include <cmath>
using namespace std;



int main()
{
    long long int n;
    cin >> n;
    long long a[n];
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    a[0]=0;
    long long int k = n-1;
    long long int m=0;
    for (long long int i = k+1;i>0;i--)
    {
           m+=a[i]/i;
           a[i]%=i;
           a[i-1]+=m;
    }
    cout << a[0] << endl;
    return 0;
}

