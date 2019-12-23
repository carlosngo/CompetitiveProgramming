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
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    int r, c;
    cin >> r >> c;
    // cin >> c >> r;
    int grid[r][c];
    int srcR, srcC;
    queue<ii> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') grid[i][j] = -2;
            else grid[i][j] = INF;
            if (ch == 'J') {
                srcR = i;
                srcC = j;
            } else if (ch == 'F') {
                grid[i][j] = 0;
                q.push(ii(i, j));
            }
        }
    }
    while (!q.empty()) {
        int curR = q.front().first;
        int curC = q.front().second;
        int d = grid[curR][curC];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextR = curR + fx[i][0];
            int nextC = curC + fx[i][1];
            if (LIN(nextR, 0, r) && LIN(nextC, 0, c) && grid[nextR][nextC] == INF && grid[nextR][nextC] != -2) {
                grid[nextR][nextC] = d + 1;
                q.push(ii(nextR, nextC));
            }
        }
    }
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    q = queue<ii>();
    q.push(ii(srcR, srcC));
    vvi timeGrid(r, vi(c, UNVISITED));
    timeGrid[srcR][srcC]= 0;
    int ans = -1;
    while (!q.empty()) {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        int curT = timeGrid[curR][curC];
        if (curR == 0 || curR == r - 1 || curC == 0 || curC == c - 1) {
            ans = curT;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nextR = curR + fx[i][0];
            int nextC = curC + fx[i][1];
            if (LIN(nextR, 0, r) && LIN(nextC, 0, c) && 
                    timeGrid[nextR][nextC] == -1 && grid[nextR][nextC] != -2 && 
                        grid[nextR][nextC] > curT + 1) {
                timeGrid[nextR][nextC] = curT + 1;
                q.push(ii(nextR, nextC));
            }
        }
    }
    if (ans == -1) cout << "IMPOSSIBLE\n";
    else cout << (ans + 1) << '\n';
    
    
	return 0;
}