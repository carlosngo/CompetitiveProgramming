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
typedef pair<double, int> di;
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
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    int n;
    cin >> n;
    double matrix[n + 2][n + 2];
    vii pts(n + 2);
    for (int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;
    cin >> pts[n].first >> pts[n].second >> pts[n + 1].first >> pts[n + 1].second;
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            int x1 = pts[i].first, y1 = pts[i].second;
            int x2 = pts[j].first, y2 = pts[j].second;
            double dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            matrix[i][j] = dist;
            matrix[j][i] = dist;
        }
    }
    priority_queue<di, vector<di>, greater<di> > pq;
    vector<double> dist(n + 2, INF);
    dist[n] = 0;
    vector<int> parent(n + 2, UNVISITED);
    pq.push(di(0, n));
    while (!pq.empty()) {
        int u = pq.top().second;
        double w = pq.top().first;
        // cout << "processing node " << u << " with curW = " << w << '\n';
        pq.pop();
        if (w > dist[u]) continue;
        for (int v = 0; v < n + 2; v++) {
            if (u == v) continue;
            double newW = w + matrix[u][v];
            if (newW < dist[v]) {
                dist[v] = newW;
                pq.push(di(newW, v));
                parent[v] = u;
            }
        }
    }
    // for (int i = 0; i < n + 2; i++) {
    //     cout << "parent of i = " << i << " is " << parent[i] << '\n';
    // }
    if (dist[n + 1] == INF) {
        cout << '-';
    } else {
        int cur = parent[n + 1];
        stack<int> s;
        while (cur != -1) {
            if (cur == n) break;
            s.push(cur);
            cur = parent[cur];
        }
        if (s.empty()) cout << '-';
        else {
            while (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
        }        
    }
	return 0;
}