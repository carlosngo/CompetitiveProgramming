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
    int n, h, l;
    SCD(n); SCD(h); SCD(l);
    vi dfs_num(n, UNVISITED);
    vvi adjList(n, vi());
    queue<int> q;
    for (int i = 0; i < h; i++) {
        int num;
        SCD(num);
        q.push(num);
        dfs_num[num] = 0;
    }
    for (int i = 0; i < l; i++) {
        int u, v;
        SCD(u); SCD(v);
        adjList[u].PB(v);
        adjList[v].PB(u);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int depth = dfs_num[u];
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (dfs_num[v] == UNVISITED) {
                dfs_num[v] = depth + 1;
                q.push(v);
            }
        }
    }
    int cur = 0; 
    int maxHI = INT_MIN;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == UNVISITED) {
            ans = i;
            break;
        } else if (maxHI < dfs_num[i]) {
            maxHI = dfs_num[i];
            ans = i;
        }
    }
    fprintf(stdout, "%d", ans);
	return 0;
}