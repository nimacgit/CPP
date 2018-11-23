#include <cstdio>
#include <cassert>
#include <iostream>
#include "testlib.h"

using namespace std;

bool v[1010],h[1010];

int main(int argc, char* argv[]){
	registerGen(argc, argv);
	int test_case; scanf("%d", &test_case);
	for (int o=1; o<=test_case; o++){
		int n,m,k,is_yes;
		scanf("%d%d%d%d", &n, &m, &k, &is_yes);
		if (is_yes){
			for (int i=0; i<n; i++)
				v[i] = rnd.next(0, 1); 
			for (int i=0; i<m; i++)
				h[i] = rnd.next(0, 1);
		}
		stringstream inp; inp<<o<<"."<<"in";
		FILE* out_file = fopen(inp.str().c_str(), "w"); 
		fprintf(out_file, "%d %d %d\n", n, m, k);
		for (int i=0; i<k; i++){
			int x = rnd.next(0, n-1); 
			int y = rnd.next(0, m-1);
			int xx= rnd.next(0, n-1);
			int yy= rnd.next(0, m-1);
			if (is_yes){
				if (x!=xx || y!=yy){
					if (x==xx){
						if (v[x] != (y<yy)) { i--; continue; }
					}else if (y==yy){
						if (h[y] != (x<xx)) { i--; continue; }
					}else{
						if (((x<xx)!=h[y] || (y<yy)!=v[xx]) && ((y<yy)!=v[x] || (x<xx)!=h[yy])) { i--; continue; }
					}
				}
			}
			x++; y++; xx++; yy++;
			fprintf(out_file, "%d %d %d %d\n", x, y, xx, yy);
		}
		fclose(out_file);
	}
	return 0;
}
