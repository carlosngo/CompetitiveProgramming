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

const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const int UNVISITED = -1;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m;
    SCD(n); SCD(m);
    getchar();
    int grid[n][m];
    int ans[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            SCC(ch);
            grid[i][j] = ch - '0';
            ans[i][j] = -1;   
        }
        getchar();
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%d", grid[i][j]);
    //     }
    //     printf("\n");
    // }
    ans[0][0] = 0;
    queue<ii> q;
    q.push(ii(0, 0));
    while (!q.empty()) {
        int curR = q.front().first;
        int curC = q.front().second;
        int depth = ans[curR][curC];
        q.pop();
        int w = grid[curR][curC];
        int fx[4][2] = {{0,w}, {0,-w}, {w,0}, {-w,0}};
        for (int i = 0; i < 4; i++) {
            int nextR = curR + fx[i][0];
            int nextC = curC + fx[i][1];
            if (LIN(nextR, 0, n) && LIN(nextC, 0, m) && ans[nextR][nextC] == -1) {
                ans[nextR][nextC] = depth + 1;
                q.push(ii(nextR, nextC));
            }
        }   
    }
    fprintf(stdout, "%d", ans[n - 1][m - 1]);
	return 0;
}