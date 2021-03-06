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

ii memo[100][10001][100];
int val, n;
int coins[100];

ii cc(int pos, int remC, int numCoins) {
    if (remC <= 0) {
        // printf("%d\n", val - remC);
        return ii(val - remC, numCoins);
    }
    if (pos == n) return ii(1 << 30, 1 << 30);
    if (memo[pos][remC][numCoins] != ii(-1, -1)) return memo[pos][remC][numCoins];
    ii take = cc(pos + 1, remC - coins[pos], numCoins + 1);
    ii next = cc(pos + 1, remC, numCoins);
    if (take.first < next.first) {
        memo[pos][remC][numCoins] = ii(take.first, take.second);
    } else if (take.first == next.first) {
        if (take.second < next.second) {
            memo[pos][remC][numCoins] = ii(take.first, take.second);
        } else {
            memo[pos][remC][numCoins] = ii(next.first, next.second);
        }
    } else {
        memo[pos][remC][numCoins] = ii(next.first, next.second);
    }
    return memo[pos][remC][numCoins];

}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    while (t--) {
        SCD(val);
        SCD(n);
        FOR (i, 0, n, 1) SCD(coins[i]);
        memset(memo, -1, sizeof memo);
        ii ans = cc(0, val, 0);
        fprintf(stdout, "%d %d\n", ans.first, ans.second);
        fprintf(pFile, "%d %d\n", ans.first, ans.second);
    }
	fclose(pFile);
	return 0;
}
