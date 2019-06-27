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
const int UNVISITED = -1;



int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // vector<ll> primes;
    // ll maxN = 1000000010ll;
    // bitset<1000000010ll> sieve;
    // for (ll i = 2; i <= maxN; i++) {
    //     if (!sieve.test(i)) {
    //         primes.push(i);
    //         for (ll j = i * i; j <= maxN; j *= i) {
    //             sieve.set(i);
    //         }
    //     }
    // }
    int q;
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        ll ans = 0;
        while (n % 2 == 0) {
            n /= 2;
            ans++;
        }
        while (n % 3 == 0) {
            n /= 3;
            ans += 2;
        }
        while (n % 5 == 0) {
            n /= 5;
            ans += 3;
        }
        if (n != 1) cout << -1 << '\n';
        else cout << ans << '\n';
    }
	// freopen("out.txt", "wt", stdout);
	// freopen("in.txt", "r", stdin);
	return 0;
}