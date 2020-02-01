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

int ans = 0;
bitset<10001> visited;
vvi parents;
int s, t; 

void dfs(int u) {
    if (u == s) ans++;
    for (int i = 0; i < parents[u].size(); i++) {
        int v = parents[u][i];
        dfs(v);
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, e;
    cin >> n >> e;
    vi dist(n, INF);
    vector<vii> adjList(n, vii());
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].PB(ii(v, w));
    }
    cin >> s >> t;
    if (s == t) {
        cout << "1";
        return 0;
    }
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(0,s));
    dist[s] = 0;
    parents = vvi(n, vi());
    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (w > dist[u]) continue;
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first;
            int newW = w + adjList[u][i].second;
            if (newW < dist[v]) {
                parents[v] = vi();
                parents[v].PB(u);
                dist[v] = newW;
                pq.push(ii(newW, v));
            } else if (newW == dist[v]) {
                parents[v].PB(u);
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << "parents of " << i << " are: ";
    //     for (int j = 0; j < parents[i].size();j++) {
    //         cout << parents[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    dfs(t);
    cout << ans;
	return 0;
}