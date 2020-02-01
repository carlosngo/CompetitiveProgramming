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
    int n;
    while (cin >> n, n != 0) {
        double adjMatrix[n][n];
        // memset(adjMatrix, INF, sizeof adjMatrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) adjMatrix[i][i] = 1.0;
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            m[s] = i;
        }
        int e;
        cin >> e;
        for (int i = 0; i < e; i++) {
            string a, b;
            cin >> a >> b;
            int u = m[a], v = m[b];
            int c, d;
            char ch;
            cin >> c >> ch >> d;
            adjMatrix[u][v] = max(adjMatrix[u][v], 1.0 * d / c);
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adjMatrix[i][j] = max(adjMatrix[i][j], adjMatrix[i][k] * adjMatrix[k][j]);
                }
            }
        }
        bool arbitrage = false;
        for (int i = 0; i < n; i++) {
            if (adjMatrix[i][i] > 1.0) {
                arbitrage = true;
            }   
        }
        if (arbitrage) cout << "Arbitrage\n";
        else cout << "Ok\n";
    }
	
	return 0;
}