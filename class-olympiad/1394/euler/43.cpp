#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

long long makeint()
{
	long long sum = 0;
	for(int i = 0; i < 10; i++)
		sum = sum * 10 + a[i];
	return sum;
}

int main()
{
	long long count = 0;
	while(next_permutation(a, a + 10))
	{
			if((a[1] * 100 + a[2] * 10 + a[3]) % 2 == 0)
				if((a[2] * 100 + a[3] * 10 + a[4]) % 3 == 0)
					if((a[3] * 100 + a[4] * 10 + a[5]) % 5 == 0)
						if((a[4] * 100 + a[5] * 10 + a[6]) % 7 == 0)
							if((a[5] * 100 + a[6] * 10 + a[7]) % 11 == 0)
								if((a[6] * 100 + a[7] * 10 + a[8]) % 13 == 0)
									if((a[7] * 100 + a[8] * 10 + a[9]) % 17 == 0)
										count += makeint();
	}
	cout << count << endl;
}