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

bool compare(ii a, ii b) {
    if (a.first > b.first) return true;
    else if (a.first == b.first) return a.second < b.second;
    else return false;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	freopen("out.txt", "wt", stdout);
	freopen("in.txt", "r", stdin);
    int r, c;
    int ctr = 1;
    while (fscanf(stdin, "%d%d", &r, &c), r != 0 || c != 0) {
        char grid[r][c];
        getchar();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                SCC(grid[i][j]);
            }
            getchar();
        }
        vii ans;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch = grid[i][j];
                if (ch != '.') {
                    int count = 1;
                    grid[i][j] = '.';
                    queue<ii> q;
                    q.push(ii(i, j));
                    while (!q.empty()) {
                        int curR = q.front().first;
                        int curC = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nextR = curR + fx[k][0];
                            int nextC = curC + fx[k][1];
                            if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c) {
                                if (grid[nextR][nextC] == ch) {
                                    grid[nextR][nextC] = '.';
                                    count++;
                                    q.push(ii(nextR, nextC));
                                }
                            }
                        }
                    }
                    ans.PB(ii(count, ch));
                }
            }
        }
        sort(ans.begin(), ans.end(), compare);
        fprintf(stdout, "Problem %d:\n", ctr);
        for (int i = 0; i < ans.size(); i++) {
            fprintf(stdout, "%c %d\n", ans[i].second, ans[i].first);
        }
        ctr++;
    }
	return 0;
}