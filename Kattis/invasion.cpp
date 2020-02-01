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
    int n, m, a, k;
    while (cin >> n >> m >> a >> k, !(n == 0 && m == 0 && a == 0 && k == 0)) {
        vector<vii> adjList(n, vii());
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adjList[u].PB(ii(v, w));
            adjList[v].PB(ii(u, w));
        }
        
        priority_queue<ii, vii, greater<ii> > pq;
        vi dist(n, INF);
        unordered_set<int> ans;
        for (int i = 0; i < n; i++) ans.insert(i);
        for (int i = 0; i < a; i++) {
            int u; 
            cin >> u;
            dist[u - 1] = 0;
            pq.push(ii(0, u - 1));
            ans.erase(u - 1);
            while (!pq.empty()) {
                int u = pq.top().second;
                int w = pq.top().first;
                pq.pop();
                if (w > dist[u]) continue;
                for (int i = 0; i < adjList[u].size(); i++) {
                    int v = adjList[u][i].first;
                    int newW = adjList[u][i].second + w;
                    if (newW < dist[v]) {
                        if (newW < k) ans.erase(v);
                        dist[v] = newW;
                        pq.push(ii(newW, v));
                    }
                }
            }
            cout << ans.size() << '\n';
        }
        cout << '\n';
    }
	return 0;
}