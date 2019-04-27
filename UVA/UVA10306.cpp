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

int m, s;
ll memo[301][301];
ii coins[40];

ll cc(int remX, int remY) {
    if (remX == 0 && remY == 0) return 0;
    if (remX < 0 || remY < 0) return (1 << 30);
    if (memo[remX][remY] != -1) return memo[remX][remY];
    ll minCoins = INT_MAX;
    for (int i = 0; i < m; i++) {
        minCoins = min(minCoins, cc(remX - coins[i].first, remY - coins[i].second));
    }
    return memo[remX][remY] = minCoins + 1;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n;
    SCD(n);
    
    while (n--) {
        memset(memo, -1, sizeof memo);
        SCD(m); SCD(s);
        FOR (i, 0, m, 1) {
            int x, y;
            SCD(x); SCD(y);
            coins[i] = ii(x, y);
        }
        ll ans = (1 << 30);
        for (int i = 0; i <= s; i++) {
            int x2 = i * i;
            double y2 = s * s - x2;
            if (sqrt(y2) == floor(sqrt(y2))) {
                ans = min(ans, cc(i, (int)(sqrt(y2) + 0.5)));
            }
        }
        if (ans == 0 || ans == (1 << 30)) {
            fprintf(stdout, "not possible\n");
            // fprintf(pFile, "not possible\n");
        } else {
            fprintf(stdout, "%lld\n", ans);
            // fprintf(pFile, "%lld\n", ans);
        }
    }
	fclose(pFile);
	return 0;
}