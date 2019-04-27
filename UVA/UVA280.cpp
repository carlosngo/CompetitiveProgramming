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
	int v;
    while (SCD(v), v != 0) {
        vvi adjList = vvi(v, vi());
        int i;
        while (SCD(i), i != 0) {
            int j;
            i--;
            while (SCD(j), j != 0) {
                j--;
                adjList[i].PB(j);
            }
        }
        int q;
        SCD(q);
        while (q--) {
            int start;
            SCD(start);
            start--;
            int cnt = 0;
            vi ans;
            if (start < v && start >= 0) {
                bitset<101> bs;
                queue<int> q;
                q.push(start);
                while (!q.empty()) {
                    
                    int cur = q.front(); q.pop();
                    for (int i = 0; i < adjList[cur].size(); i++) {
                        if (!bs.test(adjList[cur][i])) {
                            bs.set(adjList[cur][i]);
                            q.push(adjList[cur][i]);
                        } 
                    }
                }
                for (int i = 0; i < v; i++) {
                    if (!bs.test(i)) {
                        cnt++;
                        ans.PB(i);
                    }
                }
            } else {
                for (int i = 0; i < v; i++) {
                    cnt++;
                    ans.PB(i);
                }
            }
            fprintf(stdout, "%d", cnt);
            for (int i = 0; i < cnt; i++) {
                fprintf(stdout, " %d", ans[i] + 1);
            }
            fprintf(stdout, "\n");
        }
    }
	return 0;
}
