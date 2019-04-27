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
    int t, r, h;
    while (SCD(t) == 1) {
        SCD(r); SCD(h);
        int tr[t][r + 1];
        int rh[r][h + 1];
        int ht[h][t + 1];
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < r + 1; j++) {
                SCD(tr[i][j]);
            }
        }   
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < h + 1; j++) {
                SCD(rh[i][j]);
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < t + 1; j++) {
                SCD(ht[i][j]);
            }
        }
        iii trh;
        int ans = INT_MAX;
        for (int tRow = 0; tRow < t; tRow++) {
            for (int tCol = 1; tCol < r + 1; tCol++) {
                int total = 0;
                if (tr[tRow][tCol] == 0) {
                    total += tr[tRow][0];
                    int rRow = tCol - 1;
                    for (int rCol = 1; rCol < h + 1; rCol++) {
                        if (rh[rRow][rCol] == 0) {
                            total += rh[rRow][0];
                            int hRow = rCol - 1;
                            if (ht[hRow][tRow + 1] == 0) {
                                total += ht[hRow][0];
                                if (total < ans) {
                                    trh = iii(tRow, ii(rRow, hRow));
                                    ans = total;
                                }
                                total -= ht[hRow][0];
                            }
                            total -= rh[rRow][0];
                        }
                    }
                }
            }
        }
        if (ans == INT_MAX) {
            fprintf(stdout, "Don't get married!\n");
            fprintf(pFile, "Don't get married!\n");
        } else {
            fprintf(stdout, "%d %d %d:%d\n", trh.first, trh.second.first, trh.second.second, ans);
            fprintf(pFile, "%d %d %d:%d\n", trh.first, trh.second.first, trh.second.second, ans);
        }
    }
	fclose(pFile);
	return 0;
}