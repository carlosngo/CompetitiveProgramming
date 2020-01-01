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
typedef pair<int, iii> iiii;
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
    int n, m, q, s;
    while (cin >> n >> m >> q >> s, !(n == 0 && m == 0 && q == 0 && s == 0)) {
        vector<vector<iiii> > adjList(n, vector<iiii>());
        vi time(n);
        vi intervals(n);
        for (int i = 0; i < m; i++) {
            int u, v, t, P, w;
            cin >> u >> v >> t >> P >> w;
            adjList[u].PB(iiii(v, iii(t, ii(P, w))));
        }
        vi dist(n, INF);
        dist[s] = 0;
        priority_queue<ii, vii, greater<ii> > pq;
        pq.push(ii(0, s));
        while (!pq.empty()) {
            int u = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            // cout << "Processing node " << u << " with time = " << t << '\n';
            if (t > dist[u]) continue;
            for (int i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u][i].first;
                int start = adjList[u][i].second.first;
                int interval = adjList[u][i].second.second.first;
                int w = adjList[u][i].second.second.second;
                if (interval == 0 && t > start) continue;
                int earliest;
                if (t < start) earliest = start;
                else earliest = start + ceil(1.0 * (t - start) / interval) * interval;
                int finish = earliest + w;
                // cout << "Earliest to go from " << u << " to " << v << " is " << earliest << ", finishing at " << finish << '\n';
                if (finish < dist[v]) {
                    dist[v] = finish;
                    pq.push(ii(finish, v));
                }
            }
        }
        for (int i = 0; i < q; i++) {
            int dest;
            cin >> dest;
            if (dist[dest] == INF) cout << "Impossible\n";
            else cout << dist[dest] << '\n';
        }
        cout << '\n';

    }
	
	return 0;
}