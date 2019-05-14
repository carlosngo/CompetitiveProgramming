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
#define UNVISITED -1

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
int dfs_num[100];
int dfs_low[100];
int dfs_parent[100];
bool articulation_vertex[100];
int ans;
int dfs_ctr;
int dfs_root;
int rootChildren;

void findArticulationPoints(int u) {
    dfs_num[u] = dfs_low[u] = dfs_ctr++;
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == UNVISITED) {
            if (u == dfs_root) rootChildren++;
            dfs_parent[v] = u;
            findArticulationPoints(v);
            if (u != dfs_root && dfs_low[v] >= dfs_num[u]) {
                // fprintf(stdout, "%d is an articulation point because dfs_low[%d] = %d >= dfs_num[%d] = %d.\n", u, v, dfs_low[v], u, dfs_num[u]);
                articulation_vertex[u] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int n;
    while (SCD(n), n != 0) {
        memset(dfs_num, UNVISITED, sizeof dfs_num);
        memset(dfs_low, 0, sizeof dfs_low);
        memset(dfs_parent, 0, sizeof dfs_parent);
        memset(articulation_vertex, false, sizeof articulation_vertex);
        dfs_ctr = 0;
        ans = 0;
        adjList.assign(n, vi());
        string line;
        while (getline(cin, line), line != "0") {
            stringstream ss(line);
            int from, to;
            ss >> from;
            from--;
            while (ss >> to) {
                to--;
                adjList[from].PB(to);
                adjList[to].PB(from);
            }
        }
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == UNVISITED) {
                dfs_root = i;
                rootChildren = 0;
                findArticulationPoints(i);
                // fprintf(stdout, "root children = %d\n", rootChildren);
                articulation_vertex[i] = rootChildren > 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (articulation_vertex[i]) ans++;
        }
        fprintf(stdout, "%d\n", ans);
    }
	return 0;
}