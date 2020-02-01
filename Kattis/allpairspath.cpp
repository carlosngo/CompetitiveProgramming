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
const ll INF = 1e18 + 10;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, m, q;
    while (cin >> n >> m >> q, !(n == 0 && m == 0 && q == 0)) {
        vector<vector<ll> > adjMatrix = vector<vector<ll> >(n, vector<ll>(n, INF));
        vector<vector<bool> > hasNegativeCycle = vector<vector<bool> >(n, vector<bool>(n, false));
        for (ll i = 0; i < n; i++) adjMatrix[i][i] = 0;

        for (ll i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            adjMatrix[u][v] = min(adjMatrix[u][v], w);
        }

        for (ll k = 0; k < n; k++) {
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    if (adjMatrix[i][k] < INF && adjMatrix[k][j] < INF)
                        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                for (ll k = 0; k < n; k++) {
                    if (adjMatrix[k][k] < 0 && adjMatrix[i][k] != INF && adjMatrix[k][j] != INF) 
                        hasNegativeCycle[i][j] = true;
                }
            }
        }


        for (ll i = 0; i < q; i++) {
            ll src, dest;
            cin >> src >> dest;
            if (adjMatrix[src][dest] == INF) cout << "Impossible\n";
            else if (hasNegativeCycle[src][dest]) cout << "-Infinity\n";
            else cout << adjMatrix[src][dest] << '\n';
        }
        cout << '\n';

    }    
	
	return 0;
}