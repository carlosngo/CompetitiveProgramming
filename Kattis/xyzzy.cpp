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
const int cx[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int UNVISITED = -1;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int n;
    while (cin >> n, n != -1) {
        // UnionFind ufds(n);
        vvi adjList(n, vi());
        vi dist(n, INF);
        dist[0] = -100;
        vi rooms(n);
        for (int u = 0; u < n; u++) {
            cin >> rooms[u];
            int e;
            cin >> e;
            for (int i = 0; i < e; i++) {
                int v;
                cin >> v;
                v--;
                adjList[u].PB(v);
                
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int u = 0; u < n; u++) {
                if (dist[u] == INF) continue;
                for (int j = 0; j < adjList[u].size(); j++) {
                    int v = adjList[u][j];
                    int w = -rooms[v];
                    if (dist[u] + w >= 0) continue;
                    dist[v] = min(dist[v], dist[u] + w);
                }
            }
        }
        bool done = false;
        vector<bool> hasNegativeCycle(n, false);
        while (!done) {
            done = true;
            for (int u = 0; u < n; u++) {
                if (dist[u] == INF) continue;
                for (int i = 0; i < adjList[u].size(); i++) {
                    int v = adjList[u][i];
                    int w = -rooms[v];
                    if (dist[u] + w < dist[v] && !hasNegativeCycle[v] && dist[u] + w < 0) {
                        dist[v] = -INF;
                        done = false;
                        hasNegativeCycle[v] = true;
                    }
                }
            }
        }
        
        if (hasNegativeCycle[n - 1] || dist[n - 1] < 0) cout << "winnable\n";
        else cout << "hopeless\n";
    }
	return 0;
}