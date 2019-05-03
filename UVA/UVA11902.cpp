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

vvi adjList;
vi reachable;
vi original;
bitset<100> visited;
int n;

void dfs(int pos) {
    if (visited.test(pos) || pos == n) return;
    visited.set(pos);
    reachable.PB(pos);
    for (int i = 0; i < adjList[pos].size(); i++) {
        dfs(adjList[pos][i]);
    }
}

bool isDominated(int x, int y) {
    bool isReachable = false;
    for (int i = 0; i < original.size(); i++) if (original[i] == y) isReachable = true;
    if (!isReachable) return false;
    if (x == y) return true;
    vi temp = adjList[x];
    adjList[x] = vi();
    reachable = vi();
    visited = bitset<100>();
    dfs(0);
    bool isStillReachable = false;
    for (int i = 0; i < reachable.size(); i++) if (reachable[i] == y) isStillReachable = true;
    adjList[x] = temp;
    return !isStillReachable;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
    int t;
	SCD(t);
    for (int ctr = 1; ctr <= t; ctr++) {
        
        SCD(n);
        adjList = vvi(n, vi());
        reachable = vi();
        original = vi();
        visited = bitset<100>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int isConnected;
                SCD(isConnected);
                if (isConnected) {
                    adjList[i].PB(j);
                }
            }
        }
        dfs(0);
        original = reachable;

        fprintf(stdout, "Case %d:\n", ctr);
        fprintf(stdout, "+");
        for (int j = 0; j < 2 * n - 1; j++) fprintf(stdout, "-");
        fprintf(stdout, "+\n");
        for (int i = 0; i < n; i++) {
            if (i > 0) fprintf(stdout, "\n");
            fprintf(stdout, "|");
            for (int j = 0; j < n; j++) {
                if (isDominated(i, j)) fprintf(stdout, "Y");
                else fprintf(stdout, "N");
                fprintf(stdout, "|");
            }
            fprintf(stdout, "\n+");
            for (int j = 0; j < 2 * n - 1; j++) fprintf(stdout, "-");
            fprintf(stdout, "+");
        }
        fprintf(stdout, "\n");
    }
	return 0;
}