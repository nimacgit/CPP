#include <iostream>

using namespace std;

int main()
{
	int count = 1;
	for(int a1 = 0; a1 <= 200; a1++)
	{
		for(int a2 = 0; a2 <= 100; a2++)
		{
			for(int a5 = 0; a5 <= 40; a5++)
			{
				for(int a10 = 0; a10 <= 20; a10++)
				{
					for(int a20 = 0; a20 <= 10; a20++)
					{
						for(int a50 = 0; a50 <= 4; a50++)
						{
							for(int a100 = 0; a100 <= 2; a100++)
							{
								long long sum = a1 * 1 + a2 * 2+ a5 * 5 + a10 * 10 + a20 * 20 + a50 * 50 + a100 * 100;
								if(sum == 200)
									count++;
							}
						}
					}
				}
			}
		}
	}
	cout << count << endl;
}