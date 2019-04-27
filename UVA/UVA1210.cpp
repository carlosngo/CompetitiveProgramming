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
    bitset<10001> sieve;
    vi primes;
    for (int i = 2; i <= 10000; i++) {
        if (!sieve.test(i)) {
            primes.PB(i);
            for (int j = i << 1; j <= 10000; j += i) 
                sieve.set(j);
        }
    }

    // FOR (i, 0, primes.size(), 1) printf("%d\n", primes[i]);
    int ans[10001];
    for (int i = 2; i < 10001; i++) {
    // int i = 17;
        int ctr = 0;
        // printf("Trying %d\n", i);
        for (int j = 0; j < primes.size() && primes[j] < i; j++) {
            int sum = 0;
            for (int k = j; k < primes.size() && sum < i; k++) {
                // printf("Sum = %d\n", sum);
                sum += primes[k];
            }
            if (sum == i) ctr++;
        }
        // printf("\n");
        if (!sieve.test(i)) ans[i] = ctr + 1;
        else ans[i] = ctr;
    }
    int num;
    while (SCD(num), num != 0) {
        fprintf(stdout, "%d\n", ans[num]);
        // fprintf(pFile, "%d\n", ans[num]);
    }
	fclose(pFile);
	return 0;
}