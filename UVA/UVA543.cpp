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
    bitset<1000000> sieve;
    vi primes;
    for (int i = 2; i < 1000000; i++) {
        if (!sieve.test(i)) {
            primes.PB(i);
            for (int j = i << 1; j < 1000000; j += i) {
                sieve.set(j);
            }
        }
    }
    int n;
    while (SCD(n), n != 0) {
        bool found = false;
        for (int j = 0; j < primes.size() && primes[j] < n && !found; j++) {
            for (int k = j; k < primes.size() && primes[k] + primes[j] <= n && !found; k++) {
                if (primes[j] + primes[k] == n) {
                    fprintf(stdout, "%d = %d + %d\n", n, primes[j], primes[k]);
                    // fprintf(pFile, "%d = %d + %d\n", n, primes[j], primes[k]);
                    found = true;
                }
            }
        }
        if (!found) {
            fprintf(stdout, "Goldbach's conjecture is wrong.\n");
            // fprintf(pFile, "Goldbach's conjecture is wrong.\n");
        }
    }

	fclose(pFile);
	return 0;
}