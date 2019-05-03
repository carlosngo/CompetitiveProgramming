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

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

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
	// freopen("out.txt", "wt", stdout);
    int t;
    SCD(t);
    int ctr = 0;
    while (t--) {
        if (ctr > 0) fprintf(stdout, "\n");
        int r, c;
        SCD(r); SCD(c);
        // cout << r << c;
        char grid[r][c];
        getchar();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                SCC(grid[i][j]);
                // fprintf(stdout, "%c", grid[i][j]);
            }
            // fprintf(stdout, "\n");
            getchar();
        }
        // fprintf(stdout, "DOne processing.\n");
        int curR, curC;
        int curO = NORTH;
        SCD(curR); SCD(curC);
        // cout << curR << curC;
        curR--; curC--;
        getchar();
        char cmd;
        while (SCC(cmd), cmd != 'Q') {
            
            if (cmd == 'R') {
                curO = (curO + 1) % 4;
            } else if (cmd == 'L') {
                curO--;
                if (curO < 0) curO = 3;
            } else if (cmd == 'F') {
                if (curO == NORTH) {
                    if (curR - 1 >= 0 && curR - 1 < r && grid[curR - 1][curC] == ' ') curR--;
                } else if (curO == EAST) {
                    if (curC + 1 >= 0 && curC + 1 < c && grid[curR][curC + 1] == ' ') curC++;
                    // fprintf(stdout, "Is (%d, %d) a whitespace? %s\n", curR, curC + 1, grid[curR][curC + 1] == ' ' ? "YES" : "NO");
                } else if (curO == SOUTH) {
                    if (curR + 1 >= 0 && curR + 1 < r && grid[curR + 1][curC] == ' ') curR++;
                } else {
                    if (curC - 1 >= 0 && curC - 1 < c && grid[curR][curC - 1] == ' ') curC--;
                }
            }
            // fprintf(stdout, "Robot R = %d, C = %d, O = %d\n", curR, curC, curO);
        }
        char finalO;
        if (curO == NORTH) {
            finalO = 'N';
        } else if (curO == EAST) {
            finalO = 'E';
        } else if (curO == SOUTH) {
            finalO = 'S';
        } else {
            finalO = 'W';
        }
        fprintf(stdout, "%d %d %c\n", curR + 1, curC + 1, finalO);
        ctr++;
    }
	return 0;
}