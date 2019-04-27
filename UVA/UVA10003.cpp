#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) fscanf(stdin, "%d",&t)
#define SCLD(t) fscanf(stdin, "%ld",&t)
#define SCLLD(t) fscanf(stdin, "%lld",&t)
#define SCC(t) fscanf(stdin, "%c",&t)
#define SCS(t) fscanf(stdin, "%s",t)
#define SCF(t) fscanf(stdin, "%f",&t)
#define SCLF(t) fscanf(stdin, "%lf",&t)
// CHECKING BOUNDS
#define IN(i,l,r) (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
// LOOPS
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define WHILEZ int T; SCD(T); while(T--) 
// MISC
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define PB push_back
#define INF 1000000000

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int l, n;
int cuts[53];
int memo[53][53];
int backtrack(int left, int right) {
    if (left + 1 == right) return 0;
    if (memo[left][right] != -1) return memo[left][right];
    int minLen = INT_MAX;
    for (int i = left + 1; i < right; i++) {
        minLen = min(minLen, backtrack(left, i) + backtrack(i, right) + (cuts[right] - cuts[left]));
    }
    return memo[left][right] = minLen;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    while (SCD(l), l != 0) {
        SCD(n);
        cuts[0] = 0;
        memset(memo, -1, sizeof memo);
        FOR (i, 1, n + 1, 1) SCD(cuts[i]);
        cuts[n + 1] = l;
        int ans = backtrack(0, n + 1);
        fprintf(stdout, "The minimum cutting is %d.\n", ans);
        // fprintf(pFile, "The minimum cutting is %d.\n", ans);
    }
	fclose(pFile);
	return 0;
}
