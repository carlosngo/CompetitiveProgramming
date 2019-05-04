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
    string line;
    cin >> t;
    getline(cin, line);
    getline(cin, line);
    int ctr = 0;
    while(t--) {
        if (ctr > 0) fprintf(stdout, "\n");
        int n;
        
        getline(cin, line);
        n = line[0] - 'A' + 1;
        vi values(n, -1);
        vvi adjList(n, vi());
        while (getline(cin, line) && line.size() > 0) {
            int from = line[0] - 'A';
            int to = line[1] - 'A';
            adjList[from].PB(to);
            adjList[to].PB(from);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (values[i] == -1) {
                values[i] = ans;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int cur = q.front();
                    // printf("Cur = %d, ans = %d\n", cur, ans);
                    q.pop();
                    for (int j = 0; j < adjList[cur].size(); j++) {
                        int next = adjList[cur][j];
                        if (values[next] == -1) {
                            values[next] = ans;
                            q.push(next);
                        }
                    }
                }
                ans++;
            }
        }
        fprintf(stdout, "%d\n", ans);
        ctr++;
    }
	return 0;
}