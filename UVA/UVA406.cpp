#include<bits/stdc++.h>

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
const int UNVISITED = -1;

vi primes;
bitset<100000> sieve;
int MAX_N = 1000;

int
main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
    primes.PB(1);
    for (int i = 2; i <= MAX_N; i++) {
        if (!sieve.test(i)) {
            primes.PB(i);
            for (int j = i * i; j <= MAX_N; j += i) {
                sieve.set(j);
            }
        }
    }

    int n, c;
    while (cin >> n >> c) {
        cout << n << ' ' << c << ':';
        int pos = (upper_bound(primes.begin(), primes.end(), n) - primes.begin());
        int start = pos / 2;
        int end = start + c - 1;
        if (pos % 2 == 1) start = start - c + 1;
        else start = start - c;
        if (start < 0 || end >= pos) {
            for (int i = 0; i < pos; i++) {
                cout << ' ' << primes[i];
            }
        } else {
            for (int i = start; i <= end; i++) {
                cout << ' ' << primes[i];
            }
        }
        
        cout << "\n\n";
    }
    return 0;
}