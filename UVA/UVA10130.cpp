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

int memo[1001][31];
ii objects[1001];
int n;

int knapsack(int pos, int remW) {
    if (pos == n || remW < 0) return 0;
    if (memo[pos][remW] != -1) return memo[pos][remW];
    if (objects[pos].second > remW) return memo[pos][remW] = knapsack(pos + 1, remW);
    return memo[pos][remW] = max(knapsack(pos + 1, remW - objects[pos].second) + objects[pos].first, knapsack(pos + 1, remW));
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    while (t--) {
        memset(memo, -1, sizeof memo);
        
        SCD(n);
        FOR (i, 0, n, 1) {
            int price, weight;
            SCD(price); SCD(weight);
            objects[i] = ii(price, weight);
        }
        int g;
        SCD(g);
        int mw[g];
        int ans = 0;
        FOR (i, 0, g, 1) {
            SCD(mw[i]);
            ans += knapsack(0, mw[i]);
        }
        fprintf(stdout, "%d\n", ans);
        // fprintf(pFile, "%d\n", ans);
    }
	fclose(pFile);
	return 0;
}
