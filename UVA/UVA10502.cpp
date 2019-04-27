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
    int n, m;
    while (SCD(n), n != 0) {
        SCD(m);
        int grid[n + 1][m + 1];
        getchar();
        FOR (i, 1, n + 1, 1) {
            FOR (j, 1, m + 1, 1) {
                char ch;
                SCC(ch);
                grid[i][j] = ch - '0';
            }
            getchar();
        }
        int sums[n + 1][m + 1];
        memset(sums, 0, sizeof sums);
        FOR (i, 1, n + 1, 1) {
            FOR (j, 1, m + 1, 1) {
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + grid[i][j];
            }
        }
        int ans = 0;
        for (int startR = 1; startR <= n; startR++) {
            for (int startC = 1; startC <= m; startC++) {
                for (int endR = startR; endR <= n; endR++) {
                    for (int endC = startC; endC <= m; endC++) {
                        int size = (endR - startR + 1) * (endC - startC + 1);
                        int sum = sums[endR][endC] - (sums[endR][startC - 1] + sums[startR - 1][endC] - sums[startR - 1][startC - 1]);
                        if (size == sum) ans++;
                    }
                }
            }
        }
        fprintf(stdout, "%d\n", ans);
        fprintf(pFile, "%d\n", ans);
    }
	fclose(pFile);
	return 0;
}