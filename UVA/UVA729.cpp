#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int n;
int len, h;
vi soln;
FILE *pFile;

void solve(int pos, int ones) {
	if (pos == len) {
		if (ones == h) {
			for (int i = 0; i < len; i++) {
				printf("%d", soln[i]);
				fprintf(pFile, "%d", soln[i]);
			}
			printf("\n");
			fprintf(pFile, "\n");
		}
	} else {
		solve(pos + 1, ones);
		if (ones < h) {
			soln[pos] = 1;
			ones++;
			solve(pos + 1, ones);
			soln[pos] = 0;
			ones--;
		}
		
	}
}

int main() {
	pFile = fopen("out.txt","w");
	scanf("%d", &n);
	while (n-- > 0) {
		scanf ("%d %d", &len, &h);
		soln.assign(len, 0);
		solve(0, 0);
		if (n > 0) {
			printf("\n");
			fprintf(pFile, "\n");
		}
	}
	fclose(pFile);
	return 0;
}