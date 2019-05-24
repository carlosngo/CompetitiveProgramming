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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	WHILEZ {
        int n, m;
        SCD(n); SCD(m);
        UnionFind ufds(n);
        vector<iii> edges;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            SCD(u); SCD(v); SCD(w);
            u--; v--;
            edges.PB(iii(w, ii(u, v)));
        }
        sort(edges.begin(), edges.end());
        int first = 0, second = INT_MAX;
        vi mst;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int w = edges[i].first;
            if (!ufds.isSameSet(u, v)) {
                mst.PB(i);
                first += w;
                ufds.unionSet(u, v);
            }
        }
        
        for (int i = 0; i < mst.size(); i++) {
            UnionFind uf(n);
            int removedEdge = mst[i];
            int cost = 0;
            for (int j = 0; j < edges.size(); j++) {
                if (j == removedEdge) continue;
                int u = edges[j].second.first;
                int v = edges[j].second.second;
                int w = edges[j].first;
                if (!uf.isSameSet(u, v)) {
                    cost += w;
                    uf.unionSet(u, v);
                }
            }
            bool connected = true;
            for (int j = 1; j < n; j++) if (!uf.isSameSet(j, 0)) connected = false;
            if (connected) second = min(second, cost);
        }
        fprintf(stdout, "%d %d\n", first, second);

    }
	return 0;
}