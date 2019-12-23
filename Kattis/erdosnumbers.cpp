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
    unordered_map<string, int> m;
    int cur = 0;
    vvi adjList;
    string line;
    vector<string> authors;
    int src;
    while (getline(cin, line)) {
        stringstream ss(line);
        string author, coauthor;
        ss >> author;
        authors.PB(author);
        int u, v;
        if (m.find(author) == m.end()) {
            m[author] = cur;
            u = cur;
            adjList.PB(vi());
            cur++;
        } else u = m[author];
        if (author == "PAUL_ERDOS") src = u;
        while (ss >> coauthor) {
            if (m.find(coauthor) == m.end()) {
                m[coauthor] = cur;
                v = cur;
                adjList.PB(vi());
                cur++;
            } else v = m[coauthor];
            adjList[u].PB(v);
            adjList[v].PB(u);
        }
    }
    vi dist(adjList.size(), UNVISITED);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int d = dist[u];
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (dist[v] == UNVISITED) {
                dist[v] = d + 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < authors.size(); i++) {
        string author = authors[i];
        if (dist[m[author]] == -1) cout << author << " no-connection\n";
        else cout << author << ' ' << dist[m[author]] << '\n';
    }
	return 0;
}