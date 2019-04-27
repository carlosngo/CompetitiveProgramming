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

ll memo[5][30001];
int n;
const int coins[5] = {1, 5, 10, 25, 50};

ll cc(int V, int remV) {
    if (remV == 0) return 1;
    if (V == 5 || remV < 0) return 0;
    if (memo[V][remV] != -1) return memo[V][remV];
    return memo[V][remV] = cc(V, remV - coins[V]) + cc(V + 1, remV);
    
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    memset(memo, -1, sizeof memo);
    while (SCD(n) == 1) {
        // memset(memo, -1, sizeof memo);
        ll ans = cc(0, n);
        if (ans == 1) {
            fprintf(stdout, "There is only 1 way to produce %d cents change.\n", n);
            // fprintf(pFile, "There is only 1 way to produce %d cents change.\n", n);
        } else {
            fprintf(stdout, "There are %lld ways to produce %d cents change.\n", ans, n);
            // fprintf(pFile, "There are %lld ways to produce %d cents change.\n", ans, n);
        }
        
    }   
	fclose(pFile);
	return 0;
}

