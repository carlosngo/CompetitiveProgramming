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
bitset<33> visited;
int dfs_parent[33];

void dfs(int u) {
    visited.set(u);
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (!visited.test(v)) {
            dfs_parent[v] = u;
            dfs(v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    unordered_map<string, int> m;
    bool hasConnection[2000][2000];
    memset(hasConnection, false, sizeof(hasConnection));
    unordered_set<string> s;
    string names[2000];
    int index = 0;
    adjList = vvi(2000, vi());
    memset(dfs_parent, -1, sizeof(dfs_parent));
    while (n--) {
        getline(cin, line);
        // cout << line;
        stringstream ss(line);
        string src, dest;
        ss >> src;
        int u;
        if (s.find(src) == s.end()) {
            m[src] = index;
            names[index] = src;
            u = index;
            s.insert(src);
            index++;
        } else u = m[src];
        
        while (ss >> dest) {
            int v;
            if (s.find(dest) == s.end()) {
                m[dest] = index;
                names[index] = dest;
                v = index;
                s.insert(dest);
                index++;
            } else v = m[dest];
            // cout << "u, v = " << u << ',' << v << '\n';
            if (!hasConnection[u][v]) {
                hasConnection[u][v] = true;
                hasConnection[v][u] = true;
                adjList[u].PB(v);
                adjList[v].PB(u);
            }
        }
    }
    string start, end;
    cin >> start >> end;
    if (m.find(start) == m.end() || m.find(end) == m.end()) {
        cout << "no route found";
        return 0;
    }
    int a = m[start];
    int b = m[end];
    dfs(a);
    if (visited.test(b)) {
        vi arr;
        int ind = b;
        while (dfs_parent[ind] != -1) {
            arr.PB(ind);
            ind = dfs_parent[ind];
        }
        arr.PB(ind);
        for (int i = arr.size() - 1; i >= 0; i--) {
            cout << names[arr[i]] << ' ';
        }
    } else cout << "no route found";
         
    
	return 0;
}