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
const int MAX_N = 100000;
class Sieve {
    public:
        bitset<MAX_N> sieve;
};

vi primes;
Sieve * s;

bool isPrime(int n) {
    if (n < MAX_N) return !(s->sieve).test(n);
    for (int i = 0; i < primes.size() && primes[i] <= sqrt(n); i++) {
        if (n % primes[i] == 0) return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    s = new Sieve;
    
    for (int i = 2; i < MAX_N; i++) {
        if (!(s->sieve).test(i)) {
            primes.PB(i);
            for (int j = i << 1; j < MAX_N; j += i) {
                (s->sieve).set(j);
            }
        }
    }
    (s->sieve).set(1);
    // FOR (i, 0, primes.size(), 1) printf("%d\n", primes[i]);
    int l, u;
    while (fscanf(stdin, "%d %d", &l, &u) == 2) {
        int mini = INT_MAX;
        ii minPair;
        int maxi = INT_MIN;
        ii maxPair;
        int prev = -1;
        bool found = false;
        for (ll i = l; i <= u; i++) {
            // printf("Hi");
            if (isPrime(i)) {
                if (prev == -1) prev = i;
                else {
                    // printf("Current Prime: %d\nPrev: %d", i, prev);
                    int diff = i - prev;
                    if (diff < mini) {
                        mini = diff;
                        minPair = ii(prev, i);
                    }
                    if (diff > maxi) {
                        maxi = diff;
                        maxPair = ii(prev, i);
                    }
                    found = true;
                    prev = i;
                }
            }
        }
        if (found) {
            fprintf(stdout, "%d,%d are closest, %d,%d are most distant.\n", minPair.first, minPair.second, maxPair.first, maxPair.second);
            // fprintf(pFile, "%d,%d are closest, %d,%d are most distant.\n", minPair.first, minPair.second, maxPair.first, maxPair.second);
        } else {
            fprintf(stdout, "There are no adjacent primes.\n");
            // fprintf(pFile, "There are no adjacent primes.\n");
        }
    }
	fclose(pFile);
	return 0;
}