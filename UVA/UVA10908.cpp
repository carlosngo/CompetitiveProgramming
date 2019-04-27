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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    while (t--) {
        int m, n, q;
        SCD(m); SCD(n); SCD(q);
        fprintf(stdout, "%d %d %d\n", m, n, q);
        fprintf(pFile, "%d %d %d\n", m, n, q);
        getchar();
        char grid[m][n];
        FOR (i, 0, m, 1) {
            FOR (j, 0, n, 1) {
                SCC(grid[i][j]);
            }
            getchar();
        }
        while (q--) {
            int r, c;
            SCD(r); SCD(c);
            int ans = 1;
            int nextR = r - 1, nextC = c - 1;
            while (nextR >= 0 && nextC >= 0 && grid[nextR][nextC] == grid[r][c]) {
                ans += 2;
                bool valid = true;
                for (int i = nextR; i < nextR + ans && valid; i++) {
                    if (i == m) valid = false;
                    for (int j = nextC; j < nextC + ans && valid; j++) {
                        if (j == n) valid = false;
                        if (grid[i][j] != grid[r][c]) valid = false;
                    }
                }
                if (!valid) {
                    ans -= 2;
                    break;
                }
                nextR--; nextC--;
            }
            fprintf(stdout, "%d\n", ans);
            fprintf(pFile, "%d\n", ans);
            // fprintf(pFile, "%d %d %d\n", r, c,ans);
        }
    }
	fclose(pFile);
	return 0;
}