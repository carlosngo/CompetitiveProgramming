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
    int n, b, sg, sb;
    SCD(n);
    int ctr = 0;
    while (n--) {
        if (ctr > 0) {
            fprintf(stdout, "\n");
            // fprintf(pFile, "\n");
        }
        SCD(b); SCD(sg); SCD(sb);
        priority_queue<int, vi, less<int> > gArmy, bArmy;
        while (sg--) {
            int pwr; SCD(pwr);
            gArmy.push(pwr);
        }
        while (sb--) {
            int pwr; SCD(pwr);
            bArmy.push(pwr);
        }
        while (!(gArmy.empty() || bArmy.empty())) {
            vi bSurv, gSurv;
            for (int i = 0; i < b && (!gArmy.empty() && !bArmy.empty()); i++) {
                int gFighter = gArmy.top(); gArmy.pop();
                int bFighter = bArmy.top(); bArmy.pop();
                // printf("G %d will fight against B %d\n", gFighter, bFighter);
                if (gFighter > bFighter) gSurv.PB(gFighter - bFighter);
                else if (bFighter > gFighter) bSurv.PB(bFighter - gFighter);
            }
            FOR (i, 0, bSurv.size(), 1) bArmy.push(bSurv[i]);
            FOR (i, 0, gSurv.size(), 1) gArmy.push(gSurv[i]);
        }
        if (gArmy.empty() && bArmy.empty()) {
            fprintf(stdout, "green and blue died\n");
            // fprintf(pFile, "green and blue died\n");
        } else if (gArmy.empty()) {
            fprintf(stdout, "blue wins\n");
            // fprintf(pFile, "blue wins\n");
            while (!bArmy.empty()) {
                fprintf(stdout, "%d\n", bArmy.top());
                // fprintf(pFile, "%d\n", bArmy.top());
                bArmy.pop();
            }
        } else if (bArmy.empty()) {
            fprintf(stdout, "green wins\n");
            // fprintf(pFile, "green wins\n");
            while (!gArmy.empty()) {
                fprintf(stdout, "%d\n", gArmy.top());
                // fprintf(pFile, "%d\n", gArmy.top());
                gArmy.pop();
            }
        } 
        ctr++;
    }
	fclose(pFile);
	return 0;
}