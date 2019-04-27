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
	int n, m;

	bitset<20000> bs;
	while (scanf("%d %d", &n, &m), n != 0 && m != 0) {
		vi knights(m);
		vi heads(n);
		bs.reset();
		for (int i = 0; i < n; i++)
			scanf("%d", &heads[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &knights[i]);
		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());
		int sum = 0;

		bool doomed = (m < n) ? true : false;
		for (int i = 0; i < n && !doomed; i++) {
			bool killable = false;
			for (int j = 0; j < m && !killable; j++) {
				if (knights[j] >= heads[i] && !bs.test(j)) {
					sum += knights[j];
					killable = true;
					bs.set(j);
				}
			}
			if (!killable)
				doomed = true;
		}
		if (doomed) {
			printf("Loowater is doomed!\n");
			fprintf(pFile, "Loowater is doomed!\n");
		}
		else {
			printf("%d\n", sum);
			fprintf(pFile, "%d\n", sum);
		}
	}
	fclose(pFile);
	return 0;
}