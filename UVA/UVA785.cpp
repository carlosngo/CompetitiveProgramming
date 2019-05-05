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
	string line;
    char grid[32][80];
    memset(grid, 0, sizeof grid);
    map<char, int> occ;
    int r = 0;
    char contour;

    while (getline(cin, line)) {
        if (line[0] == '_') {
            // process
            int maxOcc = INT_MIN;
            for (map<char, int>::iterator itr = occ.begin(); itr != occ.end(); itr++) {
                if (itr->second > maxOcc) {
                    maxOcc = itr->second;
                    contour = itr->first;
                }
            }
            for (int i = 0; i < 32; i++) {
                for (int j = 0; j < 80; j++) {
                    char ch = grid[i][j];
                    if (ch != ' ' && ch != 0 && ch != contour) {
                        queue<ii> q;
                        q.push(ii(i, j));
                        while (!q.empty()) {
                            int curR = q.front().first;
                            int curC = q.front().second;
                            q.pop();
                            for (int k = 0; k < 4; k++) {
                                int nextR = curR + fx[k][0];
                                int nextC = curC + fx[k][1];
                                if (nextR >= 0 && nextR < 32 && nextC >= 0 && nextC < 80) {
                                    if (grid[nextR][nextC] == ' ') {
                                        grid[nextR][nextC] = ch;
                                        q.push(ii(nextR, nextC));
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < 80; j++) {
                    if (grid[i][j] != 0) {
                        fprintf(stdout, "%c", grid[i][j]);
                    }
                }
                fprintf(stdout, "\n");
            }
            fprintf(stdout, "%s\n", line.c_str());

            memset(grid, 0, sizeof grid);
            occ = map<char, int>();
            r = 0;
        } else {
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != ' ' && line[i] != 0) {
                    occ[line[i]]++;
                }
                grid[r][i] = line[i];
            }
            r++;
        }
    }
	return 0;
}