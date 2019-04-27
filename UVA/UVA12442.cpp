#include <bits/stdc++.h>

using namespace std;


int
main() {
	FILE *pFile = fopen("out.txt", "w");
	int t;
	scanf("%d", &t);
	int ctr = 1;
	while (t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for (int i = 0; i < n; i++) {
			int src, dest;
			scanf("%d %d", &src, &dest);
			src--; dest--;
			arr[src] = dest;
		}
		
		int ans = -1;
		int maxi = 0;
		int memo[n];
		memset(memo, -1, sizeof memo);

			bitset<50001> bs;	
		for (int i = 0; i < n; i++) {
			int forwarded = 0;
			int cur = i;
			while (!bs.test(arr[cur])) {
				bs.set(arr[cur]);
				if (memo[arr[cur]] != -1) {
					forwarded += memo[arr[cur]];
					break;
				} else {
					forwarded++;
				}
				cur = arr[cur];
			}
			memo[i] = forwarded;
			if (forwarded > maxi) {
				ans = i;
				maxi = forwarded;
			}
			printf("ans = %d\n", ans);
		}
		printf("Case %d: %d\n", ctr, ans + 1);
		fprintf(pFile, "Case %d: %d\n", ctr, ans + 1);
		ctr++;
	}
	fclose(pFile);
	return 0;
}
