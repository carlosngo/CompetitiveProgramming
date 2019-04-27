#include <bits/stdc++.h>

using namespace std;

// READING INPUT
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCintD(t) scanf("%intd",&t)
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
#define aint(cont) cont.begin(), cont.end()
#define raint(cont) cont.end(), cont.begin()
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
const int MAX_N = (1 << 16);


int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    vi primes;
    bitset<MAX_N> sieve;
    for (int i = 2; i < MAX_N; i++) {
        if (!sieve.test(i)) {
            primes.PB(i);
            if (i <= (int) sqrt(MAX_N)) {
                for (int j = i * i; j < MAX_N; j += i) {
                    sieve.set(j);
                }
            }
        }
    }
    int len = primes.size();
    int num;
    while (SCD(num), num != 0) {
        vector<int> pf;
        int temp = num;
        if (num < 0) {
            pf.PB(-1);
            temp *= -1;
        } 
        for (int i = 0; i < len; i++) {
            while (temp % primes[i] == 0) {
                pf.PB(primes[i]);
                temp /= primes[i];
            }
        }
        if (temp != 1) {
            pf.PB(temp);
        }
        printf("%d = ", num);
        // fprintf(pFile, "%d = ", num);
        for (int i = 0; i < pf.size(); i++) {
            if (i > 0) {
                printf(" x ");
                // fprintf(pFile, " x ");
            }
            printf("%d", pf[i]);
            // fprintf(pFile, "%d", pf[i]);
            if (pf.size() == 1 && pf[0] == -1) {
                printf(" x ");
                // fprintf(pFile, " x ");
            }
        }
        printf("\n");
        // fprintf(pFile, "\n");
    }

	fclose(pFile);
	return 0;
}