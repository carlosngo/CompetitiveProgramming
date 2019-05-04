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
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,-1}};
const int BLACK = 0;
const int WHITE = 1;

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	freopen("out.txt", "wt", stdout);
	int n;
    int ctr = 1;
    while(SCD(n), n != 0) {
        char grid[n][n];
        getchar();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                SCC(grid[i][j]);
            }
            getchar();
        }
        int winner = -1;
        for (int i = 0; i < n; i++) {
            int j = 0;
            char ch = grid[i][j];
            if (ch == 'w') {
                grid[i][j] = 'd';
                queue<ii> q;
                q.push(ii(i, j));
                while (!q.empty() && winner == -1) {
                    int curR = q.front().first;
                    int curC = q.front().second;
                    // fprintf(stdout, "curR = %d, curC = %d\n", curR, curC);
                    q.pop();
                    
                    for (int k = 0; k < 6; k++) {
                        int nextR = curR + fxx[k][0];
                        int nextC = curC + fxx[k][1];
                        if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n) {
                            if (grid[nextR][nextC] == 'w') {
                                if (nextC == n - 1) winner = WHITE;
                                grid[nextR][nextC] = 'd';
                                q.push(ii(nextR, nextC));
                            }
                        }
                    }
                }
            } 
        }
        for (int j = 0; j < n; j++) {
            int i = 0;
            char ch = grid[i][j];
            if (ch == 'b') {
                queue<ii> q;
                grid[i][j] = 'd';
                q.push(ii(i, j));
                while (!q.empty() && winner == -1) {
                    int curR = q.front().first;
                    int curC = q.front().second;
                    // fprintf(stdout, "curR = %d, curC = %d\n", curR, curC);
                    q.pop();
                    for (int k = 0; k < 6; k++) {
                        int nextR = curR + fxx[k][0];
                        int nextC = curC + fxx[k][1];
                        if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n) {
                            if (grid[nextR][nextC] == 'b'){
                                if (nextR == n - 1) winner = BLACK;
                                grid[nextR][nextC] = 'd';
                                q.push(ii(nextR, nextC));
                            } 
                        }
                    }
                }
            } 
        }
        fprintf(stdout, "%d %c\n", ctr, winner == WHITE ? 'W' : 'B');
        ctr++;
    }

	return 0;
}