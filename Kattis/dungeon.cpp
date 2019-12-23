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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int l, r, c;
    while (cin >> l >> r >> c, !(r == 0 && l == 0 && c == 0)) {
        // cout << l << ' ' << r << ' ' << c << '\n';
        char dummy;
        // cin >> dummy;
        int grid[l][r][c];
        iii src, dest;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    char ch;
                    cin >> ch;
                    if (ch == '#') grid[i][j][k] = -1;
                    else grid[i][j][k] = 0;
                    if (ch == 'S') src = iii(i, ii(j, k));
                    else if (ch == 'E') dest = iii(i, ii(j, k));
                }
            }
        }

        int ans = -1;
        queue<iii> q;
        q.push(src);
        while (!q.empty()) {
            int curH = q.front().first;
            int curR = q.front().second.first;
            int curC = q.front().second.second;
            q.pop();
            int curT = grid[curH][curR][curC];
            if (curH == dest.first && curR == dest.second.first && curC == dest.second.second) {
                ans = curT;
                break;
            }
            for (int i = 0; i < 6; i++) {
                int nextH = curH + cx[i][0];
                int nextR = curR + cx[i][1];
                int nextC = curC + cx[i][2];
                if (LIN(nextH, 0, l) && LIN(nextR, 0, r) && LIN(nextC, 0, c) && grid[nextH][nextR][nextC] == 0 && grid[nextH][nextR][nextC] != -1) {
                    grid[nextH][nextR][nextC] = curT + 1;
                    q.push(iii(nextH, ii(nextR, nextC)));
                }
            }
        }
        if (ans != -1) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
        
    }

	
	return 0;
}