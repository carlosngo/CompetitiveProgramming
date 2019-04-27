#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define PB push_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef long long ll;

class SegmentTree { // the segment tree is stored like a heap array
    private: vi st, A; // recall that vi is: typedef vector<int> vi;
    int n;
    int left (int p) { return p << 1; } // same as binary heap operations
    int right(int p) { return (p << 1) + 1; }
    void build(int p, int L, int R) { // O(n)
        if (L == R) // as L == R, either one is fine
            st[p] = L; // store the index
        else { // recursively compute the values
            build(left(p) , L , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R );
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        } 
    }
    int rmq(int p, int L, int R, int i, int j) { // O(log n)
        if (i > R || j < L) return -1; // current segment outside query range
        if (L >= i && R <= j) return st[p]; // inside query range
        // compute the min position in the left and right part of the interval
        int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
        int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
        if (p1 == -1) return p2; // if we try to access segment outside query
        if (p2 == -1) return p1; // same as above
        return (A[p1] <= A[p2]) ? p1 : p2; // as in build routine
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
    
    public:
    SegmentTree(const vi &_A) {
        A = _A; n = (int)A.size(); // copy content for local usage
        st.assign(4 * n, 0); // create large enough vector of zeroes
        build(1, 0, n - 1); // recursive build
    }
    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading
    int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }
};

int main() {
	FILE *pFile = fopen("out.txt","w");
    string input;
    int ctr = 1;
    while (cin >> input) {
        vi arr(input.length());
        FOR (i, 0, input.length(), 1) {
            arr[i] = (int) (input[i] - '0');
        }
        SegmentTree st(arr);
        int queries;
        SCD(queries);
        printf("Case %d:\n", ctr);
        fprintf(pFile,"Case %d:\n", ctr);
        while (queries-- > 0) {
            int l, r;
            SCD(l); SCD(r);
            int temp = l;
            l = min(l, r);
            r = max(temp, r);
            int num = arr[l];
            bool ans = true;
            FOR (i, l + 1, r + 1, 1) {
                if (arr[i] != num) ans = false;
            }   
            printf("%s", ans ? "Yes\n" : "No\n");
            fprintf(pFile, "%s", ans ? "Yes\n" : "No\n");
        }
        ctr++;
    }
	fclose(pFile);
	return 0;
}