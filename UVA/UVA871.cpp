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
	// ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	int t;
    SCD(t);
    string line;
    getchar();
    getchar();
    int ctr = 0;
    while (t--) {
        if (ctr) fprintf(stdout, "\n");
        char grid[25][25];
        int r = 0;
        int c;
        while (getline(cin, line)) {
            // fprintf(stdout, "%s\n", line.c_str());
            if (line == "") break;
            for (int i = 0; i < line.length(); i++) {
                grid[r][i] = line[i];
            }
            c = line.length();
            r++;
        }
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch = grid[i][j];
                // fprintf(stdout, "%c", ch);
                if (ch == '1') {
                    grid[i][j] = '0';
                    int count = 1;
                    queue<ii> q;
                    q.push(ii(i, j));
                    while (!q.empty()) {
                        int curR = q.front().first;
                        int curC = q.front().second;
                        q.pop();
                        for (int k = 0; k < 8; k++) {
                            int nextR = curR + fxx[k][0];
                            int nextC = curC + fxx[k][1];
                            if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c) {
                                if (grid[nextR][nextC] == '1') {
                                    count++;
                                    grid[nextR][nextC] = '0';
                                    q.push(ii(nextR, nextC));
                                }
                            }
                        }
                    }
                    ans = max(ans, count);
                }
            }
            // fprintf(stdout, "\n");
        }
        fprintf(stdout, "%d\n", ans);
        ctr++;
    }
	return 0;
}