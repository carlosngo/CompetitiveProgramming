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
vi dfs_num, dfs_low, dfs_parent, dove_values;
int dfs_ctr, dfs_root, rootChildren;
vector<bool> isArticulationPoint;
vii articulation_points;

bool compare(ii a, ii b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        return a.first <= b.first;
    } else {
        return false;
    }
}

void findArticulationPoints(int u) {
    dfs_num[u] = dfs_low[u] = dfs_ctr++;
    set<int> lows;
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfs_root) rootChildren++;
            findArticulationPoints(v);
            if (dfs_low[v] >= dfs_num[u]) {
                // if (u != dfs_root)
                    dove_values[u]++;
                isArticulationPoint[u] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            // lows.insert(dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            // lows.insert(dfs_low[v]);
        }
    }
    // dove_values[u] = lows.size();
}


int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	freopen("out.txt", "wt", stdout);
	freopen("in.txt", "r", stdin);
	int n, m;
    while (fscanf(stdin, "%d%d", &n, &m), n != 0 || m != 0) {
        adjList.assign(n, vi());
        dfs_num.assign(n, UNVISITED);
        dfs_parent.assign(n, 0);
        dfs_low.assign(n, 0);
        dove_values.assign(n, 1);
        dfs_ctr = 0;
        articulation_points = vii();
        isArticulationPoint.assign(n, false);
        int from, to;
        while (fscanf(stdin, "%d%d", &from, &to), from != -1 || to != -1) {
            adjList[from].PB(to);
            adjList[to].PB(from);
        }
        dfs_root = 0;
        rootChildren = 0;
        findArticulationPoints(0);
        dove_values[0]--;
        for (int i = 0; i < n; i++) {
            articulation_points.PB(ii(i, dove_values[i]));
        }
        sort(articulation_points.begin(), articulation_points.end(), compare);
        for (int i = 0; i < m; i++) {
            fprintf(stdout, "%d %d\n", articulation_points[i].first, articulation_points[i].second);
        }
        fprintf(stdout, "\n");
    }
}