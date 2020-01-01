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

// class BigArray {
//     int grid[2001][2001];
// }

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    int p;
    while (cin >> p, p != 0) {
        vii firstM(p);
        int r = INT_MIN, c = INT_MIN;
        queue<ii> q;
        // memset(grid, -1, sizeof grid);
        FOR (i, 0, p, 1) {
            int x, y;
            cin >> x >> y;
            r = max(r, x);
            c = max(c, y);
            firstM[i] = ii(x, y);
            q.push(firstM[i]);
        }
        cin >> p;
        vii secondM(p);
        FOR (i, 0, p, 1) {
            int x, y;
            cin >> x >> y;
            r = max(r, x);
            c = max(c, y);
            secondM[i] = ii(x, y);
        }
        r++; c++;
        vvi grid(r, vi(c, UNVISITED));
        FOR (i, 0, firstM.size(), 1) {
            grid[firstM[i].first][firstM[i].second] = 0;
        }
        while (!q.empty()) {
            int curR = q.front().first;
            int curC = q.front().second;
            q.pop();
            int curD = grid[curR][curC];
            for (int i = 0; i < 4; i++) {
                int nextR = curR + fx[i][0];
                int nextC = curC + fx[i][1];
                int nextD = curD + 1;
                if (LIN(nextR, 0, r) && LIN(nextC, 0, c) && grid[nextR][nextC] == UNVISITED) {
                    q.push(ii(nextR, nextC));
                    grid[nextR][nextC] = nextD;
                }
            }
        }
        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        int ans = INT_MAX;
        for (int i = 0; i < secondM.size(); i++) ans = min(ans, grid[secondM[i].first][secondM[i].second]);
        cout << ans << '\n';
    }    
	return 0;
}