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
	int t;
    cin >> t;
    string line;
    getline(cin, line);

    while (t--) {
        char grid[30][80];
        memset(grid, 0, sizeof grid);
        int i = 0;
        int r, c;
        int startR, startC;
        string separator;
        while (getline(cin, line), line[0] != '_') {
            for (int j = 0; j < line.length(); j++) {
                grid[i][j] = line[j];
                if (grid[i][j] == '*') {
                    startR = i;
                    startC = j;
                }
            }
            i++;
        }
        r = i;
        queue<ii> q;
        q.push(ii(startR, startC));
        grid[startR][startC] = '#';
        while (!q.empty()) {
            int curR = q.front().first;
            int curC = q.front().second;
            // printf("%d, %d = %c\n", curR, curC, grid[curR][curC]);
            q.pop();
            for (int j = 0; j < 8; j++) {
                int nextR = curR + fxx[j][0];
                int nextC = curC + fxx[j][1];
                if (nextR >= 0 && nextR < 30 && nextC >= 0 && nextC < 80) {
                    if (grid[nextR][nextC] == ' ') {
                        grid[nextR][nextC] = '#';
                        q.push(ii(nextR, nextC));
                    }
                }

            }
        }
        for (i = 0; i < r; i++) {
            for (int j = 0; j < 80; j++) {
                if (grid[i][j] != 0) {
                    cout << grid[i][j];
                }
            }
            cout << "\n";
        }
        cout << line << "\n";
    }

	return 0;
}