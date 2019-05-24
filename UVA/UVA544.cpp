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

vector<vii> adjList;
vector<bool> visited;
int start, endi;

void dfs(int u, int cost) {
    if (u == endi) {
        fprintf(stdout, "%d tons\n\n", cost);
    }
    visited[u] = true;
    for (int i = 0; i < adjList[u].size(); i++) {
        int w = adjList[u][i].first;
        int v = adjList[u][i].second;
        if (!visited[v]) dfs(v, min(cost, w));
    }
}

int main() {
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int n, m;
    int ctr = 1;
    while (fscanf(stdin, "%d%d", &n, &m), n != 0 || m != 0) {
        UnionFind ufds(n);
        map<string, int> indices;
        vector<iii> edges;
        int ind = 1;
        string src, dest;
        for (int i = 0; i < m; i++) {
            int w;
            cin >> src >> dest >> w;
            if (indices[src] == 0) {
                indices[src] = ind;
                ind++;
            } 
            if (indices[dest] == 0) {
                indices[dest] = ind;
                ind++;
            }
            edges.PB(iii(w, ii(indices[src] - 1, indices[dest] - 1)));
        }
        // sort(edges.begin(), edges.end());
        sort(edges.begin(), edges.end(), greater<iii>());
        adjList.assign(n, vii());
        visited.assign(n, false);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int w = edges[i].first;
            if (!ufds.isSameSet(u, v)) {
                adjList[u].PB(ii(w, v));
                adjList[v].PB(ii(w, u));
                ufds.unionSet(u, v);
            }
        }
        cin >> src >> dest;
        start = indices[src] - 1;
        endi = indices[dest] - 1;
        fprintf(stdout, "Scenario #%d\n", ctr);
        dfs(start, INT_MAX);
        ctr++;
    }
	return 0;
}