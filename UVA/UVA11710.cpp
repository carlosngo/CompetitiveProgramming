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
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int n, m;
    while (fscanf(stdin, "%d%d", &n, &m), n != 0 || m != 0) {
        UnionFind ufds(n);
        vector<iii> edges;
        vector<string> locs;
        map<string, int> indices;
        for (int i = 0; i < n; i++) {
            string loc;
            cin >> loc;
            locs.PB(loc);
            indices[loc] = i;
        }
        for (int i = 0; i < m; i++) {
            string src, dest;
            int w;
            cin >> src >> dest >> w;
            edges.PB(iii(w, ii(indices[src], indices[dest])));
        }
        string s;
        cin >> s;
        int start = indices[s];
        sort(edges.begin(), edges.end());
        int ans = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if (!ufds.isSameSet(u, v)) {
                ans += edges[i].first;
                ufds.unionSet(u, v);
            }
        }
        bool valid = true;
        for (int i = 0; i < n && valid; i++) {
            if (!ufds.isSameSet(start, i)) valid = false; 
        }
        if (valid) fprintf(stdout, "%d\n", ans);
        else fprintf(stdout, "Impossible\n");
    }
	return 0;
}