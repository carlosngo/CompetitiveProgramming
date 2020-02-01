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
const int cx[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int UNVISITED = -1;

vector<vector<ll>> memo;
vector<vector<char>> grid;
int n;
ll MOD = 2147483647;

ll dp(int r, int c) {
    if (r == n || c == n) return 0;
    if (grid[r][c] == '#') return 0;
    if (r == n - 1 && c == n - 1) return 1;
    if (memo[r][c] != UNVISITED) return memo[r][c];
    return memo[r][c] = (dp(r + 1, c) + dp(r, c + 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    cin >> n;
    memo.assign(n, vector<ll>(n, UNVISITED));
    grid.assign(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    ll ans = dp(0, 0);
    if (ans == 0) {
        queue<ii> q;
        q.push(ii(0, 0));
        vector<vector<bool> > visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        bool reachable = false;
        while (!q.empty()) {
            int curR = q.front().first;
            int curC = q.front().second;
            if (curR == n - 1 && curC == n - 1) reachable = true;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nextR = curR + fx[i][0];
                int nextC = curC + fx[i][1];
                if (LIN(nextR, 0, n) && LIN(nextC, 0, n) && grid[nextR][nextC] != '#' && !visited[nextR][nextC]) {
                    visited[nextR][nextC] = true;
                    q.push(ii(nextR, nextC));
                }
            }
        }
        if (reachable) cout << "THE GAME IS A LIE";
        else cout << "INCONCEIVABLE";
    } else cout << ans;

	return 0;
}