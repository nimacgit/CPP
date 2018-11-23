#include <iostream>
#include <vector>

using namespace std;

class heap
{
public:
	vector<int> v;
	void add();
	heap()
	{
		v.clear();
	}
	heap(int *a, int n)
	{
		for(int i = 0; i < n ; i++)
		{
			v.push_back(a[i]);
		}
		for(int i = n; i; i--)
			bubble_down(i);
	}
	void bubble_up(int i)
	{
		if(i >= 2 && v[i - 1] > v[(i / 2) - 1])
		{
			swap(v[i - 1], v[(i / 2) - 1]);
			bubble_up(i / 2);
		}
	}

	void bubble_down(int i)
	{
		if(i * 2 <= v.size() && (v[i - 1] < v[(2 * i) - 1] || v[i - 1] < v[(2 * i)] ) )
		{
			if(v[i - 1] < v[(2 * i) - 1] )
			{
				swap(v[i - 1], v[(2 * i) - 1]);
			}
			else
			{
				swap(v[i - 1], v[2 * i]);
			}
			bubble_down(i * 2);
		}
	}
	void add(int a)
	{
		v.push_back(a);
		bubble_up(v.size());
	}
	int extract_max()
	{
		int maxn = v[0];
		v[0] = v[v.size() - 1];
		v.pop_back();
		bubble_down(1);
		return maxn;
	}
	
};


int main()
{
	int n;
	cin >> n;
	int x[100];
	for(int i = 0; i < n; i++)
		cin >> x[i];
	heap a(x, n);
	for(int i = 0; i < n; i++)
		cout << a.extract_max() << endl; 

}
