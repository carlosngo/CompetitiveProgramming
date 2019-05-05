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
	int t;
    SCD(t);
    while (t--) {
        int n, m, l;
        SCD(n); SCD(m); SCD(l);
        vvi adjList(n, vi());
        for (int i = 0; i < m; i++) {
            int from, to;
            SCD(from); SCD(to);
            from--; to--;
            adjList[from].PB(to);
        }
        int ans = 0;
        bitset<10000> bs;
        for (int i = 0; i < l; i++) {
            int start;
            SCD(start);
            start--;
            if (!bs.test(start)) {
                ans++;
                queue<int> q;
                q.push(start);
                bs.set(start);
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (int j = 0; j < adjList[cur].size(); j++) {
                        int next = adjList[cur][j];
                        if (!bs.test(next)) {
                            bs.set(next);
                            ans++;
                            q.push(next);
                        }
                    }
                }
            }
        }
        fprintf(stdout, "%d\n", ans);
    }
	return 0;
}