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

class Sieve {
    public:
        bitset<20000000> sieve;
};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	FILE *pFile = fopen("out.txt","w");
    Sieve * sieve = new Sieve;
    vi primes;
    for (int i = 2; i < 20000000; i++) {
        if (!(sieve->sieve).test(i)) {
            primes.PB(i);
            for (int j = i; j < 20000000; j += i) {
                (sieve->sieve).set(j);
            }
        }
    }
    vii ans;
    for (int i = 0; i < primes.size() - 1; i++) {
        if (primes[i + 1] - primes[i] == 2) {
            ans.PB(ii(primes[i], primes[i + 1]));
        }
    }

    int s;
    while (SCD(s) == 1) {
        fprintf(stdout, "(%d, %d)\n", ans[s - 1].first, ans[s - 1].second);
        fprintf(pFile, "(%d, %d)\n", ans[s - 1].first, ans[s - 1].second);
    }
	fclose(pFile);
	return 0;
}