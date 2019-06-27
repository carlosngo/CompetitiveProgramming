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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int m;
    int ctr = 1;
    while (SCD(m), m != 0) {
        int ind = 1;
        vi nodes;
        vvi adjList(30, vi());
        map<int, int> indices;
        for (int i = 0; i < m; i++) {
            int src, dest;
            SCD(src); SCD(dest);
            if (indices[src] == 0) {
                indices[src] = ind;
                nodes.PB(src);
                ind++;
            } 
            if (indices[dest] == 0) {
                indices[dest] = ind;
                nodes.PB(dest);
                ind++;
            }
            int u = indices[src] - 1;
            int v = indices[dest] - 1;
            adjList[u].PB(v);
            adjList[v].PB(u);
        }
        int src, ttl;
        while (fscanf(stdin, "%d%d", &src, &ttl), src != 0 || ttl != 0) {
            if (indices[src] == 0) {
                fprintf(stdout, "Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ctr, nodes.size(), src, ttl);
                ctr++;
                continue;
            }
            vi dist(nodes.size(), UNVISITED);
            int temp = src;
            src = indices[src] - 1;
            dist[src] = 0;
            queue<int> q;
            q.push(src);
            int ans = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int i = 0; i < adjList[cur].size(); i++) {
                    int next = adjList[cur][i];
                    if (dist[next] == UNVISITED) {
                        dist[next] = dist[cur] + 1;
                        if (dist[next] > ttl) {
                            ans++;
                        }
                        q.push(next);
                    }
                }
            }
            for (int i = 0; i < dist.size(); i++) {
                if (dist[i] == UNVISITED) ans++;
            }
            fprintf(stdout, "Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ctr, ans, temp, ttl);
            ctr++;
        }
        
    }
	return 0;
}