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

class UnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
UnionFind(int N) { rank.assign(N, 0);
p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
if (!isSameSet(i, j)) { // if from different set
int x = findSet(i), y = findSet(j);
if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
else { p[x] = y;
if (rank[x] == rank[y]) rank[y]++; }
} } };

vvi adjList, modifiedG;
vi dfs_num, dfs_low, dfs_parent;
int dfs_ctr;
UnionFind ufds(10000);

void findBridges(int u) {
    dfs_num[u] = dfs_low[u] = dfs_ctr++;
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            findBridges(v);
            if (dfs_low[v] > dfs_num[u]) ufds.unionSet(u, v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	freopen("out.txt", "wt", stdout);
	freopen("in.txt", "r", stdin);
    int r, c, q;
    while (fscanf(stdin, "%d%d%d", &r, &c, &q), r != 0 || c != 0 || q != 0) {
        adjList.assign(r, vi());
        modifiedG.assign(r, vi());
        ufds = UnionFind(r);
        dfs_num.assign(r, UNVISITED);
        dfs_low.assign(r, 0);
        dfs_parent.assign(r, 0);
        dfs_ctr = 0;
        for (int i = 0; i < c; i++) {
            int from, to;
            SCD(from); SCD(to);
            from--; to--;
            adjList[from].PB(to);
            adjList[to].PB(from);
        }
        for (int i = 0; i < r; i++) {
            if (dfs_num[i] == UNVISITED) {
                findBridges(i);
            }
        }
        
        for (int i = 0; i < q; i++) {
            int start, end;
            SCD(start); SCD(end);
            start--; end--;
            if (ufds.isSameSet(start, end)) fprintf(stdout, "Y\n");
            else fprintf(stdout, "N\n");
        }
        fprintf(stdout, "-\n");
    }
	return 0;
}