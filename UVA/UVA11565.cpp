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
    int n, a, b, c;
    SCD(n);
    while (n--) {
        SCD(a); SCD(b); SCD(c);
        bool found = false;
        for (int x = -100; x <= 100 && !found; x++) {
            for (int y = -100; y <= 100 && !found; y++) {
                if (x * x + y * y <= c) {
                    double sq = sqrt(c - x * x - y * y);
                    if (sq - floor(sq) == 0) {
                        int z = (int)sq;
                        if (x + y + z == a) {
                            if (x * y * z == b) {
                                if (x != y && x != z && y != z) {
                                    fprintf(stdout, "%d %d %d\n", x, y, z);
                                    // fprintf(pFile, "%d %d %d\n", x, y, z);
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (!found) {
            fprintf(stdout, "No solution.\n");
            // fprintf(pFile, "No solution.\n");
        }
    }
	fclose(pFile);
	return 0;
}