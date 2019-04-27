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
	// freopen("out.txt", "wt", stdout);
	int n, m;
    SCD(n); SCD(m);
    char grid[n][m];
    int ans[n][m];
    memset(ans, 0, sizeof ans);
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            SCC(grid[i][j]);
        }
        getchar();
    }
    bool ring = true;
    int k;
    for (k = 1; k <= 100 && ring; k++) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'T') {
                    int minVal = INT_MAX;
                    for (int l = 0; l < 4; l++) {
                        int newR = i + fx[l][0];
                        int newC = j + fx[l][1];
                        if (newR >= 0 && newR < n && newC >= 0 && newC < m) {
                            minVal = min(minVal, ans[newR][newC]);    
                        } else {
                            minVal = min(minVal, 0);
                        }
                    }
                    if (minVal == k - 1) {
                        found = true;
                        ans[i][j] = k;
                    }
                }
            }
        }
        if (!found) ring = false;
    }
    k--;
    if (k < 10) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j]) fprintf(stdout, ".%d", ans[i][j]);
                else fprintf(stdout, "..");
            } 
            fprintf(stdout, "\n");
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] == 0) fprintf(stdout, "...");
                else if (ans[i][j] < 10) fprintf(stdout, "..%d", ans[i][j]);
                else fprintf(stdout, ".%d", ans[i][j]);
            }
            fprintf(stdout, "\n");
        }
    }
    
	return 0;  
}