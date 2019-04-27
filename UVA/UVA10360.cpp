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

class City {
    public:
        int grid[1075][1075];
        int sums[1075][1075];
};

int main() {
    // printf("Hi");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int t, d, n;
    SCD(t);
    while(t--) {
        SCD(d);
        SCD(n);
        City *c = new City;
        memset(c->grid, 0, sizeof (c->grid));
        memset(c->sums, 0, sizeof (c->sums));
        FOR (i, 0, n, 1) {
            int row, col, num;
            SCD(row); SCD(col); SCD(num);
            c->grid[row + 50][col + 50] = num;
        }
        for (int i = 0; i < 1075; i++) {
            for (int j = 0; j < 1075; j++) {
                if (i == 0 && j == 0) {
                    c->sums[i][j] = c->grid[i][j];
                } else if (i > 0 && j > 0) {
                    c->sums[i][j] = c->sums[i - 1][j] + c->sums[i][j - 1] - c->sums[i - 1][j - 1] + c->grid[i][j];
                } else if (i == 0) {
                    c->sums[i][j] = c->sums[i][j - 1] + c->grid[i][j];
                } else if (j == 0) {
                    c->sums[i][j] = c->sums[i - 1][j] + c->grid[i][j];
                }
            }
        }
        int ansR;
        int ansC;
        int ans = INT_MIN;

        for (int startR = 0; startR < 1075; startR++) {
            for (int startC = 0; startC < 1075; startC++) {
                int endR = startR + 2 * d;
                int endC = startC + 2 * d;
                if (startR + d >= 50 && startC + d >= 50 && endR < 1075 && endC < 1075) {
                    int sum = c->sums[endR][endC] - (c->sums[startR - 1][endC] + c->sums[endR][startC - 1] - c->sums[startR - 1][startC - 1]);
                    if (sum > ans) {
                        ansR = startR - 50 + d;
                        ansC = startC - 50 + d;
                        ans = sum;
                    }
                }
            }
        }
        
        fprintf(stdout, "%d %d %d\n", ansR, ansC, ans);
        fprintf(pFile, "%d %d %d\n", ansR, ansC, ans);
    }
	fclose(pFile);
	return 0;
}