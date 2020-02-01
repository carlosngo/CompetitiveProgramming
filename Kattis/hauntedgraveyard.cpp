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

int r, c;
int convertTo1D(int row, int col) {
    return row * c + col;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    while (cin >> r >> c, r != 0 || c != 0) {
        int n = r * c;
        vector<vii> adjList(n, vii());
        int g;
        cin >> g;
        bitset<901> graves;
        bitset<901> holes;
        for (int i = 0; i < g; i++) {
            int row, col;
            cin >> row >> col;
            graves.set(convertTo1D(row, col));
        }
        
        int e;
        cin >> e;
        for (int i = 0; i < e; i++) {
            int ux, uy, vx, vy, w;
            cin >> ux >> uy >> vx >> vy >> w;
            int u = convertTo1D(ux, uy);
            int v = convertTo1D(vx, vy);
            adjList[u].PB(ii(v, w));
            holes.set(u);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int u = convertTo1D(i, j);
                if (graves.test(u) || holes.test(u) || u == n - 1) continue;
                for (int k = 0; k < 4; k++) {
                    int nextR = i + fx[k][0];
                    int nextC = j + fx[k][1];
                    if (LIN(nextR, 0, r) && LIN(nextC, 0, c)) {
                        int v = convertTo1D(nextR, nextC);
                        if (!graves.test(v)) {
                            // cout << "connecting u = " << u << " and v = " << v << "\n"; 
                            adjList[u].PB(ii(v, 1));
                        }
                    }
                }
            }
        }
        vi dist(n, INF);
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int u = 0; u < n; u++) {
                if (dist[u] == INF) continue;
                for (int j = 0; j < adjList[u].size(); j++) {
                    int v = adjList[u][j].first;
                    int w = adjList[u][j].second;
                    dist[v] = min(dist[v], dist[u] + w);
                }
            }
        }
        bool hasNegativeCycle = false;
        for (int u = 0; u < n; u++) {
            if (dist[u] == INF) continue;
            for (int i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u][i].first;
                int w = adjList[u][i].second;
                if (dist[v] > dist[u] + w) hasNegativeCycle = true;
            }
        }
        if (hasNegativeCycle) cout << "Never\n";
        else if (dist[n - 1] == INF) cout << "Impossible\n";
        else cout << dist[n - 1] << '\n';
    }
	return 0;
}