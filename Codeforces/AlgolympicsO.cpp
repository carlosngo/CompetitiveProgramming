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
const int rx[3][2] = {{0,1}, {0,-1}, {1,0}};
const int sx[3][2] = {{0,1}, {0,-1}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const int cx[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int UNVISITED = -1;

int main() {
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    WHILEZ {
        int r, c;
        cin >> r >> c;
        char grid[r][c];
        int still[r][c];
        ii parent[r][c];
        int ans[r][c];
        int branch[r][c];
        getchar();
        queue<ii> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = UNVISITED;
                still[i][j] = UNVISITED;
                branch[i][j] = UNVISITED;
                SCC(grid[i][j]);
                if (grid[i][j] == 'W') {
                    q.push(ii(i, j));
                    parent[i][j] = ii(-1, -1);
                    ans[i][j] = 0;
                    branch[i][j] = 0;
                }
            }
            getchar();
        }
        while (!q.empty()) {

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (ans[i][j] == UNVISITED) fprintf(stdout, "%c", grid[i][j]);
                    else fprintf(stdout, "%d", ans[i][j] % 10);
                }
                fprintf(stdout, "\n");
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (branch[i][j] == UNVISITED) fprintf(stdout, ".");
                    else fprintf(stdout, "%d", branch[i][j] % 10);
                }
                fprintf(stdout, "\n");
            }
            int curR = q.front().first;
            int curC = q.front().second;
            int curT = ans[curR][curC];
            cout << "processing r = " << curR << ", c = " << curC << ", t = " << curT << '\n';
            q.pop();
            int lr = curR, lc = curC - 1;
            int rr = curR, rc = curC + 1;
            int ur = curR - 1, uc = curC;
            int dr = curR + 1, dc = curC;
            bool hasMove = false;
            bool isStill = true;
            if (dr < r) {
                if (ans[dr][dc] == UNVISITED && grid[dr][dc] == '.' && grid[dr][dc] != '#') {
                    ans[dr][dc] = curT + 1;
                    parent[dr][dc] = ii(curR, curC);
                    branch[dr][dc] = branch[curR][curC];
                    q.push(ii(dr, dc));
                    hasMove = true;
                }
                if (grid[dr][dc] == '#' || still[curR][curC] != UNVISITED) {
                    if (lc >= 0) {
                        if (ans[lr][lc] == UNVISITED && grid[lr][lc] != '#') {
                            ans[lr][lc] = curT + 1;  
                            branch[lr][lc] = branch[curR][curC];
                            parent[lr][lc] = ii(curR, curC);
                            if (parent[curR][curC].first == curR - 1) branch[lr][lc]++;
                            q.push(ii(lr, lc));
                            hasMove = true;
                        }
                    } else isStill = false;

                    if (rc < c) {
                        if (ans[rr][rc] == UNVISITED && grid[rr][rc] != '#') {
                            ans[rr][rc] = curT + 1; 
                            branch[rr][rc] = branch[curR][curC];
                            parent[rr][rc] = ii(curR, curC);
                            if (parent[curR][curC].first == curR - 1) branch[rr][rc]++;
                            q.push(ii(rr, rc));
                            hasMove = true;
                        }
                    } else isStill = false;   
                }
            } else isStill = false;

            if (ur >= 0) {
                if (ans[ur][uc] == UNVISITED && still[curR][curC] != UNVISITED && grid[ur][uc] != '#') {
                    ans[ur][uc] = still[curR][curC] + 1;
                    branch[ur][uc] = branch[curR][curC];
                    parent[ur][uc] = ii(curR, curC);
                    q.push(ii(ur, uc));
                    hasMove = true;
                }
            }
            
            if (still[curR][curC] == UNVISITED && !hasMove && isStill) {
                cout << "out of moves and isStill at t = " << curT << "\n";
                int curBranch = branch[curR][curC];
                int pr = curR, pc = curC;
                
                while (branch[pr][pc] == curBranch) {
                    if (still[pr][pc] != UNVISITED) break;
                    still[pr][pc] = curT;
                    q.push(ii(pr, pc));
                    int tempR = parent[pr][pc].first, tempC = parent[pr][pc].second;
                    pr = tempR; pc = tempC;
                    
                }
                
            }
        }   
    }
	
	return 0;
}