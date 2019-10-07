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
    int c, p, x, l;
    cin >> c >> p >> x >> l;
    x--; l--;
    vvi adjList(c, vi());
    int numPartners[c];
    memset(numPartners, 0, sizeof(numPartners));
    bool visited[c];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        numPartners[u]++;
        numPartners[v]++;
        adjList[u].PB(v);
        adjList[v].PB(u);
    }
    
    queue<int> q;
    q.push(l);
    visited[l] = true;
    int updatedPartners[c];
    for (int i = 0; i < c; i++) updatedPartners[i] = numPartners[i];
    while (!q.empty()) {
        int cur = q.front();
        // cout << cur << '\n';
        q.pop();
        for (int i = 0; i < adjList[cur].size(); i++) {
            int next = adjList[cur][i];
            updatedPartners[next]--;
            if (updatedPartners[next] <= numPartners[next] / 2 && !visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    if (visited[x]) cout << "leave";
    else cout << "stay";
	return 0;
}