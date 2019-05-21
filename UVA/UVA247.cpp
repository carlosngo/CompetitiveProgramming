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
map<string, int> indices;
vi dfs_num, dfs_low, dfs_parent;
int dfs_ctr;
vector<bool> visited;
vector<string> names;
stack<int> s;

void findSCC(int u) {
    dfs_num[u] = dfs_low[u] = dfs_ctr++;
    s.push(u);
    visited[u] = true;
    // fprintf(stdout, "%d ->", u);
    // for (int i = 0; i < adjList[u].size(); i++) {
    //     int v = adjList[u][i];
    //     fprintf(stdout, " %d", v);
    // }
    // fprintf(stdout, "\n");
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        // fprintf(stdout, " %d", v);
        if (dfs_num[v] == UNVISITED) {
            findSCC(v);
        }
        if (visited[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }
    
    if (dfs_num[u] == dfs_low[u]) {
        int ctr = 0;
        while (true) {
            if (ctr) fprintf(stdout, ", ");
            int top = s.top();
            visited[top] = false;
            s.pop();
            fprintf(stdout, "%d", top);
            // fprintf(stdout, "%s", names[top].c_str());
            ctr++;
            if (top == u) break;
        }
        fprintf(stdout, "\n");
    }
}

int main() {
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	freopen("out.txt", "wt", stdout);
	freopen("in.txt", "r", stdin);
    int n, m;
    int ctr = 1;
    while (fscanf(stdin, "%d%d", &n, &m), n != 0 || m != 0) {
        if (ctr > 1) fprintf(stdout, "\n");
        adjList.assign(n, vi());
        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0);
        dfs_ctr = 0;
        indices = map<string, int>();
        names = vector<string>();
        s = stack<int>();
        visited.assign(n, false);
        int ind = 1;
        for (int i = 0; i < m; i++) {
            string src, dest;
            cin >> src >> dest;
            if (indices[src] == 0) {
                indices[src] = ind;
                names.PB(src);
                ind++;
            }
            if (indices[dest] == 0) {
                indices[dest] = ind;
                names.PB(dest);
                ind++;
            }
            adjList[indices[src] - 1].PB(indices[dest] - 1);
        }
        fprintf(stdout, "Calling circles for data set %d:\n", ctr);
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == UNVISITED) {
                findSCC(i);
            }
        }
        ctr++;
    }
	
	return 0;
}