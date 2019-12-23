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
const int UNVISITED = -1;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    string line;
    while (getline(cin, line), line != "-1") {
        int r, c, t, l, w;
        stringstream ss(line);

        ss >> c >> r >> t >> l >> w;
        // cout << c << ' ' << r << ' ' << t << ' ' << l << ' ' << w << '\n';
        vvi grid(r, vi(c, 0));
        queue<ii> q;
        int ans = 0;
        FOR (i, 0, l, 1) {
            int row, col;
            cin >> col >> row;
            col--; row--;
            grid[row][col] = 1;
            q.push(ii(row, col));
        } 

        FOR (i, 0, w, 1) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;;
            grid[y1][x1] = -1;
            while (y1 != y2 || x1 != x2) {
                if (y1 > y2) y1--;
                else if (y1 < y2) y1++;
                if (x1 > x2) x1--;
                else if (x1 < x2) x1++;
                grid[y1][x1] = -1;
            }
        }
        while (!q.empty()) {
            ans++;
            int curR = q.front().first;
            int curC = q.front().second;
            int curT = grid[curR][curC];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nextR = curR + fx[i][0];
                int nextC = curC + fx[i][1];
                int nextT = curT + 1;
                if (nextT <= t && LIN(nextR, 0, r) && LIN(nextC, 0, c) && grid[nextR][nextC] == 0) {
                    grid[nextR][nextC] = nextT;
                    q.push(ii(nextR, nextC));
                }
            }
        }
        // FOR (i, 0, r, 1) {
        //     FOR (j, 0, c, 1) {
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        getline(cin, line);
        cout << ans << '\n';
    }
	
	return 0;
}