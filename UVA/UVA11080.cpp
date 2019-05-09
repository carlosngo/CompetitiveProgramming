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
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	WHILEZ {
        int v, e;
        SCD(v); SCD(e);
        vvi adjList(v, vi());
        vi colors(v, -1);
        bitset<200> visited;
        for (int i = 0; i < e; i++) {
            int from, to;
            SCD(from); SCD(to);
            adjList[from].PB(to);
            adjList[to].PB(from);
        }
        bool isBarpartite = true;
        int ans = 0;
        for (int i = 0; i < v && isBarpartite; i++) {
            if (!visited.test(i)) {
                visited.set(i);
                colors[i] = 0;
                queue<int> q;
                int whites = 0;
                int blacks = 0;
                whites++;
                q.push(i);
                
                while (!q.empty() && isBarpartite) {
                    int cur = q.front();
                    q.pop();
                    for (int j = 0; j < adjList[cur].size(); j++) {
                        int next = adjList[cur][j];
                        if (colors[next] == -1) {
                            colors[next] = 1 - colors[cur];
                            visited.set(next);
                            if (colors[next] == 0) whites++;
                            else blacks++;
                            q.push(next);
                        } else if (colors[next] == colors[cur]) {
                            isBarpartite = false;
                        }
                    }
                }
                if (whites == 0) {
                    ans += blacks;
                } else if (blacks == 0) {
                    ans += whites;
                } else {
                    ans += min(blacks, whites);
                }
            }
        }
        if (isBarpartite) fprintf(stdout, "%d\n", ans);
        else fprintf(stdout, "-1\n");
    }
	return 0;
}