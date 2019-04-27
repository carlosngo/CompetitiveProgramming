#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
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

typedef pair<int,int> ii;
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
	FILE *pFile = fopen("out.txt","w");
    int n; 
    cin >> n;
    FOR (i, 1, n + 1, 1) {
        int v, e;
        cin >> v >> e;
        vector<vii> adjList(v, vii());
        vi dist(v, INT_MAX);
        int start, end;
        cin >> start >> end;
        dist[start] = 0;
        FOR (j, 0, e, 1) {
            int a, b, w;
            cin >> a >> b >> w;
            adjList[a].PB(ii(b, w));  
            adjList[b].PB(ii(a, w));
        }
        priority_queue<ii, vii, greater<ii> > q;
        q.push(ii(0, start));
        while (!q.empty()) {
            ii nextState = q.top(); q.pop();
            if (nextState.second == end) {
                break;
            }
            if (dist[nextState.second] < nextState.first) {
                continue;
            }
            FOR(j, 0, adjList[nextState.second].size(), 1) {
                ii nextNode = adjList[nextState.second][j];
                if (dist[nextNode.first] > dist[nextState.second] + nextNode.second) {
                    dist[nextNode.first] = dist[nextState.second] + nextNode.second;
                    q.push(ii(dist[nextNode.first], nextNode.first));
                }
            }
        }
        
        if (dist[end] != INT_MAX) {
            printf("Case #%d: %d\n", i, dist[end]);
            fprintf(pFile,"Case #%d: %d\n", i, dist[end]);
            // cout << "Case #" << i << ": " << dist[end] << "\n"; 
        } else { 
            printf("Case #%d: unreachable\n", i);
            fprintf(pFile,"Case #%d: unreachable\n", i);
            // cout << "Case #" << i << ": unreachable\n"; 
        }
    }
	fclose(pFile);
	return 0;
}