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
    WHILEZ {
        map<ii, int> m;
        vector<unordered_set<int> > adjList; 
        int n;
        SCD(n);
        getchar();
        int dest;
        int curR = 0, curC = 0;
        ii src = ii(curR, curC);
        adjList.PB(unordered_set<int>());
        m[src] = 0;
        int curI = 1;
        for (int i = 0; i < n; i++) {
            char dir;
            SCC(dir);
            ii curPos = ii(curR, curC);
            int u = m[curPos];
            if (dir == 'N') curR--;
            else if (dir == 'E') curC++;
            else if (dir == 'W') curC--;
            else curR++;
            ii newPos = ii(curR, curC);
            int v;
            if (m.find(newPos) == m.end()) {
                m[newPos] = curI;
                v = curI;
                curI++;
                adjList.PB(unordered_set<int>());
            } else v = m[newPos];
            adjList[u].insert(v);
            if (i == n - 1) dest = v;
            getchar();
        }
        queue<int> q;
        q.push(0);
        vi dist(adjList.size(), UNVISITED);
        dist[0] = 0;
        int ans = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int d = dist[u];
            if (u == dest) {
                ans = d;
                break;
            }
            for (unordered_set<int>::iterator itr = adjList[u].begin(); itr != adjList[u].end(); itr++) {
                int v = *itr;
                if (dist[v] == UNVISITED) {
                    dist[v] = d + 1;
                    q.push(v);
                }
            }
            // for (int i = 0; i < adjList[u].size(); i++) {
            //     int v = adjList[u][i];
            //     if (dist[v] == UNVISITED) {
            //         dist[v] = d + 1;
            //         q.push(v);
            //     }
            // }
        }
        cout << ans << '\n';
    }
	return 0;
}