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
const int UNVISITED = -1;

vvi adjList;
bitset<10001> visited;
int ans;

void dfs(int u) {
    visited.set(u);
    ans++;
    FOR(i, 0, adjList[u].size(), 1) {
        int v = adjList[u][i];
        if (!visited.test(v)) {
            dfs(v);
        }
    }
}

int main() {
    WHILEZ {
        int n, m, l;
        cin >> n >> m >> l;
        adjList = vvi(n, vi());
        visited = bitset<10001>();
        ans = 0;
        FOR(i, 0, m, 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adjList[u].PB(v);
        }
        FOR(i, 0, l, 1) {
            int src;
            cin >> src;
            src--;
            if (!visited.test(src)) dfs(src);
        }
        cout << ans;
        if (T) cout << '\n';
    }
	return 0;
}