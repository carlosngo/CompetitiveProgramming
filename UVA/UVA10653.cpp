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
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int r, c;
    while (fscanf(stdin, "%d%d", &r, &c), r != 0 || c != 0) {
        short int grid[r][c];
        memset(grid, UNVISITED, sizeof grid);
        int rows;
        SCD(rows);
        for (int i = 0; i < rows; i++) {
            int row, bombs;
            SCD(row); SCD(bombs);
            for (int j = 0; j < bombs; j++) {
                int col;
                SCD(col);
                grid[row][col] = -2;
            }
        }
        int srcR, srcC, destR, destC;
        SCD(srcR); SCD(srcC); SCD(destR); SCD(destC);
        grid[srcR][srcC] = 0;
        queue<ii> q;
        q.push(ii(srcR, srcC));
        bool found = false;
        while (!q.empty() && !found) {
            int curR = q.front().first;
            int curC = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nextR = curR + fx[i][0];
                int nextC = curC + fx[i][1];
                if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c) {
                    if (grid[nextR][nextC] == -2) continue;
                    if (grid[nextR][nextC] == UNVISITED) {
                        grid[nextR][nextC] = grid[curR][curC] + 1;
                        q.push(ii(nextR, nextC));
                    }
                    if (nextR == destR && nextC == destC) {
                        found = true;
                        break;
                    }
                }
            }
        }
        fprintf(stdout, "%d\n", grid[destR][destC]);
    }
	return 0;
}