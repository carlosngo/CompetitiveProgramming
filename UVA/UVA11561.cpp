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

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	freopen("out.txt", "wt", stdout);
	freopen("in.txt", "r", stdin);
	int r, c;
    while (fscanf(stdin, "%d %d", &c, &r) == 2) {
        char grid[r][c];
        getchar();
        // fprintf(stdout, "%d %d\n", r, c);
        int startR, startC;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                SCC(grid[i][j]);
                // fprintf(stdout, "%c", grid[i][j]);
                if (grid[i][j] == 'P') {
                    startR = i;
                    startC = j;
                }
            }
            // fprintf(stdout, "\n");
            getchar();
        }
        queue<ii> q;
        q.push(ii(startR, startC));
        int ans = 0;
        while (!q.empty()) {
            int curR = q.front().first;
            int curC = q.front().second;
            q.pop();
            vii nextBatch;
            bool isSafe = true;
            for (int i = 0; i < 4; i++) {
                int nextR = curR + fx[i][0];
                int nextC = curC + fx[i][1];
                if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c) {
                    char ch = grid[nextR][nextC];
                    if (ch == '.') {
                        nextBatch.push_back(ii(nextR, nextC));
                    } else if (ch == 'G') {
                        nextBatch.push_back(ii(nextR, nextC));
                    } else if (ch == 'T') isSafe = false;
                }
            }
            if (isSafe) {
                for (int i = 0; i < nextBatch.size(); i++) {
                    int row = nextBatch[i].first;
                    int col = nextBatch[i].second;
                    char ch = grid[row][col];
                    if (ch == '.') {
                        grid[row][col] = 'P';
                        q.push(ii(row, col));
                    } else if (ch == 'G') {
                        ans++;
                        grid[row][col] = 'P';
                        q.push(ii(row, col));
                    }
                }
            }
        }
        fprintf(stdout, "%d\n", ans);
    }
	return 0;
}