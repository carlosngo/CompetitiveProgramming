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

int n, m, c, k;
int garms[20][20];
int numberOfModels[20];
int memo[201][20];
// int ans;

int backtrack(int money, int garm) {
    if (money >= 0) {
        if (garm == c) {
            return m - money;
        } else {
            if (memo[money][garm] != INT_MIN) return memo[money][garm];
            int ans = INT_MIN; 
            for (int i = 0; i < numberOfModels[garm]; i++) {
                // printf("Checking garment #%d model %d with price %d\n", garm, i, garms[garm][i]);
                ans = max(ans, backtrack(money - garms[garm][i], garm + 1));
                // backtrack(money - garms[garm][i], garm + 1);
            }
            // return m - ans;
            memo[money][garm] = ans;
            return ans;
        }
    } else {
        return INT_MIN;
    }
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n;
    SCD(n);
    while (n--) {
        // ans = INT_MIN;
        FOR (i, 0, 201, 1) {
            FOR (j, 0, 20, 1) {
                memo[i][j] = INT_MIN;
            }
        }
        SCD(m);
        SCD(c);
        FOR (i, 0, c, 1) {
            SCD(k);
            numberOfModels[i] = k;
            FOR (j, 0, k, 1) {
                SCD(garms[i][j]);
            }
        }
        // backtrack(m, 0);
        int score = backtrack(m, 0);
        if (score < 0) {
            fprintf(stdout, "no solution\n");
            // fprintf(pFile, "no solution\n");
        } else {
            fprintf(stdout, "%d\n", score);
            // fprintf(pFile, "%d\n", score);
        }
        
    }
	fclose(pFile);
	return 0;
}