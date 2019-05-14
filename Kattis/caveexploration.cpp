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
vi dfs_num, dfs_low, dfs_parent;
int dfs_ctr;
int ans;
vii bridges;

void findBridges(int u) {
    dfs_num[u] = dfs_low[u] = dfs_ctr++;
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            findBridges(v);
            if (dfs_low[v] > dfs_num[u]) {
                bridges.PB(ii(u, v));
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

void dfs(int u) {
    dfs_num[u] = 0;
    ans++;
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == UNVISITED) {
            dfs(v);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int n, m;
    cin >> n >> m;
    
    adjList.assign(n, vi());
    dfs_num.assign(n, UNVISITED);
    dfs_low.assign(n, 0);
    dfs_parent.assign(n, 0);
    dfs_ctr = 0;
    for (int i = 0; i < m; i++) {
        int src, dest;
        cin >> src >> dest;
        adjList[src].PB(dest);
        adjList[dest].PB(src);
    }
    ans = 0;
    findBridges(0);
    for (int i = 0; i < bridges.size(); i++) {
        int u = bridges[i].first;
        int v = bridges[i].second;
        adjList[v].erase(std::remove(adjList[v].begin(), adjList[v].end(), u), adjList[v].end());
        adjList[u].erase(std::remove(adjList[u].begin(), adjList[u].end(), v), adjList[u].end());
    }
    dfs_num.assign(n, UNVISITED);
    dfs(0);
    fprintf(stdout, "%d", ans);
	return 0;
}