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

class SegmentTree {
	public:
		vi st;
		vi a;
		int n;
		SegmentTree(vi _a) {
			a = _a;
			n = (int)a.size();
			st.assign(4 * n, 0);	
			build(1, 0, n - 1);
		}

		void build(int p, int L, int R) {
			if (L == R) {
				if (a[L] > 0) 
					st[p] = 1;
				else if (a[L] == 0)
					st[p] = 0;
				else
					st[p] = -1;
			}
			else {
				int M = (L + R) / 2;
				build(left(p), L, M);
				build(right(p), M + 1, R);
				st[p] = st[left(p)] * st[right(p)];
			}
		}

		int rsq(int p, int L, int R, int i, int j) {
			if (j < L || i > R) {
				return 1;
			}
			if (L >= i && R <= j) {
				return st[p];
			}
			int M = L + (R - L) / 2;
			return rsq(left(p), L, M, i, j) * rsq(right(p), M + 1, R, i, j);
		}

		void update(int p, int L, int R, int i, int val) {
			if (L == R) {
				a[i] = val;
				if (a[i] > 0) 
					st[p] = 1;
				else if (a[i] == 0)
					st[p] = 0;
				else
					st[p] = -1;
			} else {
				int M = (L + R) / 2;
				if (i >= L && i <= M) {
					update(left(p), L, M, i, val);	
				} else {
					update(right(p), M + 1, R, i, val);
				}
				st[p] = st[left(p)] * st[right(p)];
			}	
		}

		int left(int p) {
			return p << 1;
		}

		int right(int p) {
			return (p << 1) + 1;
		}
};

int main() {
	FILE *pFile = fopen("out.txt","w");
	int n, k;
	int ctr = 1;
	while (scanf("%d", &n) == 1) {
		scanf("%d", &k);
		vi arr(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		SegmentTree st(arr);
		string cmd;
		for (int i = 0; i < k; i++) {
			cin >> cmd;
			int x, y;
			scanf("%d %d", &x, &y);
			if (cmd == "C") {
				st.update(1, 0, n - 1, x - 1, y);
			} else {
				int output = st.rsq(1, 0, n - 1, x - 1, y - 1);
				printf("%s", output == 0 ? "0" : (output == 1 ? "+" : "-"));
				fprintf(pFile,"%s", output == 0 ? "0" : (output == 1 ? "+" : "-"));
			}
		}
		printf("\n");
		fprintf(pFile, "\n");
	}

	fclose(pFile);
	return 0;
}