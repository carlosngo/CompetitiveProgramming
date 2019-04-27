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
			if (L == R)
				st[p] = a[L];
			else {
				int M = (L + R) / 2;
				build(left(p), L, M);
				build(right(p), M + 1, R);
				st[p] = st[left(p)] + st[right(p)];
			}
		}

		int rsq(int p, int L, int R, int i, int j) {
			if (j < L || i > R) {
				return 0;
			}
			if (L >= i && R <= j) {
				return st[p];
			}
			int M = L + (R - L) / 2;
			return rsq(left(p), L, M, i, j) + rsq(right(p), M + 1, R, i, j);
		}

		void update(int p, int L, int R, int i, int val) {
			if (L == R) {
				a[i] = val;
				st[p] = a[i];
			} else {
				int M = (L + R) / 2;
				if (i >= L && i <= M) {
					update(left(p), L, M, i, val);	
				} else {
					update(right(p), M + 1, R, i, val);
				}
				st[p] = st[left(p)] + st[right(p)];
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
	int n;
	int ctr = 1;
	while (scanf("%d", &n), n) {
		if (ctr > 1)
			printf("\n");
		printf("Case %d:\n", ctr++);
		vi arr(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		SegmentTree st(arr);
		string cmd;
		while (cin >> cmd, cmd != "END") {
			int x, y;
			scanf("%d %d", &x, &y);
			if (cmd == "S") {
				st.update(1, 0, n - 1, x - 1, y);
			} else {
				printf("%d\n", st.rsq(1, 0, n - 1, x - 1, y - 1));
			}
		}
	}

	fclose(pFile);
	return 0;
}