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

typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
int n, k, m;

vvi memo;

ll solve(int pos, int bars) {
	if (bars == 1) {
		if (n - pos > m || pos >= n) {
			return 0;
		} else
			return 1;
	} else if (n - pos < bars) 
		return 0; 
	else {
		ll &sum = memo[pos][bars];
		if (sum != -1)
			return sum;
		else {
			sum = 0;
			for (int i = pos + 1; i <= pos + m; i++) {
				sum += solve(i, bars - 1);
			} 
			// printf("solve(%d,%d) = %d\n",pos,bars,sum);
			return sum;
		}
	}

}

int main() {
	FILE *pFile = fopen("out.txt","w");
	
	while (scanf("%d %d %d", &n, &k, &m) == 3) {
		if(n == -1) {
			break;
		}
		memo.assign(n, vi(k + 1, -1));
		vi arr(n);
		
		printf("%lld\n", solve(0, k));
		fprintf(pFile,"%lld\n", solve(0, k));
	}
	fclose(pFile);
	return 0;
}