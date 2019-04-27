#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
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

bool isAdjacent(int i, int j) {
    int x = i ^ j;
    return (x & (-x)) == x;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    int n, m;

    while (scanf("%d %d", &n, &m), !(n == 0 && m == 0)) {
        bitset<2000000> cal;
        bool conflict = false;
        FOR(i, 0, n, 1) {
            int s, e;
            SCD(s); SCD(e);
            if (!conflict) {
                FOR (j, s, e, 1) {
                    
                    if (cal.test(j))
                        conflict = true;
                    
                    cal.set(j);
                }
            }
        }

        FOR (i, 0, m, 1) {
            int s, e, interval;
            SCD(s); SCD(e); SCD(interval);
            if (!conflict) {
                while (s < 1000000 && e < 1000000) {
                    FOR (j, s, e, 1) {
                        // if (j > s && j < e) {
                            if (cal.test(j))
                                conflict = true;
                        // }
                        cal.set(j);
                    }
                    s += interval;
                    e += interval;
                    if (e >= 1000000)
                        e = 999999;
                }

            }
        }
        if (conflict) {
            printf("CONFLICT\n");
            fprintf(pFile, "CONFLICT\n");
        } else {
            printf("NO CONFLICT\n");
            fprintf(pFile, "NO CONFLICT\n");
        }

    }
	fclose(pFile);
	return 0;
}