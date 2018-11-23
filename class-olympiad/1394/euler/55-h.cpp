#include<iostream>

using namespace std;

long long int rev(long long int a)
{
    long long int ans = 0;
    while(a > 0)
    {
        ans = ans * 10 + a % 10;
        a /= 10;
    }
    return ans ;
}

bool pal(long long int a, int i)
{
    if(i == 49)
        return false;
    long long int b = rev(a);
    if(i != 0 && a == b)
        return true;
    return pal((long long int)a + b, i + 1);
}

int main()
{
    int ans = 0;
    for(int i = 0; i <= 10000; i ++)
    {
        if(! pal((long long int)i, 0))
            ans ++;
    }
    cout << ans << endl;
    return 0;
}