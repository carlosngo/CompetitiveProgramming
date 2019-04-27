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

int main() {
	FILE *pFile = fopen("out.txt","w");
	int cases;
	bitset<105> visited;
	bitset<105> small;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		int n, end;
		visited.reset();
		small.reset();
		scanf("%d %d", &n, &end);
		int points[105];
		for (int j = 0; j < n; j++) {
			char size, dash;
			cin >> size >> dash >> points[j];
			if (size == 'S') small.set(j);
		}

		points[n] = end;

		int ans = points[0];
		for (int j = 0; j < n; j++) {
			visited.set(j);
			if (!small.test(j + 1)) {
				ans = max(ans, points[j + 1] - points[j]);
			} else {
				ans = max(ans, points[j + 2] - points[j]);
				j++;
			}
		}

		for (int j = n; j > 0; j--) {
			if (!visited.test(j - 1) || !small.test(j - 1))
				ans = max(ans, points[j] - points[j - 1]);
			else {
				ans = max(ans, points[j] - points[j - 2]);
				j--;
			}
		}
		printf("Case %d: %d\n", i, ans);
		fprintf(pFile, "Case %d: %d\n", i, ans);
	}
	fclose(pFile);
	return 0;
}