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

vector<vector<pair<double, int> > > adjList;
vector<bool> visited;

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

void dfs(int u, double cost) {
    if (u == 1) {
        fprintf(stdout, "Frog Distance = %.3lf\n", cost);
    } 
    visited[u] = true;
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].second;
        double w = adjList[u][i].first;
        if (!visited[v]) dfs(v, max(cost, w));
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int n;
    int ctr = 1;
    while (SCD(n), n != 0) {
        UnionFind ufds(n);
        vector<pair<double, ii> > edges;
        vii points;
        for (int i = 0; i < n; i++) {
            int x, y;
            SCD(x); SCD(y);
            points.PB(ii(x, y));
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = sqrt((points[i].first - points[j].first) * (points[i].first - points[j].first) +
                                  (points[i].second - points[j].second) * (points[i].second - points[j].second));
                edges.PB(pair<double, ii>(dist, ii(i, j)));
            }
        }
        sort(edges.begin(), edges.end());
        adjList.assign(n, vector<pair<double, int> >());
        visited.assign(n, false);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            double w = edges[i].first;
            // fprintf(stdout, "%d <-> %d %lf\n", u, v, w);
            if (!ufds.isSameSet(u, v)) {
                adjList[u].PB(pair<double, int>(w, v));
                adjList[v].PB(pair<double, int>(w, u));
                ufds.unionSet(u, v);
            }
        }
        fprintf(stdout, "Scenario #%d\n", ctr);
        dfs(0, 0.0);
        fprintf(stdout, "\n");
        ctr++;
    }

	return 0;
}