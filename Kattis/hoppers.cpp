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

vvi adjList;


int main() {
    int n, m;
    cin >> n >> m;
    adjList = vvi(n, vi());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].PB(v);
        adjList[v].PB(u);
    }
    int ans = 0;
    bool hasOdd = false;
    int colors[n];
    memset(colors, UNVISITED, sizeof(colors));
    for (int i = 0; i < n; i++) {
        if (colors[i] == UNVISITED) {
            bool isBipartite = true;
            queue<int> q;
            q.push(i);
            colors[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int j = 0; j < adjList[u].size(); j++) {
                    int v = adjList[u][j];
                    if (colors[v] == UNVISITED) {
                        q.push(v);
                        colors[v] = 1 - colors[u];
                    } else if (colors[u] == colors[v]) isBipartite = false;
                }
            }
            if (!isBipartite) hasOdd = true;
            ans++;
        }
    }
    if (hasOdd) ans--;
	cout << ans;
	return 0;
}