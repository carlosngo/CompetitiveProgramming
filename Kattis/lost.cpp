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
typedef vector<vii> vvii;

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
    int n, m;
    cin >> n >> m;
    vi depth(n + 1, UNVISITED);
    vi dfs_parent(n + 1, UNVISITED);
    int costs[n + 1][n + 1];
    vector<ll> dist(n + 1, INT_MAX);
    vvii adjList(n + 1, vii());
    unordered_map<string, int> ma;
    depth[0] = 0;
    dist[0] = 0;
    string s = "English";
    ma[s] = 0;
    for (int i = 1; i <= n; i++) {
        string lang;
        cin >> lang;
        ma[lang] = i;
    }
    for (int i = 0; i < m; i++) {
        string src, dest;
        cin >> src >> dest;
        int cost;
        cin >> cost;
        int u = ma[src];
        int v = ma[dest];
        costs[u][v] = cost;
        costs[v][u] = cost;
        adjList[u].PB(ii(v, cost));
        adjList[v].PB(ii(u, cost));
    }

    queue<int> q;
    q.push(0);
    ll ans = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int d = depth[u];
        ll cost = dist[u];
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first;
            int c = adjList[u][i].second;
            int newDepth = d + 1;
            ll newCost = cost + c;
            if (depth[v] == UNVISITED) {
                depth[v] = newDepth;
                dist[v] = newCost;
                ans += c;
                dfs_parent[v] = u;
                q.push(v);
            } else if (depth[v] == newDepth && newCost < dist[v]) {
                int prevParent = dfs_parent[v];
                ans -= costs[v][prevParent];
                ans += c;
                dfs_parent[v] = u;
                dist[v] = newCost;
                // q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (depth[i] == -1) {
            cout << "Impossible";
            return 0;
        }
    }
    cout << ans;
	return 0;
}