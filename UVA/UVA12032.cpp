#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

vi rungs;

bool canReach(int k) {
	for (int i = 0; i < rungs.size() - 1; i++) {
		if (rungs[i + 1] - rungs[i] > k)
			return false;
		else if (rungs[i + 1] - rungs[i] == k)
			k--;
	}
	return true;
}

int main() {
	FILE *pFile = fopen("out.txt","w");
	int n;
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		int size;
		scanf("%d", &size);
		rungs.assign(size + 1, 0);
		for (int i = 1; i <= size; i++) {
			scanf("%d", &rungs[i]);
		}
		int low = 1;
		int high = rungs[size];
		while (low < high) {
			int mid = (low + high) / 2;
			// fprintf(pFile, "%d %d %d", low, mid, high);
			if (canReach(mid)) {
				high = mid;
			} else
				low = mid + 1;
		}
		printf("Case %d: %d\n", j + 1, low);
		fprintf(pFile, "Case %d: %d\n", j + 1, low);
	}
	fclose(pFile);
	return 0;
}