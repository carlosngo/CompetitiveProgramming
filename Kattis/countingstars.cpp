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
	int r, c;
    int t  = 1;
    while (cin>> r >> c) {
        char grid[r][c];
        string line;
        for (int i = 0; i < r; i++) {
            cin >> line;
            for (int j =0 ; j < c; j++) {
                grid[i][j] = line[j];
            }
        }
        bitset<10001> visited;
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char cur = grid[i][j];
                if (cur == '-') {
                    ans++;
                    grid[i][j] = '#';
                    queue<ii> q; 
                    q.push(ii(i, j));
                    while (!q.empty()) {
                        int curR = q.front().first;
                        int curC = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nextR = curR + fx[k][0];
                            int nextC = curC + fx[k][1];
                            if (LIN(nextR, 0, r) && LIN(nextC, 0, c)) {
                                if (grid[nextR][nextC] == '-') {
                                    grid[nextR][nextC] = '#';
                                    q.push(ii(nextR, nextC));
                                }
                                
                            }
                        }
                    }
                }
                
            }
        }
        cout << "Case " << t << ": " << ans << '\n';
        t++; 
    }
    
    
	return 0;
}