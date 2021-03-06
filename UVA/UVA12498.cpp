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
	FILE *pFile = fopen("out.txt","w");
    int t;
    SCD(t);
    int ctr = 1;
    while (t--) {
        int r, c;
        SCD(r); SCD(c);
        getchar();
        char grid[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                SCC(grid[i][j]);
            }
            getchar();
        }
        int ans = INT_MAX;
        for (int col = 0; col < c; col++) {
            int total = 0;
            bool valid = true;
            for (int row = 0; row < r && valid; row++) {
                if (grid[row][col] == '1') {
                    int lPushes = 1;
                    int rPushes = 1;
                    bool lVacant = false;
                    bool rVacant = false;
                    // CHECK LEFT
                    for (int lCol = col - 1; lCol >= 0; lCol--) {
                        if (grid[row][lCol] == '0') {
                            lVacant = true;
                            break;
                        } else {
                            lPushes++;
                        }
                    }
                    // CHECK RIGHT
                    for (int rCol = col + 1; rCol < c; rCol++) {
                        if (grid[row][rCol] == '0') {
                            rVacant = true;
                            break;
                        } else {
                            rPushes++;
                        }
                    }
                    if (lVacant && rVacant) total += min(lPushes, rPushes);
                    else if (lVacant) total += lPushes;
                    else if (rVacant) total += rPushes;
                    else valid = false;
                } 
            }
            if (valid) ans = min(ans, total);
        }
        if (ans == INT_MAX) {
            fprintf(stdout, "Case %d: -1\n", ctr);
            fprintf(pFile, "Case %d: -1\n", ctr);
        } else {
            fprintf(stdout, "Case %d: %d\n", ctr, ans);
            fprintf(pFile, "Case %d: %d\n", ctr, ans);
        }
        ctr++;
    }
	fclose(pFile);
	return 0;
}