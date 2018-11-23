#include <iostream>

using namespace std;

int main()
{
int a,b,c,d;
cin >> a >> b >> c >> d;
if(a==d||b==d||c==d)
{
cout << "YES";
}
else if(a+b==d||a+c==d||b+c==d)
{
cout << "YES";
}
else if(a+b+c==d)
{
cout << "YES";
}
else
{
cout << "NO";
}
return 0;
}
