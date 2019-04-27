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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

// Offset Arrays
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

bool isAdj () {

}

double calcSpread(int d1, int d2) {
    return d2 * 1.0 / d1;   
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int front, rear, f[100], r[100];
    
    while (SCD(front), front != 0) {
        vector<double> dRatios;
        SCD(rear);
        FOR (i, 0, front, 1) SCD(f[i]);
        FOR (i, 0, rear, 1) {
            SCD(r[i]);
            FOR (j, 0, front, 1) {
                dRatios.PB(r[i] * 1.0 / f[j]);
            }
        }
        sort(dRatios.begin(), dRatios.end());
        double ans = DBL_MIN;
        for (int i = 0; i < dRatios.size() - 1; i++) {
            // printf("")
            // if (dRatios[i + 1] > dRatios[i])
                ans = max(ans, dRatios[i + 1] / dRatios[i]);
        }
        fprintf(stdout, "%.2lf\n", ans);
        fprintf(pFile, "%.2lf\n", ans);
    }
	fclose(pFile);
	return 0;
}