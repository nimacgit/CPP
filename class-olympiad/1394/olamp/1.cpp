#include <iostream>
#include <vector>
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;
int n;
const int maxn = 10;
bool seen [maxn + 2][maxn + 2];
int waysx[8] ={1, 2, 1, 2, -1, -2, -1, -2}; 
int waysy[8] = {2, 1, -2, -1, 2, 1, -2, -1 };
vector <int>  myvecx, myvecy;
int co = 0;

bool find(int x,int y)
{
	if(co == n * n)
		return true;
	for(int i = 0; i < 8; i++)
	{
		int ny = y + waysy[i];
		int nx = x + waysx[i];
		if(nx < n && ny < n && nx >= 0 && ny >= 0)
		{
			if(!seen[nx][ny])
			{
				seen[nx][ny] = true;
				co++;
				if(find(nx,ny))
				{
					myvecx.push_back(nx);
					myvecy.push_back(ny);
					return true;
				}
				seen[nx][ny] = false;
				co--;
			}
		}
	}
	return false;
			
}

int main()
{
	cin >> n;
	bool ok;
	seen[0][0] = true;
	co = 1;
	ok = find(0, 0);
	myvecx.push_back(0);
	myvecy.push_back(0);
	if(ok)
	{
		cout << "YES" << endl;
		for(int i = myvecx.size() - 1; i >= 0; i--)
		{
			cout << myvecx[i] + 1 << "  " << myvecy[i] + 1 << endl;
		}
		return 0;
	}
	cout << "NO" << endl;

}
