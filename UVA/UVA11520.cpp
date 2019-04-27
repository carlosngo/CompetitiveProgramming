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
        int n;
        fprintf(stdout, "Case %d:\n", ctr);
        // fprintf(pFile, "Case %d:\n", ctr);
        ctr++;
        SCD(n);
        getchar();
        char grid[n][n];
        FOR (i, 0, n, 1) {
            FOR (j, 0, n, 1) {
                SCC(grid[i][j]);
            }
            getchar();
        }
        FOR (i, 0, n, 1) {
            FOR (j, 0, n, 1) {
                bool found = false;
                if (grid[i][j] != '.') {
                    fprintf(stdout, "%c", grid[i][j]);
                    // fprintf(pFile, "%c", grid[i][j]);
                    continue;
                }
                for (int k = 0; k < 26 && !found; k++) {
                    char ch = k + 'A';
                    bool valid = true;
                    for (int l = 0; l < 4; l++) {
                        int newR = i + fx[l][0];
                        int newC = j + fx[l][1];
                        if (newR >= 0 && newR < n && newC >= 0 && newC < n) {
                            // printf("At i = %d j = %d, checking row %d and col %d\n", i, j, newR, newC);
                            if (grid[newR][newC] == ch) valid = false;
                        }
                    }
                    if (valid) {
                        grid[i][j] = ch;
                        fprintf(stdout, "%c", ch);
                        // fprintf(pFile, "%c", ch);
                        found = true;
                    }
                }
            }
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
        
    
    }
	fclose(pFile);
	return 0;
}