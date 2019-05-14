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

bool ans;
vvi adjList;
vi dfs_num, dfs_low, dfs_parent;
int dfs_ctr;

void findBridges(int u) {
    if (!ans) return;
    dfs_num[u] = dfs_low[u] = dfs_ctr++;
    for (int i = 0; i < adjList[u].size() && ans; i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            findBridges(v);
            if (dfs_low[v] > dfs_num[u]) ans = false;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int p, c;
    while ((cin >> p >> c), p != 0 || c != 0) {
        adjList.assign(p, vi());
        dfs_num.assign(p, UNVISITED);
        dfs_low.assign(p, 0);
        dfs_parent.assign(p, 0);
        dfs_ctr = 0;
        for (int i = 0; i < c; i++) {
            int from, to;
            cin >> from >> to;
            adjList[from].PB(to);
            adjList[to].PB(from);
        }
        ans = true;
        for (int i = 0; i < p; i++) {
            if (dfs_num[i] == UNVISITED) findBridges(i);
        }
        if (ans) cout << "No\n";
        else cout << "Yes\n"; 
    }
    
	return 0;
}