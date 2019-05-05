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
	freopen("out.txt", "wt", stdout);
	freopen("in.txt", "r", stdin);
	int s;
    while (SCD(s), s != 0) {
        int grid[s][s];
        getchar();
        int size = s;
        memset(grid, 0, sizeof grid);
        for (int i = 0; i < s - 1; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            int r, c;
            while (ss >> r) {
                ss >> c;
                r--; c--;
                grid[r][c] = i + 1;
            }
        }
        // for (int i = 0; i < s; i++) {
        //     for (int j = 0; j < s; j++) {
        //         fprintf(stdout, "%d", grid[i][j]);
        //     }
        //     fprintf(stdout, "\n");
        // }
        bool right = true;
        bool occ[100];
        memset(occ, false, sizeof occ);
        for (int i = 0; i < s && right; i++) {
            for (int j = 0; j < s && right; j++) {
                int num = grid[i][j];
                if (num != -1) {
                    if (occ[num]) right = false;
                    else {
                        int count = 1;
                        occ[num] = true;
                        grid[i][j] = -1;
                        queue<ii> q;
                        q.push(ii(i, j));
                        while (!q.empty()) {
                            int curR = q.front().first;
                            int curC = q.front().second;
                            q.pop();
                            for (int k = 0; k < 4; k++) {
                                int nextR = curR + fx[k][0];
                                int nextC = curC + fx[k][1];
                                if (nextR >= 0 && nextR < s && nextC >= 0 && nextC < s) {
                                    if (grid[nextR][nextC] == num) {
                                        count++;
                                        grid[nextR][nextC] = -1;
                                        q.push(ii(nextR, nextC));
                                    }
                                }
                            }
                        }
                        if (count != s) right = false;
                    }
                }
            }
        }
        fprintf(stdout, "%s\n", right ? "good" : "wrong");
    }
	return 0;
}