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
	int p, ctr, n, m;
    cin >> p;
    while (p--) {

        cin >> ctr >> n >> m;
        vector<vector<char> > orig(n, vector<char>(m, ' '));
        string line;
        getline(cin, line);
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            for (int j = 0; j < m; j++) {
                orig[i][j] = line[j];
            }
        }
        int ansT = INT_MIN;
        int ansW = INT_MIN;
        int ansB = INT_MIN;
        for (int j = 0; j < m; j++) {
            vector<vector<char> > grid = orig;
            int whites = 0;
            int blacks = 0;
            for (int i = 0; i < n; i++) {
                grid[i][j] = '1';
            }
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < m; k++) {
                    char ch = grid[i][k];
                    if (ch != '2') {
                        grid[i][k] = '2';
                        if (ch == '1') blacks++;
                        else whites++;
                        queue<ii> q;
                        q.push(ii(i, k));
                        while (!q.empty()) {
                            int curR = q.front().first;
                            int curC = q.front().second;
                            q.pop();
                            for (int l = 0; l < 4; l++) {
                                int nextR = curR + fx[l][0];
                                int nextC = curC + fx[l][1];
                                if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m) {
                                    if (grid[nextR][nextC] == ch) {
                                        grid[nextR][nextC] = '2';
                                        q.push(ii(nextR, nextC));
                                    }
                                }
                            }
                        }
                    }
                }
            }
            int total = whites + blacks;
            if (total > ansT) {
                ansT = total;
                ansW = whites;
                ansB = blacks;
            } else if (total == ansT) {
                if (whites > ansW) {
                    ansW = whites;
                    ansB = blacks;
                }
            }
        }
        cout << ctr << ' ' << ansW << ' ' << ansB << '\n';
    }
	
	return 0;
}