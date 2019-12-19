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
typedef pair<double, int> di;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const int UNVISITED = -1;

int main() {
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    int m, n;
    double r;
    cin >> m >> n >> r;
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    double angle = 180.0 / m;
    double smallR = r / n;
    double arcLen[n + 1];
    arcLen[0] = 0.0;
    for (int i = 1; i < n + 1; i++) arcLen[i] = 2 * M_PI * (i) * smallR * (angle / 360);
	vector<vector<pair<int, double> > > adjList((m + 1) * (n + 1), vector<pair<int, double> >());
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            int curR = i, curC = j;
            int u = curR * (n + 1) + curC; 
            // cout << "Checking neighbors of r = " << curR << " c = " << curC << '\n';
            for (int k = 0; k < 4; k++) {
                int nextR = curR + fx[k][0];
                int nextC = curC + fx[k][1];
                if (LIN(nextR, 0, m + 1) && LIN(nextC, 0, n + 1)) {
                    // cout << "r = " << nextR << " c = " << nextC << " is valid.\n";
                    int v = nextR * (n + 1) + nextC;
                    if (k == 0 || k == 1) {
                        adjList[u].PB(pair<int, double>(v, smallR));
                    }
                    else {
                        adjList[u].PB(pair<int, double>(v, arcLen[curC]));
                    }
                }
            }
        }
    }
    // for (int i = 0; i < adjList.size(); i++) {
    //     cout << i << ':';
    //     for (int j = 0; j < adjList[i].size(); j++) {
    //         cout << adjList[i][j].first << ',' << adjList[i][j].second << '';
    //     }
    //     cout << '\n';
    // }
    int src = ax * (n + 1) + ay;
    int dest = bx * (n + 1) + by;
    vector<double> dist((m + 1) * (n + 1), INF);
    dist[src] = 0;
    priority_queue<di, vector<di>, greater<di> > pq;
    pq.push(di(0, src));
    while (!pq.empty()) {
        di top = pq.top(); pq.pop();
        int cur = top.second;
        double curW = top.first;
        if (curW > dist[cur]) continue;
        for (int i = 0; i < adjList[cur].size(); i++) {
            int next = adjList[cur][i].first;
            double w = adjList[cur][i].second;
            if (dist[cur] + w < dist[next]) {
                dist[next] = dist[cur] + w;
                pq.push(di(dist[next], next));
            }
        }
    }   
    printf("%.6lf", dist[dest]);



	return 0;
}