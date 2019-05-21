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
int dfs_ctr, dfs_root, rootChildren;
vector<bool> isArticulationVertex;
vector<string> ans;

void findArticulationPoints(int u) {
    dfs_num[u] = dfs_low[u] = dfs_ctr++;
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (dfs_root == u) rootChildren++;
            findArticulationPoints(v);
            if (dfs_low[v] >= dfs_num[u]) {
                isArticulationVertex[u] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int n;
    int ctr = 1;
    while (SCD(n), n != 0) {
        if (ctr > 1) fprintf(stdout, "\n");
        adjList.assign(n, vi());
        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0);
        ans = vector<string>();
        isArticulationVertex.assign(n, false);
        dfs_ctr = 0;
        map<string, int> indices;
        vector<string> locations(n);
        for (int i = 0; i < n; i++) {
            cin >> locations[i];
            indices[locations[i]] = i;
        }
        int m;
        SCD(m);
        for (int i = 0; i < m; i++) {
            string from, to;
            cin >> from >> to;
            adjList[indices[from]].PB(indices[to]);
            adjList[indices[to]].PB(indices[from]);
        }
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == UNVISITED) {
                dfs_root = i;
                rootChildren = 0;
                findArticulationPoints(i);
                isArticulationVertex[i] = rootChildren > 1;
            }
            if (isArticulationVertex[i]) ans.PB(locations[i]);
        }
        sort(ans.begin(), ans.end());
        fprintf(stdout, "City map #%d: %d camera(s) found\n", ctr, ans.size());
        for (int i = 0; i < ans.size(); i++) {
            fprintf(stdout, "%s\n", ans[i].c_str());
        }
        
        ctr++;
    }
	return 0;
}