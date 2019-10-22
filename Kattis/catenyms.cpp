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
bitset<1001> visited;
string words[1001];
int n;
vi dfs_parent;
bool found;

void dfs(int u, int depth) {
    if (found) return;
    // cout << "words[u] = " << words[u] << "depth = " << depth << '\n';
    visited.set(u);
    if (depth == n) {
        int cur = u;
        vector<string> v;
        v.PB(words[cur]);
        while (dfs_parent[cur] != -1) {
            v.PB(words[dfs_parent[cur]]);
            cur = dfs_parent[cur];
        }
        int j = 0;
        for (int i = (int)v.size() - 1; i >= 0; i--) {
            if (j) cout << '.';
            cout << v[i];
            j++;
        }
        cout << '\n';
        found = true;
    }
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (!visited.test(v)) {
            dfs_parent[v] = u;
            dfs(v, depth + 1);
        }
    }
    visited.reset(u);
}


int main() {
    WHILEZ {
        cin >> n;
        adjList = vvi(n, vi());
        dfs_parent.assign(n, UNVISITED);
        visited = bitset<1001>(); 
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string s1 = words[i];
                string s2 = words[j];
                if (s1[s1.length() - 1] == s2[0]) {
                    // cout << "s1, s2 = " << s1 << ',' << s2 << '\n';
                    adjList[i].PB(j);
                }
                if (s2[s2.length() - 1] == s1[0]) {
                    // cout << "s2, s1 = " << s1 << ',' << s2 << '\n';
                    adjList[j].PB(i);
                }
            }
        }
        bool ans = false;
        for (int i = 0; i < n; i++) {
            bitset<1001> visited;
            dfs_parent[i] = -1;
            found = false;
            dfs(i, 1);
            if (found) {
                ans = true;
                break;
            } 
        }
        if (!ans) cout << "***\n";
    }
	return 0;
}