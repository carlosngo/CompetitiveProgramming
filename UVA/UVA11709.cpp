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
vi dfs_num, dfs_low, dfs_parent, s;
vector<bool> visited;
int dfs_ctr;
vector<string> names;
map<string, int> indices;
int ans;

void findSCC(int u) {
    dfs_num[u] = dfs_low[u] = dfs_ctr++;
    s.push_back(u);
    visited[u] = true;
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == UNVISITED) findSCC(v);
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_num[u] == dfs_low[u]) {
        ans++;
        while (true) {
            int top = s.back();
            s.pop_back();
            visited[top] = false;
            if (top == u) break;
        }
    }
}

int main() {
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    int n, m;
    while (fscanf(stdin, "%d%d", &n, &m), n != 0 || m != 0) {
        adjList.assign(n, vi());
        dfs_num.assign(n, UNVISITED);
        dfs_parent.assign(n, 0);
        dfs_low.assign(n, 0);
        dfs_ctr = 0;
        s = vi();
        visited.assign(n, false);
        names = vector<string>();
        indices = map<string, int>();
        ans = 0;
        getchar();
        for (int i = 0; i < n; i++) {
            string name;
            getline(cin, name);
            names.PB(name);
            indices[name] = i;
        }
        for (int i = 0; i < m; i++) {
            string src, dest;
            getline(cin, src);
            getline(cin, dest);
            adjList[indices[src]].PB(indices[dest]);
        }
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == UNVISITED) {
                findSCC(i);
            }
        }
        fprintf(stdout, "%d\n", ans);
    }
	
	return 0;
}