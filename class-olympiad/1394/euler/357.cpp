#include <iostream>

using namespace std;

int n = 1000 * 1000 * 100;

bool isprime(int a)
{
    for(int i = 2; i * i <= a; i ++)
        if(a % i == 0)
            return false;
    return true;
}

bool check(int a)
{
    for(int i = 1; i * i <= a; i ++)
    {
        if(a % i == 0)
        {
            if(! isprime(i + a / i))
                return false;
        }
    }
    return true;
}

int main()
{
    long long int sum = 0;
    for(int i = 2; i <= n; i += 4)
    {
        if(check(i))
        {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}