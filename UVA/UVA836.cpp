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
    int cases;
    SCD(cases);
    string line;
    int ctr = 0;
    while (cases--) {
        if (ctr > 0) {
            fprintf(stdout, "\n");
            fprintf(pFile, "\n");
        }
        
        cin >> line;
        int n = line.length();
        vector<string> matrix;
        matrix.PB(line);
        int sums[n][n];
        FOR (i, 1, n, 1) {
            cin >> line;
            matrix.PB(line);
        }
        FOR (i, 0, n, 1) {
            FOR (j, 0, n, 1) {
                sums[i][j] = 0;
                // printf("%c ", matrix[i][j]);
            }
            // printf("\n");
        }
        FOR (i, 0, n, 1) {
            FOR (j, 0, n, 1) {
                char ch = matrix[i][j];
                if (i == 0 && j == 0) sums[i][j] = (ch == '1' ? 1 : 0);
                if (i > 0 && j > 0) {
                    sums[i][j] = (sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1]) + (ch == '1' ? 1 : 0);
                } else if (i == 0) {
                    sums[i][j] = sums[i][j - 1] + (ch == '1' ? 1 : 0);
                } else if (j == 0) {
                    sums[i][j] = sums[i - 1][j] + (ch == '1' ? 1 : 0);
                }
                // printf("%d ", sums[i][j]);
            }
            // printf("\n");
        }
        int ans = 0;

        FOR (startR, 0, n, 1) {
            FOR (startC, 0, n, 1) {
                FOR (endR, startR, n, 1) {
                    FOR (endC, startC, n, 1) {
                        int subRect = sums[endR][endC];
                        if (!(startR == 0 && startC == 0)) {   
                            if (startR > 0 && startC > 0) {
                                subRect -= (sums[startR - 1][endC] + sums[endR][startC - 1] - sums[startR - 1][startC - 1]);
                            } else if (startR == 0) {
                                subRect -= sums[endR][startC - 1];
                            } else if (startC == 0) {
                                subRect -= sums[startR - 1][endC];
                            }
                        }
                        // if (subRect > ans) {
                            if (subRect == (endR - startR + 1) * (endC - startC + 1)) {
                                ans = max(ans, subRect);
                            }
                        // }
                    }
                }
            }
        }
        fprintf(stdout, "%d\n", ans);
        fprintf(pFile, "%d\n", ans);
        ctr++;
    }
	fclose(pFile);
	return 0;
}
