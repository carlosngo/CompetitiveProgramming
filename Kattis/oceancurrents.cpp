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
const int fxx[8][2] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
const int cx[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int UNVISITED = -1;

int main() {
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    int r, c;
    cin >> r >> c;
    int grid[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            grid[i][j] = ch - '0';
        }
    }
    int n;
    cin >> n;
    while (n--) {
        vvi ans(r, vi(c, INT_MAX));
        int srcR, srcC, destR, destC;
        cin >> srcR >> srcC >> destR >> destC;
        srcR--; srcC--; destR--; destC--;
        ans[srcR][srcC] = 0;
        deque<ii> q;
        q.push_back(ii(srcR, srcC));
        while (!q.empty()) {
            int curR = q.front().first; 
            int curC = q.front().second;
            q.pop_front();
            int curD = ans[curR][curC];
            // cout << "Processing curR = " << curR << " curC = " << curC << " with depth = " << curD << '\n';
            for (int i = 0; i < 8; i++) {
                int nextR = curR + fxx[i][0];
                int nextC = curC + fxx[i][1];
                int nextD = curD + (i == grid[curR][curC] ? 0 : 1);
                if (LIN(nextR, 0, r) && LIN(nextC, 0, c) && nextD < ans[nextR][nextC]) {
                    // cout << "i = " << i << '\n';
                    // cout << "grid[curR][curC] = " << grid[curR][curC] << '\n';
                    if (i == grid[curR][curC]) q.push_front(ii(nextR, nextC));
                    else q.push_back(ii(nextR, nextC));
                    ans[nextR][nextC] = nextD;
                }
            }

        }
        cout << ans[destR][destC] << '\n';
    }
	return 0;
}