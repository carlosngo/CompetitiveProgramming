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
	freopen("in.txt", "r", stdin);
	int n;
    while (SCD(n), n != 0) {
        vvi adjList(n, vi());
        vi colors(n, -1);
        int from, to;
        while (fscanf(stdin, "%d%d", &from, &to), from != 0 || to != 0) {
            from--; to--;
            adjList[from].PB(to);
            adjList[to].PB(from);
        }
        bool isBipartite = true;
        for (int i = 0; i < n && isBipartite; i++) {
            if (colors[i] == -1) {
                queue<int> q;
                q.push(i);
                colors[i] = 1;
                while (!q.empty() && isBipartite) {
                    int cur = q.front();
                    q.pop();
                    for (int j = 0; j < adjList[cur].size(); j++) {
                        int next = adjList[cur][j];
                        if (colors[next] == -1) {
                            colors[next] = 1 - colors[cur];
                            q.push(next);
                        } else if (colors[next] == colors[cur])
                            isBipartite = false;
                    }
                }
            }
        }
        if (isBipartite) fprintf(stdout, "YES\n");
        else fprintf(stdout, "NO\n");
    }
	return 0;
}