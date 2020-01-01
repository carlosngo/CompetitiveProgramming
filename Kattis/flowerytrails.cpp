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
    int p, t;
    cin >> p >> t;
    vector<vii> adjList(p, vii());
    for (int i = 0; i < t; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].PB(ii(v, w));
        adjList[v].PB(ii(u, w));
    }
    vi dist(p, INF);
    dist[0] = 0;
    vector<vii> parents(p, vii());
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(0, 0));
	
    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (w > dist[u]) continue;
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first;
            int newW = w + adjList[u][i].second;
            if (newW < dist[v]) {
                parents[v] = vii();
                parents[v].PB(ii(u, adjList[u][i].second));
                dist[v] = newW;
                pq.push(ii(dist[v], v));
            } else if (newW == dist[v]) {
                parents[v].PB(ii(u, adjList[u][i].second));
            }
        }
    }
    int ans = 0;
    queue<int> q;
    bitset<10001> visited;
    visited.set(0);
    q.push(p - 1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        // cout << "children of " << u << " are: "; 
        for (int i = 0; i < parents[u].size(); i++) {
            int v = parents[u][i].first;
            ans += parents[u][i].second;
            if (!visited.test(v)) {
                visited.set(v);
                q.push(v);
            }            
        }
        // cout << '\n';
        // cout << "ans = " << ans << '\n';
    }
    cout << (ans * 2);    
	return 0;
}