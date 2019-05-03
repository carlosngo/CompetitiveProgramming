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



int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	freopen("out.txt", "wt", stdout);
	int t;
    SCD(t);
    for (int ctr = 1; ctr <= t; ctr++) {
        int totalUnits = 0;
        int finalNode = -1;
        vvi adjList;
        vi nodeUnits;
        totalUnits = 0;
        finalNode = -1;
        int n, m;
        SCD(n); SCD(m);
        adjList.assign(n, vi());
        nodeUnits = vi(m);
        int startNode = -1;
        for (int i = 0; i < n; i++) {
            SCD(nodeUnits[i]);
            if (nodeUnits[i] == 0) startNode = i;
        }
        for (int i = 0; i < m; i++) {
            int from, to;
            SCD(from); SCD(to);
            adjList[from].PB(to);
        }
        queue<int> q;
        q.push(startNode);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int maxUnits = INT_MIN;
            int maxIndex = -1;
            totalUnits += nodeUnits[cur];
            if (adjList[cur].empty()) {
                finalNode = cur;
                break;
            }
            for (int i = 0; i < adjList[cur].size(); i++) {
                int next = adjList[cur][i];
                if (nodeUnits[next] > maxUnits) {
                    maxUnits = nodeUnits[next];
                    maxIndex = i;
                }
            }
            q.push(adjList[cur][maxIndex]);
        }
        fprintf(stdout, "Case %d: %d %d\n", ctr, totalUnits, finalNode);
    }
	return 0;
}